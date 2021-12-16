#ifndef INC_5_SELLER_H
#define INC_5_SELLER_H

#include <thread>
#include "Buyer.h"

class Department;

class Seller {
private:
    Department *departmentPtr;

    [[noreturn]] void sellLoop();

public:
    explicit Seller(Department *departmentPtr) : departmentPtr(departmentPtr) {}

    void startSelling();

    bool tryToBuy(Product &product);

};

#endif //INC_5_SELLER_H
