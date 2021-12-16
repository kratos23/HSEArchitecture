#include "Buyer.h"
#include "Department.h"

#include <iostream>

int Buyer::buyerId = 1;

void Buyer::moveToNextDepartment() {
    curDepartmentIndex++;
    if (curDepartmentIndex >= departments.size()) {
        curDepartmentIndex -= (int) departments.size();
    }
    departments[curDepartmentIndex]->addBuyerToQueue(this);
}

Buyer::Buyer(std::deque<Product> productsList, std::vector<Department *> &departments) :
        productsList(std::move(productsList)),
        departments(departments) {
    departments[curDepartmentIndex]->addBuyerToQueue(this);
}

void Buyer::interactWithSeller(Seller *seller) {
    std::lock_guard<std::mutex> lock(productsMutex);
    while (!productsList.empty()) {
        if (seller->tryToBuy(productsList.front())) {
            std::cout << "Buyer#" << id << " bought product with id = " << productsList.front().productId
                      << std::endl;
            productsList.pop_front();
        } else {
            moveToNextDepartment();
            return;
        }
    }
}

bool Buyer::finished() {
    std::lock_guard<std::mutex> lock(productsMutex);
    return productsList.empty();
}

Buyer::Buyer() {}

Buyer::Buyer(const Buyer &b) : productsList(b.productsList), departments(b.departments), id(b.id) {
    curDepartmentIndex.store(b.curDepartmentIndex);
}
