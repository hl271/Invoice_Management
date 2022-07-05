#pragma once
#include "Invoice.h"
#include "uuid.h"
class Incoming_Domestic : public Invoice
{
public:
	Incoming_Domestic(string id, time_t timestamp) : Invoice(id, timestamp) {
		tax = 0.10;
	}

	bool isDomestic();
	bool isIncoming();
	string getTypeAsStr();
};

