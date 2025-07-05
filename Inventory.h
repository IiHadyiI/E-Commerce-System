#ifndef INVENTORY_H_
#define INVENTORY_H_
#include "Product.h"
#include <iostream>
#include <vector>
using namespace :: std;

class Inventory{
private:
    vector<vector<Product>> inventory;
public:
    Inventory(){
        inventory.resize(6);
    }
    void add_product(string name,int price,int quantity,ProductSpec product_spec,optional<Date> expiry = nullopt){
        Product P=Product(product_spec,name,price,quantity,expiry);
        inventory[static_cast<int>(product_spec.product_type)].push_back(P);      
    }
    const vector<Product>&get_inv(int Inv)const{
        return inventory[Inv-1];
    }
    Product get_product(int Inv,int item,int quantity){
        inventory.at(Inv).at(item).update_quantity(quantity);
        return inventory.at(Inv).at(item);
    }
    void search_and_print(const string& query) const {
        bool found = false;
        for (auto category : inventory) {
            for (auto product : category) {
                if (product.match(query)) {
                    product.print();
                    found = true;
                }
            }
        }
        if (!found)
            cout << "No products found for query: " << query << endl;
    }
};

#endif