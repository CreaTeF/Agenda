#include <iostream>
#include <string>
#include <direct.h>
#include <Windows.h>
#include <vector>
#include <fstream>
#include "./Headers/Person.h"
#include "./Headers/Company.h"
#include "./Headers/Logs.h"


std::vector<std::string> GetFilesInDirectoryWithExt(std::string folder, std::string extension)
{
	std::vector<std::string> names;
	char search_path[200];
	sprintf_s(search_path, "%s/*.*", folder.c_str());
	WIN32_FIND_DATAA fd;
	HANDLE hFind = ::FindFirstFileA(search_path, &fd);

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				if (!strcmp(&fd.cFileName[strlen(fd.cFileName) - extension.size()], extension.c_str()))
					names.push_back(fd.cFileName);
			}
		} while (::FindNextFileA(hFind, &fd));
		::FindClose(hFind);
	}

	return names;
}

void Logs::addLog()
{
	Person person;

	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	person.setName(name);

	std::cout << "Enter your last name: ";
	std::string lastName;
	std::cin >> lastName;
	person.setLastName(lastName);

	std::cout << "Enter your address: ";
	std::string address;
	std::cin >> address;
	person.setAddress(address);

	std::cout << "Enter your phone: ";
	int phone;
	std::cin >> phone;
	person.setPhone(phone);
	
	//write a txt file with the person name and save his/her information.
	_mkdir("./logs");
	std::ofstream writeLog;
	std::string txtPatch = ".agenda";
	writeLog.open("./logs\\" + name + txtPatch);

	writeLog << "Name: " << name << "\n" << "Last name: " << lastName << "\n" << "Address: " << address << "\n" << "Phone: " << phone;
	writeLog.close();
}

void Logs::viewLog()
{
	std::string name, lastName, address, line, fileName;
	int phone;
	int item = 0;
	std::ifstream readLog;
	std::string txtPatch = ".agenda";
	std::string folderPath = "./logs";

	std::vector<std::string> names = GetFilesInDirectoryWithExt(folderPath, txtPatch);
	std::cout << "Logs:" << std::endl;
	std::vector<std::string> logs;
	
	//remove the file extension.
	for (int i = 0; i < names.size(); i++)
	{
		fileName = names[i];
		
		if (fileName.substr(fileName.find_last_of(".") + 1) == "agenda")
		{
			int lastindex = fileName.find_last_of(".");
			std::string rawname = fileName.substr(0, lastindex);
			logs.push_back(rawname);
		}

	}
	
	for (std::vector<std::string>::iterator it = logs.begin(); it != logs.end(); ++it)
	{
		std::cout << "[" << item << "]" << *it << std::endl;
		item++;
	}

	std::cout << "Which one would you like to see?" << std::endl;
	int option;
	std::cin >> option;

	for (int i = 0; i < logs.size(); ++i)
	{
		if (option == i)
		{
			readLog.open("./logs\\" + logs[i] + txtPatch);
			if (readLog.is_open())
			{
				while (std::getline(readLog, line))
				{
					std::cout << line << '\n';
				}
				readLog.close();
			}
			else
				std::cout << "The files doesn't exist!" << std::endl;
		}
	}
	
}

int main()
{
	std::cout << " [1]View logs \n [2]Add logs \n [3]Modify logs \n [4]Delete log" << std::endl;
	int option;
	std::cin >> option;

	switch (option)
	{
		case 1:
			Logs::viewLog();
			break;
		case 2:	
			Logs::addLog();
			break;
		default:
			std::cout << "Enter a valid option." << std::endl;
	}
	system("PAUSE");
	return 0;
}