#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <unordered_map>
#include "Product.h"
#include "uuid.h"

enum InvoiceType {
    INCOMING_DOMESTIC, INCOMING_FOREIGN, OUTCOMING_DOMESTIC, OUTCOMING_FOREIGN
};
class Invoice {
    string id;
    InvoiceType type;
    unordered_map<string, int> list_of_products;
    double total_profit = 0;
    std::time_t created_at;
public:
    Invoice(string type_as_str) {
    }
    //Accessing
    string getId() {}
    string getTypeAsStr() {}
    double getProfit() {}
    std::time_t getTimestamp() {}
    int getNumberOfProducts() {}
    int getAllProductIds() {}
    //Modify
    void addProduct(string id, int num) { }
    void removeProduct(string id) { }
    void setType(InvoiceType type) {}
    void deleteInvoice() {}
    virtual void updateProfit() = 0;
    //Searching
    void SearchProductById(string id) { }
    string SearchProductByName(string name) {}
    //Helper
    InvoiceType convertStrToType(string type_as_str) {}
};
