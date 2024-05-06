#pragma once
#include <iostream>
class Complex
{
public:
	Complex();
	Complex(double real, double im);
	
	double getReal() const;
	double getIm() const;
	
	void setReal(double real);
	void setIm(double im);

	Complex getConjugated() const;  //връща комплексно спрегнатото число на текущия обект.

	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);

	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);

private:
	double real;
	double im;
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);
