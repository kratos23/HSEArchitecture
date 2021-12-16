#include <optional>
#include <iostream>
#include "Seller.h"
#include "Buyer.h"
#include "Department.h"

[[noreturn]] void Seller::sellLoop() {
    while (true) {
        std::optional<Buyer*> buyer = departmentPtr->takeBuyerFromQueue();
        if (buyer.has_value()) {
            buyer.value()->interactWithSeller(this);
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Seller::startSelling() {
    std::thread thread1(&Seller::sellLoop, this);
    thread1.detach();
}

bool Seller::tryToBuy(Product &product) {
    return departmentPtr->haveProduct(product);
}
