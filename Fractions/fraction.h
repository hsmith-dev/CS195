#pragma once

namespace mathlib {
	class Fraction {
	private:
		int numerator;
		int denomerator;

	public:
		// Constructor
		mathlib::Fraction(int num, int denum);

		// Arthmetic Operators Overloading
		Fraction operator+(const mathlib::Fraction& other) const;
		Fraction operator-(const mathlib::Fraction& other) const;
		Fraction operator*(const mathlib::Fraction& other) const;
		Fraction operator/(const mathlib::Fraction& other) const;

		// Comparison Operators Overloading
		bool operator==(const mathlib::Fraction& other) const;
		bool operator!=(const mathlib::Fraction& other) const;
		bool operator<(const mathlib::Fraction& other) const;
		bool operator>(const mathlib::Fraction& other) const;
		bool operator<=(const mathlib::Fraction& other) const;
		bool operator>=(const mathlib::Fraction& other) const;

		// Stream Operators Overloading
		friend std::ostream& operator<<(std::ostream& os, Fraction& frac);
		friend std::istream& operator>>(std::istream& is, Fraction& frac);

		// Helper Functions
		void simplify();
		double toDouble() const;
		int gcd(int numerator, int denominator);

		// Get Functions
		int getNumerator() { return numerator; }
		int getDenominator() { return denomerator; }
	};
}