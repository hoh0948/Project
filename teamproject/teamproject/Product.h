// Product.h

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <map> // std::map을 사용하기 위해 포함

class Product {
public:
    std::string name;
    double price;
    std::string category;
    std::map<std::string, std::string> attributes; // 카테고리별 추가 정보

    Product(const std::string& n, double p, const std::string& c)
        : name(n), price(p), category(c) {
    }
};

#endif