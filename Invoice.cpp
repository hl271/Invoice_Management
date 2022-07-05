#include "Invoice.h"

time_t Invoice::getTimestamp() {
	return created_at;
}
float Invoice::getTax() {
	return tax;
}
void Invoice::setId(string id) { this->id = id; }
bool Invoice::checkIfProductExists(string name_of_product) {
	if (list_of_products.find(name_of_product) == list_of_products.end()) {
		return false;
	}
	else return true;
}

void Invoice::addProduct(string name, Product &product, int quantity) {
	struct ProductWithQuantity combined_product;
	combined_product.product = product; combined_product.quantiy = quantity;
	list_of_products[name] = combined_product;
}

void Invoice::removeProduct(string name) {
	list_of_products.erase(name);
}

double Invoice::calculateTotal() {
	double total = 0.0;
	for (auto i = list_of_products.begin(); i != list_of_products.end(); i++) {
		string name = i->first; 
		int quantity = i->second.quantiy;
		double price = i->second.product.getUnitPrice();
		total += price * quantity;
	}
	return total;
}