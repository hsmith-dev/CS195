#pragma once
#include <iostream>
#include <stdexcept>

namespace mathlib {
    template <typename T>
    class Fraction {
    private:
        T numerator;
        T denominator;

    public:
        // Constructors
        Fraction() : numerator(0), denominator(1) {}
        Fraction(T num, T denum) {
            if (denum == 0) {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
            numerator = num;
            denominator = denum;
            simplify();
        }

        // Arithmetic Operators
        Fraction<T> operator+(const Fraction<T>& other) const {
            return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
        }

        Fraction<T> operator-(const Fraction<T>& other) const {
            return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
        }

        Fraction<T> operator*(const Fraction<T>& other) const {
            return Fraction(numerator * other.numerator, denominator * other.denominator);
        }

        Fraction<T> operator/(const Fraction<T>& other) const {
            if (other.numerator == 0) {
                throw std::invalid_argument("Cannot divide by zero.");
            }
            return Fraction(numerator * other.denominator, denominator * other.numerator);
        }

        // Comparison Operators
        bool operator==(const Fraction<T>& other) const {
            return numerator * other.denominator == other.numerator * denominator;
        }

        bool operator!=(const Fraction<T>& other) const { return !(*this == other); }
        bool operator<(const Fraction<T>& other) const { return numerator * other.denominator < other.numerator * denominator; }
        bool operator>(const Fraction<T>& other) const { return !(*this <= other); }
        bool operator<=(const Fraction<T>& other) const { return *this < other || *this == other; }
        bool operator>=(const Fraction<T>& other) const { return !(*this < other); }

        // Stream Operators
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Fraction<U>& frac) {
            os << frac.numerator << '/' << frac.denominator;
            return os;
        }

        template <typename U>
        friend std::istream& operator>>(std::istream& is, Fraction<U>& frac) {
            char separator;
            is >> frac.numerator >> separator >> frac.denominator;
            if (frac.denominator == 0) {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
            frac.simplify();
            return is;
        }

        // Helper Functions
        void simplify() {
            T gcd = Fraction::gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        static T gcd(T a, T b) {
            return (b == 0) ? a : gcd(b, a % b);
        }

        double toDouble() const { return static_cast<double>(numerator) / denominator; }

        // Getters
        T getNumerator() const { return numerator; }
        T getDenominator() const { return denominator; }
    };
}