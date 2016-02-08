#ifndef PERSON_H
#define PERSON_H
#include <string.h>

class Person
{
	
	private:
		 std::string name;
		 std::string lastName;
		 std::string address;
		 int phone;
	
	public:
	//set and get
		void setName(std::string name_) { name = name_; }
		void setLastName(std::string lastName_) { lastName = lastName_; }
		void setAddress(std::string address_) { address = address_; }
		void setPhone(int phone_) { phone = phone_; }
		std::string getName() { return name; }
		std::string getlastName() { return lastName; }
		std::string getAdress() { return address; }
		int getPhone() { return phone; }

		
};

#endif