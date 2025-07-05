#include <iostream>
using namespace::std;

#include"Cart.h"
#include"ShippingService.h"
#include"Inventory.h"
#include"ProductSpec.h"

void checkout(const string& customer, Cart& cart) {
        cout << "** Shipment notice **" << endl;

        double totalWeight = ShippingService::calculateTotalWeight(cart);

        for (auto item : cart.getItems()) {
            cout << item.quantity << "x " << item.product.get_name() << endl;
            item.product.update_quantity(item.quantity);
        }

        cout << "Total package weight " << totalWeight << "kg" << endl;

        cout << "** Checkout receipt **" << endl;

        int subtotal = 0;
        for (const auto& item : cart.getItems()) {
            int linePrice = item.quantity * item.product.getPrice();
            cout << item.quantity << "x " << item.product.get_name() << " " << linePrice << endl;
            subtotal += linePrice;
        }

        cout << "----------------------" << endl;
        int shippingFee = ShippingService::calculateShippingFee(totalWeight);
        int totalAmount = subtotal + shippingFee;

        cout << "Subtotal " << subtotal << endl;
        cout << "Shipping " << shippingFee << endl;
        cout << "Amount " << totalAmount << endl;
    }
int main(){
    ProductSpec cheeseSpec(Grocery, MediuM, Small);
    ProductSpec biscuitSpec(Grocery, Light, Small);
    Date cheeseExpiry = {5, 7, 2025};
    Date biscuitExpiry = {10, 7, 2025};

    Product cheese(cheeseSpec, "Cheese 400g", 100, 20, cheeseExpiry);
    Product biscuits(biscuitSpec, "Biscuits 700g", 150, 30, biscuitExpiry);
    Inventory inv;

    ProductSpec spec1(Electronics, MediuM, Large);
    ProductSpec spec2(Grocery, Light, Small);
    Date expiry = {5, 7, 2025};

    inv.add_product("TV", 5000, 10, spec1);
    inv.add_product("Biscuits", 50, 30, spec2, expiry);

    cout << "\n=== Search: 'TV' ===\n";
    inv.search_and_print("TV");

    cout << "\n=== Search: 'Electronics' ===\n";
    inv.search_and_print("Electronics");

    cout << "\n=== Search: 'Grocery' ===\n";
    inv.search_and_print("Grocery");

    cout << "\n=== Search: 'Laptop' ===\n";
    inv.search_and_print("Laptop");
    Cart cart;
    cart.add(cheese, 2);
    cart.add(biscuits, 1);

    checkout("John Doe", cart);
    return 0;
}