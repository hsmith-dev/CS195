#pragma once

namespace mathlib {
	template <typename T>
	class Fraction {
	private:
		T numerator;
		T denomerator;

	public:
		// Constructor
		mathlib::Fraction(T num, T denum);

		// Arthmetic Operators Overloading
		Fraction<T> operator + (const mathlib::Fraction<T>& other) const;
		Fraction<T> operator - (const mathlib::Fraction<T>& other) const;
		Fraction<T> operator * (const mathlib::Fraction<T>& other) const;
		Fraction<T> operator / (const mathlib::Fraction<T>& other) const;

		// Comparison Operators Overloading
		bool operator == (const mathlib::Fraction<T>& other) const;
		bool operator != (const mathlib::Fraction<T>& other) const;
		bool operator < (const mathlib::Fraction<T>& other) const;
		bool operator > (const mathlib::Fraction<T>& other) const;
		bool operator <= (const mathlib::Fraction<T>& other) const;
		bool operator >= (const mathlib::Fraction<T>& other) const;

		// Stream Operators Overloading
		template <typename U>
		friend std::ostream& operator<<(std::ostream& os, const Fraction<U>& frac);
		template <typename U>
		friend std::istream& operator>>(std::istream& is, Fraction<U>& frac);

		// Helper Functions
		void simplify();
		double toDouble() const;
		int gcd(T numerator, T denominator);

		// Get Functions
		T getNumerator() { return numerator; }
		T getDenominator() { return denomerator; }
	};
}