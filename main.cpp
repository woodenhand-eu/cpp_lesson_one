#include <iostream>
#include <map>
#include <vector>

// Exercise 1
// create struct Product with attributes:
// name: std::string, amount: int, barcode: String
// optional attributes:
// price: long long int (in euro cent)
// create class Order with attributes:
// product: Product pointer
// for both objects create non args constructor, args constructor, copy constructor and destructor

// Exercise 2
// create map of products where vector is the key
// return pair of vector and product with highest vector

// Exercise 3
// save vector to the file

struct Product {
    std::string name;
    int amount;
    std::string barcode;
    long long int price;

    Product() {
        std::cout << "Product: none parameter constructor" << std::endl;
    }

    Product(std::string name, int amount, std::string barcode, long long int price) :
            name(name),
            amount(amount),
            barcode(barcode),
            price(price) {
        std::cout << "Product: all parameters constructor" << std::endl;
    }

    //passing reference to the original
    Product(const Product &other) :
            name(other.name),
            amount(other.amount),
            barcode(other.barcode),
            price(other.price) {
        std::cout << "Product: copy constructor" << std::endl;
    }

    ~Product() {
        std::cout << "Product: destructor" << std::endl;
    }

};

class Order {
    Product *product;

public:
    Order() : product(new Product()) {
        std::cout << "Order: none parameter constructor" << std::endl;
    }

    //passing reference to product, and doing deep copy
    Order(Product &product) : product(new Product(product)) {
        std::cout << "Order: one pointer parameter constructor" << std::endl;
    }

    //passing pointer to product, and doing deep copy
    Order(Product *product) : product(new Product(*product)) {
        std::cout << "Order: one reference parameter constructor" << std::endl;
    }

    //passing reference to the original
    Order(const Order &other) : product(new Product(*other.getProduct())) {
        std::cout << "Order: copy constructor" << std::endl;
    }

    ~Order() {
        delete product;
        std::cout << "Order: destructor" << std::endl;
    }

    Product *getProduct() const {
        return product;
    }

    void setProduct(Product *product) {};

};

void exercise1() {
    Order *order=new Order();
    delete order;
}

std::map<std::vector<int>, Product> exercise2MockData() {
    std::map<std::vector<int>, Product> out;
    out.insert({{1, 2, 3, 4, 5, 6}, Product("nazwa", 100, "barcode", 123)});
    out.insert({{1, 2, 3, 4, 1, 6}, Product("mleko", 5, "123123123", 321)});
    out.insert({{6, 6, 6, 6, 6, 6}, Product("nanananana", 666, "666", 666)});
    return out;
}

double calculateMean(std::vector<int> vector) {
    int out = 0;
    for (int e: vector) {
        out += e;
    }
    return out / vector.size();
}

std::pair<std::vector<int>, Product> exercise2() {
    std::map<std::vector<int>, Product> map = exercise2MockData();
    std::pair<std::vector<int>, Product> out = *std::max_element(map.begin(), map.end(), [](
            const std::pair<std::vector<int>, Product> &a,
            const std::pair<std::vector<int>, Product> &b) -> bool {

        return calculateMean(a.first) < calculateMean(b.first);
    });

    std::cout<<"mean value of vector:"+std::to_string(calculateMean(out.first))<<std::endl;

    return out;
}

void exercise3(){

}

int main() {
    std::cout<<"Exercise 1"<<std::endl;
    exercise1();
    std::cout<<"Exercise 2"<<std::endl;
    exercise2();

    return 0;
}
