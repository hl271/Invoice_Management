#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Invoice.h"
#include "Product.h"
class App
{
	unordered_map<string, Invoice> db_invoice;
	unordered_map<string, Product> db_product;
	vector<string> ids_invoice;
	vector<string> ids_product;
public:
	App() {}
	

};

