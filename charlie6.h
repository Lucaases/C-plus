#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    Product(string name, double price) : name(name), price(price) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
private:
    string name;
    double price;
};

class Cart {
public:
    Cart() : numProducts(0), maxProducts(100) {
        products = new Product*[maxProducts];
    }
    ~Cart() {
        delete[] products;
    }
    void addProduct(Product* product) {
        if (numProducts < maxProducts) {
            products[numProducts++] = product;
        }
    }
    void listProducts() const {
        for (int i = 0; i < numProducts; ++i) {
            cout.width(17);
            cout << products[i]->getName() << ": " << products[i]->getPrice() << endl;
        }
    }
    double totalCost() const {
        double total = 0;
        for (int i = 0; i < numProducts; ++i) {
            total += products[i]->getPrice();
        }
        return total;
    }
    double maxPrice() const {
        int maxPrice=0;
        string maxproduct={"\0"};
        for (int i = 0; i < numProducts; ++i) {
            if (products[i]->getPrice() > maxPrice) {
                maxPrice = products[i]->getPrice();
                maxproduct = products[i]->getName();
            }
        }
        cout<<"最贵的商品名称: "<<maxproduct<<endl;
        return maxPrice;
    }
private:
    Product** products;
    int numProducts;
    int maxProducts;
};
