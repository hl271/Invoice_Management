#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
#include "Invoice.h"
#include "Product.h"
#include "Incoming_Domestic.h"
#include "Incoming_Foreign.h"
#include "Outcoming_Domestic.h"
#include "Outcoming_Foreign.h"
struct CombinedId {
	string id;
	time_t timestamp;
};
class App
{
public:
	unordered_map<string, Invoice*> DB_INVOICE;
	//unordered_map<string, Invoice*> DB_INVOICE_IF;
	//unordered_map<string, Invoice*> DB_INVOICE_OD;
	//unordered_map<string, Invoice*> DB_INVOICE_OF;
	unordered_map<string, Product> DB_PRODUCT;
	vector<string> IDS_INVOICE;
	vector<string> IDS_PRODUCT;
	App();
	//Product
	void addNewProductToDb(string name, double price);
	void addExistingProductToDb(string id, string name, double price);

	// Invoices
	void addNewInvoiceToDb(string type_as_str);
	// strtime has format %Y-%m-%d %H:%M:%S
	void addExistingInvoiceToDb(string id, string time);
	bool addProductToInvoice(string inv_id, string product_id, int quantity);
	bool editProductInInvoice(string inv_id, string product_id, int quantity);
	bool removeProductFromInvoice(string inv_id, string product_id);
	bool removeInvoice(string inv_id);

	//Search
	string searchByInvoiceCode(string inv_id);
	vector<string> searchByInvoiceType(string type);
	vector<string> searchByInvoiceItems(string name_of_product);
	//time has format %Y-%m-%d
	vector<string> searchByTimeRange(string start_day, string end_day);

	//Calulate profit by time range
	double calculateProfitByTimeRange(string start_day, string end_day);

	//Helper methods
	time_t convertStringTimeFormat1(string strtime);
	time_t convertStringTimeFormat2(string strtime);
	void printAllInvoices();


};

