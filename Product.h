#ifndef PRODUCT_H_
#define PRODUCT_H_
#include "Date.h"
#include <optional>
#include "ProductSpec.h"
#include <iostream>
#include <map>
#include <vector>
#include <any>
using namespace :: std;
class Product{
private:
    ProductSpec product_specs;
    string name;
    int price;
    int quantity;
    optional<Date> expiry_date;
public:
    Product(ProductSpec product_specs,string name,int price,int quantity,optional<Date> expiry_date = nullopt)
    :product_specs(product_specs),name(name),price(price),quantity(quantity),expiry_date(expiry_date){}

    const string&get_name()const{
        return name;
    }
    void update_quantity(int quant){
        quantity-=quant;
    }
    bool match(string query){
        string lowerQuery = toLower(query);
        string lowerName = toLower(name);
        string typeStr = productTypeToString(product_specs.product_type);
        string lowerType = toLower(typeStr);

        return lowerQuery == lowerName || lowerQuery == lowerType;
    }
    const optional<Date>& get_expiry_date() const {
        return expiry_date;
    }

    bool is_expired(const Date& today) const {
        if (!expiry_date.has_value())
            return false;  // no expiry
        return expiry_date.value() < today;
    }
    double getWeight() const {
        // Example: convert WeightCategory enum to kg
        switch (product_specs.weight_categories) {
            case VeryLight: return 0.2;
            case Light:     return 0.4;
            case Medium:    return 0.7;
            case Heavy:     return 1.2;
            case VeryHeavy: return 3.0;
            default:        return 0.0;
        }
    }
  
    int getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void reduceQuantity(int qty) {
        update_quantity(qty);
    }
    void print() const {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Product Type: " << productTypeToString(product_specs.product_type) << endl;
        cout << "Weight Category: " << static_cast<int>(product_specs.weight_categories) << endl;
        cout << "Volume Category: " << static_cast<int>(product_specs.volume_categories) << endl;

        if (expiry_date.has_value()) {
            cout << "Expiry Date: " << expiry_date->day << "/" 
                << expiry_date->month << "/" << expiry_date->year << endl;
        } else {
            cout << "Expiry Date: None" << endl;
        }
        cout << "-----------------------------" << endl;
    }   
};
#endif