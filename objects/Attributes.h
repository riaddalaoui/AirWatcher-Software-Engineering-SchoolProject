#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <string>

using namespace std;

class Attributes {
public:
    Attributes();
    Attributes(int attributeID, const string& unit, const string& description);
    ~Attributes();

    int GetAttributeID() const;
    void SetAttributeID(int attributeID);

    string GetUnit() const;
    void SetUnit(const string& unit);

    string GetDescription() const;
    void SetDescription(const string& description);

private:
    int AttributeID;
    string Unit;
    string Description;
};

#endif // ATTRIBUTES_H
