#include <vector>

#include "Department.h"
#include "Buyer.h"
#include "Seller.h"

std::vector<Buyer*> buyers;

std::deque<Product> buyerProductList = {Product(8), Product(2),
                                        Product(1), Product(5),
                                        Product(3), Product(7),
                                        Product(6), Product(4)};

void createSomeBuyers(Department *dep1, Department *dep2) {
    std::vector<Department*> deps = {dep1, dep2};
    for (int i = 0; i < 20; i++) {
        buyers.push_back(new Buyer(buyerProductList, deps));
    }
}

void waitForBuyersCompletion() {
    bool allCompleted;
    do {
        allCompleted = true;
        for (auto &buyer : buyers) {
            if (!buyer->finished()) {
                allCompleted = false;
            }
        }
    } while (!allCompleted);
}

int main() {
    Department dep1({Product(1), Product(2), Product(3), Product(4)});
    Department dep2({Product(5), Product(6), Product(7), Product(8)});
    Seller s1(&dep1);
    Seller s2(&dep2);

    s1.startSelling();
    s2.startSelling();

    createSomeBuyers(&dep1, &dep2);
    waitForBuyersCompletion();
    return 0;
}
