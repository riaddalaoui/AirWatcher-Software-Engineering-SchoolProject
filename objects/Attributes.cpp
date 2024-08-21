#include "Attributes.h"

Attributes::Attributes() : AttributeID(0) {}

Attributes::Attributes(int attributeID, const string& unit, const string& description)
    : AttributeID(attributeID), Unit(unit), Description(description) {}

Attributes::~Attributes() {}

int Attributes::GetAttributeID() const {
    return AttributeID;
}

void Attributes::SetAttributeID(int attributeID) {
    AttributeID = attributeID;
}

string Attributes::GetUnit() const {
    return Unit;
}

void Attributes::SetUnit(const string& unit) {
    Unit = unit;
}

string Attributes::GetDescription() const {
    return Description;
}

void Attributes::SetDescription(const string& description) {
    Description = description;
}
