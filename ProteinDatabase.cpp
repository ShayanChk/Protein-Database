//Name: Shayan Chabook
//student ID: 159844208
//email:schabook@myseneca.ca
//5/28/2022
#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <fstream>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds {

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] protienName;
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& f)
	{
		if (&f != this)
		{
			delete[] protienName;


			//protienName = f.protienName;
			proteinNumber = f.proteinNumber;

			if (f.protienName != nullptr)
			{
				protienName = new string[f.proteinNumber];

				for (size_t i = 0; i < proteinNumber; i++)
				{
					protienName[i] = f.protienName[i];
				}
			}
		}

		return *this;
	}

	ProteinDatabase& ProteinDatabase::operator=( ProteinDatabase&& other)
	{
		if (&other != this)
		{
			delete[] protienName;
			

			protienName = other.protienName;
			other.protienName = nullptr;

			proteinNumber = other.proteinNumber;
			other.proteinNumber = 0;
		}

		return *this;
	}


	ProteinDatabase::ProteinDatabase(ProteinDatabase&& other)
	{
		*this = std::move(other);
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& other)
	{
		*this = other;
		proteinNumber = other.proteinNumber;
	}


	ProteinDatabase::ProteinDatabase()
	{
		protienName = nullptr;
		proteinNumber = 0;
	}

	
	ProteinDatabase::ProteinDatabase(string filename)
	{
		ifstream file(filename);
		string line;
		unsigned n_sequence = 0;
		while (getline(file, line))
		{
			if (line[0] == '>')
				n_sequence++;
		}
		file.close();
		file.open(filename);
		this->proteinNumber = n_sequence;
		this->protienName = new string[n_sequence];

		int i = -1;
		while (getline(file, line))
		{
			if (line[0] == '>')
				i++;
			else
				protienName[i] += line;
		}
		file.close();

	}

	size_t ProteinDatabase::size() const
	{
		return proteinNumber;
	}

	std::string ProteinDatabase::operator[](size_t number)
	{
		if (number >= 0 && number < proteinNumber)
		{
			return protienName[number];
		}

		return "";
	}

}