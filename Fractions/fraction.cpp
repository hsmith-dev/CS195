#include <iostream>  
#include <stdexcept>  
#include "fraction.h" 

namespace mathlib {  
	mathlib::Fraction::Fraction(int num, int denum) {  
		if (denum == 0) {  
			throw std::invalid_argument("Denominator cannot be zero.");  
		}  

		numerator = num;  
		denomerator = denum;
	}  

	// Arithmetic operators  
	Fraction Fraction::operator+(const Fraction& other) const {  
		return Fraction(numerator * other.denomerator + other.numerator * denomerator, denomerator * other.denomerator);
	}  

	Fraction Fraction::operator-(const Fraction& other) const {  
		return Fraction(numerator * other.denomerator - other.numerator * denomerator, denomerator * other.denomerator);
	}  

	Fraction Fraction::operator*(const Fraction& other) const {  
		return Fraction(numerator * other.numerator, denomerator * other.denomerator);
	}  

	Fraction Fraction::operator/(const Fraction& other) const {  
		if (other.numerator == 0) {  
			throw std::invalid_argument("Cannot divide by zero.");  
		}  
		return Fraction(numerator * other.denomerator, denomerator * other.numerator);
	}  

	// Comparison operators  
	bool Fraction::operator==(const Fraction& other) const {  
		return numerator * other.denomerator == other.numerator * denomerator;
	}  

	bool Fraction::operator!=(const Fraction& other) const {  
		return !(*this == other);  
	}  

	bool Fraction::operator<(const Fraction& other) const {  
		return numerator * other.denomerator < other.numerator * denomerator;
	}  

	bool Fraction::operator<=(const Fraction& other) const {  
		return *this < other || *this == other;  
	}  

	bool Fraction::operator>(const Fraction& other) const {  
		return !(*this <= other);  
	}  

	bool Fraction::operator>=(const Fraction& other) const {  
		return !(*this < other);  
	}  

	// Stream operators  
	std::ostream& operator<<(std::ostream& os, Fraction& fract) {  
		os << fract.getNumerator() << '/' << fract.getDenominator();  
		return os;  
	}  

	std::istream& operator>>(std::istream& is, Fraction& fract) {  
		char seperator;  
		is >> fract.numerator >> seperator >> fract.denomerator;
		if (fract.denomerator == 0) {
			throw std::invalid_argument("Denominator cannot be zero.");  
		}  
		fract.simplify();  
		return is;  
	}  

	int gcd(int numerator, int denomerator) {
		return (denomerator == 0) ? numerator : gcd(denomerator, numerator % denomerator);
	}

	void Fraction::simplify() {   
		int gcd = Fraction::gcd(numerator, denomerator);  
		numerator /= gcd;
		denomerator /= gcd;
		if (denomerator < 0) { // Ensure denominator is positive  
			numerator = -numerator;  
			denomerator = -denomerator;
		}  
	}  

	double Fraction::toDouble() const {
		return static_cast<double>(numerator) / denomerator;
	}
}