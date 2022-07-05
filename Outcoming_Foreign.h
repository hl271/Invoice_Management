#pragma once
#include "Invoice.h"
class Outcoming_Foreign : public Invoice
{
public:
	Outcoming_Foreign(string id, time_t timestamp) : Invoice(id, timestamp) {
		tax = 0.15;
	}
	bool isDomestic();
	bool isIncoming();
	string getTypeAsStr();
};

