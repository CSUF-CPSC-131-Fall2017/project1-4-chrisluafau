#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	// TO BE COMPLETED
	this->itemName = itemName;
	this->itemCode = code;
	this->itemPrice = price;
	this->itemTaxable = taxable;
}

PriceListItem::PriceListItem() {
	// TO BE COMPLETED
	this->itemName = "";
	this->itemCode = "";
	this->itemPrice = 0.0;
	this->itemTaxable = false;
}

string PriceListItem::getItemName() {
	// TO BE COMPLETED
	return itemName;
}

string PriceListItem::getCode() {
	// TO BE COMPLETED
	return itemCode;
}

double PriceListItem::getPrice() {
	// TO BE COMPLETED
	return itemPrice;
}

bool PriceListItem::isTaxable() {
	// TO BE COMPLETED
	return itemTaxable;
}

