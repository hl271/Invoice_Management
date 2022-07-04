#include "App.h"


App::App() {}
void App::addNewInvoiceToDb(string type) {
	string id = type + uuid::generate_uuid();
	time_t now = time(0);
	if (type == "ID") {
		DB_INVOICE[id] = new Incoming_Domestic(id, now);
	}
	else if (type == "IF") {
		DB_INVOICE[id] = new Incoming_Foreign(id, now);

	}
	else if (type == "OD") {
		DB_INVOICE[id] = new Outcoming_Domestic(id, now);

	}
	else if (type == "OF") {
		DB_INVOICE[id] = new Outcoming_Foreign(id, now);

	}
	else return;
	IDS_INVOICE.push_back(id);

}

void App::addExistingInvoiceToDb(string id, string strtime) {
	string type = id.substr(0, 2);
	//strtime has format %Y-%m-%d %H:%M:%S
	int year, mon, day, hour, min, sec;
	char c;
	int dumped = sscanf(strtime.c_str(), "%4d%1s%2d%1s%2d %2d%1s%2d%1s%2d", &year, &c, &mon, &c, &day, &hour, &c, &min, &c, &sec);
	struct tm tm;
	tm.tm_year = year - 1900;
	tm.tm_mon = mon - 1;
	tm.tm_mday = day;
	tm.tm_hour = hour;
	tm.tm_min = min;
	tm.tm_sec = sec;
	time_t timestamp = mktime(&tm);
	if (type == "ID") {
		DB_INVOICE[id] = new Incoming_Domestic(id, timestamp);
	}
	else if (type == "IF") {
		DB_INVOICE[id] = new Incoming_Foreign(id, timestamp);
	}
	else if (type == "OD") {
		DB_INVOICE[id] = new Outcoming_Domestic(id, timestamp);
	}
	else if (type == "OF") {
		DB_INVOICE[id] = new Outcoming_Foreign(id, timestamp);
	}
	else return;
	IDS_INVOICE.push_back(id);
}

void App::addNewProductToDb(string name, double price) {
	string id = uuid::generate_uuid();
	DB_PRODUCT[id] = Product(id, name, price);
	IDS_PRODUCT.push_back(id);
}

void App::addExistingProductToDb(string id, string name, double price) {
	DB_PRODUCT[id] = Product(id, name, price);
	IDS_PRODUCT.push_back(id);
}
