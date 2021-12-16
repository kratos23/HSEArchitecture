#ifndef INC_5_DEPARTMENT_H
#define INC_5_DEPARTMENT_H

#include <set>
#include "ThreadSafeQueue.h"
#include "Buyer.h"
#include "Product.h"

class Department {

private:
    ThreadSafeQueue<Buyer*> buyersQueue;
    std::set<Product> departmentProducts;

public:

    Department();

    Department(const Department& deps);

    Department(const std::set<Product> &departmentProducts);

    std::optional<Buyer*> takeBuyerFromQueue();

    bool haveProduct(Product product);

    void addBuyerToQueue(Buyer *buyer);

};

#endif //INC_5_DEPARTMENT_H
