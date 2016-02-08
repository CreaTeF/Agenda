#ifndef COMPANY_H
#define COMPANY_H
#include <string.h>

class Company 
{

	private:
		std::string companyName;
		std::string companyCity;
		std::string companyWeb;

	public:
		//set and get
		void setCompanyName(std::string companyName_) { companyName = companyName_; }
		void setCompanyCity(std::string companyCity_) { companyCity = companyCity_; }
		void setcompanyWeb(char* companyWeb_) { companyWeb = companyWeb_; }
		std::string getCompanyName() { return companyName; }
		std::string getCompanyCity() { return companyCity; }
		std::string getAddress() { return companyWeb; }

};
#endif