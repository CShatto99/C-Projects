#include "stdafx.h"
#include <iostream>
using namespace std;

class Circle {
private:
	double radius;
	double PI = 3.14159;
public:
	void Circle::initialR() {
		radius = 0.0;
	}

	void Circle::setRadius(double r) {
		radius = r;
	}

	double Circle::getRadius() const {
		return radius;
	}

	double Circle::getArea() const {
		return PI * (radius*radius);
	}

	double Circle::getDiameter() const {
		return radius * 2;
	}

	double Circle::getCircumference() const {
		return 2 * PI * radius;
	}
};

int main() {
	Circle c;
	double newRad;

	cout << "Enter the radius of a circle: ";
	cin >> newRad;
	c.setRadius(newRad);

	cout << "Area: " << c.getArea() << endl;
	cout << "Diameter: " << c.getDiameter() << endl;
	cout << "Circumference: " << c.getCircumference() << endl;

	system("PAUSE");
    return 0;
}