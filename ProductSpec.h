#ifndef PRODUCTSPEC_H_
#define PRODUCTSPEC_H_
#include <iostream>
#include "Product.h"
#include <algorithm>
#include <cctype>
#include <string>
using namespace :: std;
enum ProductType{
    MobilePhones,Electronics,VideoGames,Toys,Grocery,Perfumes
};
enum VolumeCategories{
    None,Tiny,Small,Medium,Large,Bulk,Massive,
};
enum WeightCategories{
    NoNe,VeryLight,Light,MediuM,Heavy,VeryHeavy
};

class ProductSpec{
public:
    ProductType product_type;
    WeightCategories weight_categories;
    VolumeCategories volume_categories;
public:
    ProductSpec(ProductType product_type,WeightCategories weight_categories,VolumeCategories volume_categories)
    :product_type(product_type),weight_categories(weight_categories),volume_categories(volume_categories){}

};
string productTypeToString(ProductType type) {
    switch (type) {
        case MobilePhones: return "MobilePhones";
        case Electronics:  return "Electronics";
        case VideoGames:   return "VideoGames";
        case Toys:         return "Toys";
        case Grocery:      return "Grocery";
        case Perfumes:     return "Perfumes";
        default:           return "Unknown";
    }
}
string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c){ return tolower(c); });
    return result;
}

#endif