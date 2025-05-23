#pragma once
#include <string>

using namespace std;

class Shape {
public:
    Shape() {}
    virtual ~Shape() {}

    virtual float Area() = 0;
    virtual string GetType() const { return "Shape"; }
};

