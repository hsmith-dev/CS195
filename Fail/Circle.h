#pragma once
#include "Shape.h"
#include <string>

using namespace std;

class Circle : public Shape {
public:
    Circle(float r) { m_radius = r; }
    ~Circle() {}

    float Area() override {
        return 3.14f * m_radius * m_radius;
    }

    void SetRadius(float radius) const { radius = radius; }
    float GetRadius() { return m_radius; }
    string GetType() const override { return "Circle"; }


private:
    float m_radius;
};
