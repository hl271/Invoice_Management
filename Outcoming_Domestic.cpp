#include "Outcoming_Domestic.h"

bool Outcoming_Domestic::isDomestic() { return true; }
bool Outcoming_Domestic::isIncoming() { return false; }

string Outcoming_Domestic::getTypeAsStr() { return "Outcoming Domestic"; }