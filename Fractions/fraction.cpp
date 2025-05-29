#include <iostream>  
#include <stdexcept>  
#include "fraction.h" 

namespace mathlib {  
	template<typename T>
	mathlib::Fraction<T>::Fraction(T num, T denum) {  
		if (denum == 0) {  
			throw std::invalid_argument("Denominator cannot be zero.");  
		}  

		numerator = num;  
		denomerator = denum;
		simplify();
	}  

	// Arithmetic operators  
	template<typename T>
	Fraction<T> Fraction<T>::operator + (const Fraction<T>& other) const {  
		return Fraction(numerator * other.denomerator + other.numerator * denomerator, denomerator * other.denomerator);
	}  

	template<typename T>
	Fraction<T> Fraction<T>::operator - (const Fraction<T>& other) const {
		return Fraction(numerator * other.denomerator - other.numerator * denomerator, denomerator * other.denomerator);
	}  

	template<typename T>
	Fraction<T> Fraction<T>::operator * (const Fraction<T>& other) const {
		return Fraction(numerator * other.numerator, denomerator * other.denomerator);
	}  

	template<typename T>
	Fraction<T> Fraction<T>::operator / (const Fraction<T>& other) const {
		if (other.numerator == 0) {  
			throw std::invalid_argument("Cannot divide by zero.");  
		}  
		return Fraction(numerator * other.denomerator, denomerator * other.numerator);
	}  

	// Comparison operators  
	template<typename T>
	bool Fraction<T>::operator == (const Fraction<T>& other) const {
		return numerator * other.denomerator == other.numerator * denomerator;
	}  

	template<typename T>
	bool Fraction<T>::operator != (const Fraction<T>& other) const {
		return !(*this == other);  
	}  

	template<typename T>
	bool Fraction<T>::operator < (const Fraction<T>& other) const {
		return numerator * other.denomerator < other.numerator * denomerator;
	}  

	template<typename T>
	bool Fraction<T>::operator <= (const Fraction<T>& other) const {
		return *this < other || *this == other;  
	}  

	template<typename T>
	bool Fraction<T>::operator > (const Fraction<T>& other) const {
		return !(*this <= other);  
	}  

	template<typename T>
	bool Fraction<T>::operator >= (const Fraction<T>& other) const {
		return !(*this < other);  
	}  

	// Stream operators  
	template<typename U>
	std::ostream& operator << (std::ostream& os, Fraction<U>& fract) {  
		os << fract.getNumerator() << '/' << fract.getDenominator();  
		return os;  
	}  

	template<typename U>
	std::istream& operator >> (std::istream& is, Fraction<U>& fract) {
		char seperator;  
		is >> fract.numerator >> seperator >> fract.denomerator;
		if (fract.denomerator == 0) {
			throw std::invalid_argument("Denominator cannot be zero.");  
		}  
		fract.simplify();  
		return is;  
	}  

	template<typename T>
	T gcd(T numerator, T denomerator) {
		return (denomerator == 0) ? numerator : gcd(denomerator, numerator % denomerator);
	}

	template<typename T>
	void Fraction<T>::simplify() {   
		int gcd = Fraction::gcd(numerator, denomerator);  
		numerator /= gcd;
		denomerator /= gcd;
		if (denomerator < 0) { // Ensure denominator is positive  
			numerator = -numerator;  
			denomerator = -denomerator;
		}  
	}  

	template<typename T>
	double Fraction<T>::toDouble() const {
		return static_cast<double>(numerator) / denomerator;
	}
}