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
	
	//PriceList* temp = new PriceList();
	//temp->head = head;
	if (tmp != NULL)
	{
		//compare the code with first item code, if found return true
		if (tmp->getCode() == code)
		{
			//code found
			return true;
		}
		//check if it has more items in there
		while (tmp->link != NULL)
		{
			//compare the code with each item code, if found return true
			if (tmp->getCode() == code)
			{
				//item found
				return true;
			}
			//go to the next item
			tmp = tmp->link;
		}
	}
	//item with this code not found, so return false
	//item not valid
	return false;
}

// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	// TO BE COMPLETED
	PriceListItem *temp = head;
	//check if there is item in the list
	if (temp != NULL)
	{
		//compare the code with the first item
		if (temp->getCode() == code)
		{
			//item found, return item
			return *temp;
		}
		//check if there are more items, if not found previously
		while (temp->link != NULL)
		{
			//compare code with each item's code
			if (temp->getCode() == code)
			{
				//code matches, return item
				return *temp;
			}
			//go to the next item
			temp = temp->link;
		}
	}
	else
		return *temp;
	//item not found in the item list
	//return nothing
	//return nullptr;
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

