#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <unordered_map>
#include "Product.h"
#include "uuid.h"

using namespace std;
enum InvoiceType {
    INCOMING_DOMESTIC, INCOMING_FOREIGN, OUTCOMING_DOMESTIC, OUTCOMING_FOREIGN
};
class Invoice {
protected:
    string id;
    //string type="";
    unordered_map<string, int> list_of_products;
    double Total = 0;
    float tax = 0;
    time_t created_at;
public:
    Invoice(string sid, std::time_t time) :id(sid), created_at(time){}
    //Accessing
    string getId();
    string getTypeAsStr();
    double getProfit();
    std::time_t getTimestamp();
    int getNumberOfProducts();
    int getAllProductIds();
    //Modify
    void setId(string id);
    void setTime(time_t time);
    void addProduct(string id, int num);
    void removeProduct(string id);
    void setType(InvoiceType type);
    void deleteInvoice();
    void setTotal();
    //Searching
    void SearchProductById(string id);
    string SearchProductByName(string name);
    //Helper
    InvoiceType convertStrToType(string type_as_str);
    void calculateTotal();
};
