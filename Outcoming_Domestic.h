#pragma once
#include "Invoice.h"
class Outcoming_Domestic : public Invoice
{
public:
	Outcoming_Domestic(string id, time_t timestamp) : Invoice(id, timestamp) {
		tax = 0.10;
	}
	bool isDomestic();
	bool isIncoming();
	string getTypeAsStr();
};

