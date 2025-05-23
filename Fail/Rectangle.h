#pragma once
#include "Shape.h"
#include <string>\

using namespace std;

class Rectangle : public Shape {
public:
    Rectangle(float w, float h) {
        m_width = w;
        m_height = h;
    }

    float Area() override {
        return m_width * m_height;
    }
    string GetType() const override { return "Rectangle"; }

private:
    float m_width;
    float m_height;
};

