#pragma once
#include "Invoice.h"
class Incoming_Foreign : public Invoice
{
public:
	Incoming_Foreign(string id, time_t timestamp) : Invoice(id, timestamp) {
		tax = 0.15;
	}
	bool isDomestic();
	bool isIncoming();
	string getTypeAsStr();
};

