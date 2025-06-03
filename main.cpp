#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
    double perimeter() const override { return 2 * 3.14 * radius; }
    void display() const override {
        cout << "Circle: area = " << area()
            << ", perimeter = " << perimeter() << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
    void display() const override {
        cout << "Rectangle: area = " << area()
            << ", perimeter = " << perimeter() << endl;
    }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
    double perimeter() const override { return a + b + c; }
    double area() const override {
        double s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    void display() const override {
        cout << "Triangle: area = " << area()
            << ", perimeter = " << perimeter() << endl;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(11));
    shapes.push_back(new Rectangle(2, 5));
    shapes.push_back(new Triangle(2, 4, 5));

    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        (*it)->display();
    }

    for (auto s : shapes) delete s;
}
