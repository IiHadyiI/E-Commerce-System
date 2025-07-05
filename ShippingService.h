#ifndef SHIPPINGSERRVICE_H_
#define SHIPPINGSERRVICE_H_
#include "Cart.h"
class ShippingService {
public:
    static double calculateTotalWeight(const Cart& cart) {
        double totalWeight = 0;
        for (const auto& item : cart.getItems()) {
            totalWeight += item.product.getWeight() * item.quantity;
        }
        return totalWeight;
    }

    static int calculateShippingFee(double totalWeight) {
        if (totalWeight == 0) return 0;
        else if (totalWeight <= 1.0) return 20;
        else if (totalWeight <= 3.0) return 30;
        else return 50;
    }
};

#endif