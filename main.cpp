#include <iostream>
#include <vector>
#include <algorithm>  
#include <string>
using namespace std;

class Product {
public:
    string name;
    string category;
    double price;

    Product(string n, string c, double p) {
        name = n;
        category = c;
        price = p;
    }

    void display() const {
        cout << "Name: " << name << ", Category: " << category << ", Price: $" << price << endl;
    }
};

void addProduct(vector<Product>& products) {
    string name, category;
    double price;

    cout << "Enter product name: ";
    getline(cin >> ws, name);

    cout << "Enter category: ";
    getline(cin, category);

    cout << "Enter price: ";
    cin >> price;

    products.push_back(Product(name, category, price));
    cout << "Product added\n";
}

void displayProducts(const vector<Product>& products) {
    if (products.empty()) {
        cout << "No products\n";
        return;
    }
    for (const auto& product : products) {
        product.display();
    }
}

void filterByCategory(const vector<Product>& products) {
    string category;
    cout << "Enter category to filter: ";
    getline(cin >> ws, category);

    bool found = false;
    for (const auto& product : products) {
        if (product.category == category) {
            product.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No products in this category.\n";
    }
}

void sortByPrice(vector<Product>& products) {
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
        });
    cout << "Products sorted by price.\n";
}

int main() {
    vector<Product> products;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add product\n";
        cout << "2. Display all products\n";
        cout << "3. Filter products by category\n";
        cout << "4. Sort products by price\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct(products);
            break;
        case 2:
            displayProducts(products);
            break;
        case 3:
            filterByCategory(products);
            break;
        case 4:
            sortByPrice(products);
            break;
        case 5:
            cout << "Exiting\n";
            break;
        default:
            cout << "Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
