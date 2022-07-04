#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <time.h>
#include "Invoice.h"
#include "Product.h"
#include "Incoming_Domestic.h"
#include "Incoming_Foreign.h"
#include "Outcoming_Domestic.h"
#include "Outcoming_Foreign.h"
class App
{
	unordered_map<string, Invoice*> DB_INVOICE;
	//unordered_map<string, Invoice*> DB_INVOICE_IF;
	//unordered_map<string, Invoice*> DB_INVOICE_OD;
	//unordered_map<string, Invoice*> DB_INVOICE_OF;
	unordered_map<string, Product> DB_PRODUCT;
	vector<string> IDS_INVOICE;
	vector<string> IDS_PRODUCT;
public:
	App();
	// Invoices
	void addNewInvoiceToDb(string type_as_str);
	// strtime has format %Y-%m-%d %H:%M:%S
	void addExistingInvoiceToDb(string id, string time);
	void addNewProductToDb(string name, double price);
	void addExistingProductToDb(string id, string name, double price);

};

