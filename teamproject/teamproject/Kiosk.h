#ifndef KIOSK_H
#define KIOSK_H

#include <string>
#include <vector>
#include <map>
#include <chrono>
// Product 클래스 선언
class Product {
public:
    std::string name;
    double price;
    std::string category;
    std::map<std::string, std::string> attributes;

    Product(const std::string& n, double p, const std::string& c)
        : name(n), price(p), category(c) {
    }
};

struct CartItem {
    Product product;
    int quantity;
};

// ShoppingCart 클래스 선언
class ShoppingCart {
private:
    std::vector<CartItem> items;
public:
    void addItem(const Product& product, int quantity);
    void updateItemQuantity(const std::string& productName, int newQuantity);
    void removeItem(const std::string& productName);
    const std::vector<CartItem>& getItems() const { return items; }
    double calculateTotal() const;
    void clearCart() { items.clear(); } // clearCart() 함수가 여기에 정의되어 있습니다.
};
class Order {
public:
    std::vector<CartItem> items;
    double totalAmount;
    std::string paymentMethod; // 결제 방법
    std::chrono::system_clock::time_point orderTime; // 주문 시각
};

class Kiosk {
private:
    std::map<std::string, std::vector<Product>> allProducts;
    ShoppingCart cart;
    std::vector<Order> orderHistory;

public:
    void printHeader() const; 
    void addProduct(const Product& product);
    void run();
    void searchProduct();
    void showCategories();
    void showProductsInCategory(const std::string& categoryName);
    void viewCart();
    void checkout();
    void viewOrders();
    std::string getDeliveryStatus(const Order& order); // 배송 상태를 반환하는 함수
};

#endif
