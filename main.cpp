#include <iostream>

// Exercise 1
// create struct Product with attributes:
// name: std::string, amount: int, barcode: String
// optional attributes:
// price: long long int (in euro cent)
// create class Order with attributes:
// product: Product pointer
// for both objects create non args constructor, args constructor, copy constructor and destructor

struct Product {
    std::string name;
    int amount;
    std::string barcode;
    long long int price;

    Product() {
        std::cout << "Product: none parameter constructor" << std::endl;
    };

    Product(std::string name, int amount, std::string barcode, long long int price) :
            name(name),
            amount(amount),
            barcode(barcode),
            price(price) {
        std::cout << "Product: all parameters constructor" << std::endl;
    };

    //passing reference to the original
    Product(const Product &other) :
            name(other.name),
            amount(other.amount),
            barcode(other.barcode),
            price(other.price) {
        std::cout << "Product: copy constructor" << std::endl;
    };

    ~Product() {
        std::cout<<"Product: destructor"<<std::endl;
    }

};

class Order {
    Product *product;

public:
    Order() : product(new Product()) {
        std::cout << "Order: none parameter constructor" << std::endl;
    };

    //passing reference to product, and doing deep copy
    Order(Product &product) : product(new Product(product)) {
        std::cout << "Order: one pointer parameter constructor" << std::endl;
    };

    //passing pointer to product, and doing deep copy
    Order(Product *product) : product(new Product(*product)) {
        std::cout << "Order: one reference parameter constructor" << std::endl;
    };

    //passing reference to the original
    Order(const Order &other) : product(new Product(*other.getProduct())) {
        std::cout << "Order: copy constructor" << std::endl;
    };

    ~Order() {
        delete product;
        std::cout << "Order: destructor" << std::endl;
    }

    Product *getProduct() const {
        return product;
    };

    void setProduct(Product *product) {};

};

int main() {
    Order order;
    return 0;
}
