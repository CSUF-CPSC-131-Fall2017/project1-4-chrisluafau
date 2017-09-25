#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

PriceList::PriceList() {};
// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);
	size = 0;
	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
	// TO BE COMPLETED
	PriceListItem* tmp = head;
	
	if (tmp != NULL)
	{
		if (tmp->getCode() == code)
		{

			return true;
		}
		while (tmp->link != NULL)
		{
			if (tmp->getCode() == code)
			{

				return true;
			}
			tmp = tmp->link;
		}
	}

	return false;
}

// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	// TO BE COMPLETED
	PriceListItem *temp = head;
	if (temp != NULL)
	{
		if (temp->getCode() == code)
		{
			return *temp;
		}
		while (temp->link != NULL)
		{
			if (temp->getCode() == code)
			{
				return *temp;
			}
			temp = temp->link;
		}
	}
	else
		return *temp;
}

// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	// TO BE COMPLETED
	if (size >= max)
		return;
	PriceListItem* newEntry = new PriceListItem(itemName, code, price, taxable);
	newEntry->link = NULL;
	if (head == NULL)
	{
		head = newEntry;
		temp = newEntry;
	}
	else
	{
		temp->link = newEntry;
		temp = newEntry;
	}
	size++;
}
PriceList& PriceList::operator=(const PriceList& item)
{
	this->head = item.head;
	this->temp = item.temp;
	return *this;
}
PriceList::PriceList(const PriceList &item)
{
	this->head = item.head;
	this->temp = item.temp;
}

