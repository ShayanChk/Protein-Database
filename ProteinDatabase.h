
//Name: Shayan Chabook
//student ID: 159844208
//email:schabook@myseneca.ca
//5/28/2022
#ifndef SDDS_PROTIENDATABASE_H
#define SDDS_PROTIENDATABASE_H
#include <string>

using namespace std;
namespace sdds {

	class ProteinDatabase
	{
		string* protienName{};
		size_t proteinNumber{};

	public:

		ProteinDatabase();
		ProteinDatabase(const ProteinDatabase& other);
		ProteinDatabase(string fileName);
		ProteinDatabase& operator=(const ProteinDatabase& f);
		~ProteinDatabase();

		ProteinDatabase(ProteinDatabase&& other); //move constructor 
		ProteinDatabase& operator=(ProteinDatabase&& other); //move assignment 


		size_t size() const;
		std::string operator[](size_t number);

	};


}
#endif