#pragma once
#include <string>

using namespace std;

class PriceListItem {
public:
	PriceListItem();
	~PriceListItem();
	PriceListItem(const string &itemName, const string &code, double price, bool taxable);
	string getItemName();
	string getCode();
	double getPrice();
	bool isTaxable();
	friend class PriceList;
	friend class GroceryBill;
private:
	// any private member variables and methods go here
	// TO BE COMPLETED
	string itemName;
	string itemCode;
	double itemPrice;
	bool itemTaxable;
	PriceListItem* link;
};
