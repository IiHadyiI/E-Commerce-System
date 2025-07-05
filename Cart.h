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
        if (quantity > product.getQuantity()) {
            cout << "Not enough stock for " << product.get_name() << endl;
            return;
        }
        items.push_back({product, quantity});
    }

    const vector<CartItem>& getItems() const {
        return items;
    }
};

#endif