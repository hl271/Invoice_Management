#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <unordered_map>
#include "Product.h"
#include "uuid.h"

using namespace std;
enum InvoiceType {
    INCOMING_DOMESTIC, INCOMING_FOREIGN, OUTCOMING_DOMESTIC, OUTCOMING_FOREIGN
};
struct ProductWithQuantity {
    Product product;
    int quantiy;
};
class Invoice {
protected:
    string id;
    //string type="";
    unordered_map<string, struct ProductWithQuantity> list_of_products;
    //double Total = 0;
    float tax = 0;
    time_t created_at;
public:
    Invoice(string sid, std::time_t time) :id(sid), created_at(time){}
    //Accessing
    string getId();
    virtual string getTypeAsStr()=0;
    float getTax();
    virtual bool isIncoming()=0;
    virtual bool isDomestic()=0;
    std::time_t getTimestamp();
    int getNumberOfProducts();
    int getAllProductIds();
    bool checkIfProductExists(string name);
    //Modify
    void setId(string id);
    void setTime(time_t time);
    void addProduct(string id, Product& product, int num);
    void removeProduct(string id);
    void setType(InvoiceType type);
    void deleteInvoice();
    void setTotal();
    //Searching
    //Helper
    InvoiceType convertStrToType(string type_as_str);
    double calculateTotal();
};
