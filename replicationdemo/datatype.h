#include "fastdb.h"
#include <string>

struct Detail {
    std::string name;
    double      weight;

    TYPE_DESCRIPTOR((KEY(name, INDEXED), FIELD(weight)));
};

struct Supplier {
    std::string company;
    std::string address;

    TYPE_DESCRIPTOR((KEY(company, INDEXED), FIELD(address)));
};

//struct Shipment {
//    dbReference<Detail>   detail;
//    dbReference<Supplier> supplier;
//    int                  price;
//    int                  quantity;
//
//    TYPE_DESCRIPTOR((KEY(detail, HASHED), KEY(supplier, HASHED),
//        FIELD(price), FIELD(quantity)));
//};

struct Shipment {
    int                  price;
    int                  quantity;

    TYPE_DESCRIPTOR((KEY(price, HASHED), FIELD(quantity)));
};