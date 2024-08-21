#ifndef ATTRIBUTEDAO_H
#define ATTRIBUTEDAO_H

#include <vector>
#include "Attributes.h"

using namespace std;

class AttributeDAO {
public:
    AttributeDAO();
    ~AttributeDAO();

    vector<Attributes> allAttributes();
};

#endif // ATTRIBUTEDAO_H
