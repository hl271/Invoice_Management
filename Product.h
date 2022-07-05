#pragma once
#include <string>
using namespace std;
#include "uuid.h"
class Product {
    string name_of_product;
    double unit_price = 0;
    string id;
public:
    Product(){}
    Product(string name, double price): name_of_product(name), unit_price(price) {}
    //Accessing
    string getName();
    double getUnitPrice();
    string getId();
    //Modify
    void setName(string name);
    void setUnitPrice(double price);
    void deleteProduct();
    //Searching
    string searchProductByName(string name);
    //helper
    bool CheckForDuplicateName();

};
