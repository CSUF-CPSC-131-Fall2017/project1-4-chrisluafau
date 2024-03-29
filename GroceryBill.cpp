#include "GroceryBill.h"
#include <iostream>
#include <fstream>

using namespace std;
//default constructor
GroceryBill::GroceryBill()
{
	this->plist = nullptr;
	tax = 0.0;
	total = 0;
	this->head = nullptr;
	this->temp = nullptr;
}
//destructor
GroceryBill::~GroceryBill()
{
	this->plist = nullptr;
	this->head = nullptr;
	this->temp = nullptr;
	tax = 0;
	total = 0;
	delete plist;
	delete head;
	delete temp;
}
//construct w/ const and double
GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	head = priceList->head;
	temp = priceList->temp;
	tax = taxRate;
	plist = new PriceList();
	total = 0.0;
}
//scan
void GroceryBill::scanItem(string scanCode, double quantity) {
	plist->head = head;
	if (plist->isValid(scanCode) == false)
		throw runtime_error("Item not found");
	PriceListItem temp = plist->getItem(scanCode);

	gbill = temp;
	gbill.itemPrice *= quantity;
	if (gbill.itemTaxable == true)
	{
		total += gbill.getPrice()*(1 + (tax / 100));
	}
	else
	{
		total += gbill.getPrice();
	}
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// To be completed
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string code;
		double quantity;
		while (myfile >> code >> quantity) {
			scanItem(code, quantity);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	PriceListItem* n = head;
	if (n->link == NULL)
	{
		cout << n->itemName << " " << n->itemPrice << " ";
		if (n->itemTaxable == true)
			cout << "T" << endl;
	}
	while (n->link != NULL)
	{
		cout << n->itemName << " " << n->itemPrice << " ";
		if (n->itemTaxable == true)
			cout << "T";
		cout << endl;
		n = n->link;
	}
}

