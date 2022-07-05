#include "Incoming_Foreign.h"

bool Incoming_Foreign::isDomestic() { return false; }
bool Incoming_Foreign::isIncoming() { return true; }

string Incoming_Foreign::getTypeAsStr() { return "Incoming Foreign"; }