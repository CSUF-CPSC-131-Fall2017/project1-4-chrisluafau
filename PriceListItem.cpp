#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	this->itemName = itemName;
	this->itemCode = code;
	this->itemPrice = price;
	this->itemTaxable = taxable;
}

PriceListItem::PriceListItem() {
	this->itemName = "";
	this->itemCode = "";
	this->itemPrice = 0.0;
	this->itemTaxable = false;
	this->link = nullptr;
}
PriceListItem::~PriceListItem()
{
	this->link = nullptr;
	delete link;
}

string PriceListItem::getItemName() {
	return itemName;
}

string PriceListItem::getCode() {
	return itemCode;
}

double PriceListItem::getPrice() {
	return itemPrice;
}

bool PriceListItem::isTaxable() {
	return itemTaxable;
}

