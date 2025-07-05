#ifndef Cart_H_
#define Cart_H_
#include "Product.h"
struct CartItem {
    Product product;
    int quantity;
};

class Cart {
private:
    vector<CartItem> items;

public:
    void add(Product product, int quantity) {
        items.push_back({product, quantity});
    }

    const vector<CartItem>& getItems() const {
        return items;
    }
};

#endif