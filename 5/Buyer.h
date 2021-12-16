#ifndef INC_5_BUYER_H
#define INC_5_BUYER_H

#include <utility>
#include <vector>
#include <deque>
#include <atomic>
#include <mutex>
#include "Product.h"
#include "Seller.h"

class Department;
class Seller;

class Buyer {

    static int buyerId;

private:

    std::deque<Product> productsList;
    std::vector<Department*> departments;
    std::atomic<int> curDepartmentIndex = 0;

    std::mutex productsMutex;

    void moveToNextDepartment();

    int id = buyerId++;

public:
    Buyer();

    Buyer(std::deque<Product> productsList, std::vector<Department*> &departments);

    Buyer(const Buyer& b);

    void interactWithSeller(Seller *seller);

    bool finished();
};

#endif //INC_5_BUYER_H
