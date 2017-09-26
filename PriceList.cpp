#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;
//default constructor
PriceList::PriceList() {
	this->head = nullptr;
	this->temp = nullptr;
	size = 0;
	max = 1000000;
};
//destructor
PriceList::~PriceList()
{
	this->head = nullptr;
	this->temp = nullptr;
	delete head;
	delete temp;
};
//reading from txt file
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

