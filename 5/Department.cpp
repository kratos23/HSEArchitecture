#include "Department.h"

Department::Department(const std::set<Product> &departmentProducts) : departmentProducts(departmentProducts) {}

std::optional<Buyer*> Department::takeBuyerFromQueue() {
    return buyersQueue.pop();
}

bool Department::haveProduct(Product product) {
    return departmentProducts.find(product) != departmentProducts.end();
}

void Department::addBuyerToQueue(Buyer *buyer) {
    buyersQueue.push(buyer);
}

Department::Department() {}

Department::Department(const Department &deps) : departmentProducts(deps.departmentProducts){

}
