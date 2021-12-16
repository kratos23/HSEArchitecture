#ifndef INC_5_PRODUCT_H
#define INC_5_PRODUCT_H

struct Product {
    int productId;

    Product() {}

    Product(int productId) : productId(productId) {}

    bool operator<(const Product &rhs) const {
        return productId < rhs.productId;
    }

    bool operator>(const Product &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Product &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Product &rhs) const {
        return !(*this < rhs);
    }

    bool operator==(const Product &rhs) const {
        return productId == rhs.productId;
    }

    bool operator!=(const Product &rhs) const {
        return !(rhs == *this);
    }
};

#endif //INC_5_PRODUCT_H
