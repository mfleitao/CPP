// ************************************************************
// Final Project Milestone 3
// Date: 16/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 3
// ************************************************************
#ifndef AID_GOOD_H_
#define AID_GOOD_H_

#include <iostream>
#include "Error.h"

namespace aid {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 1.13;

	class Good {

		char typeOfGood;
		char goodSKU[max_sku_length + 1];
		char goodUnit[max_unit_length + 1];
		char* goodName;
		int currentQuantity;
		int	neededQuantity;
		double price;
		bool taxableStatus;
		Error* error;

	protected:

		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;

	public:

		explicit Good(char type);
		Good(const char* sku, const char* name, const char* unit, int qty = 0,
			bool isTaxed = true, double price = 0.0, int qtyNeeded = 0);
		~Good();

		Good(const Good& good);
		Good& operator=(const Good& good);

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Good&) const;
		int operator+=(int);
		bool operator==(const char*) const;
	};

	std::ostream& operator<<(std::ostream&, const Good&);
	std::istream& operator>>(std::istream&, Good&);
	double operator+=(double&, const Good&);

}

#endif 