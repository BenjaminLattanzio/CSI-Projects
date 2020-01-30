#pragma once
class Complex {
private:
	double real;
	double imag;

public:

	Complex() : real(0.0), imag(0.0) {};
	Complex(double inReal, double inImag) { real = inReal; imag = inImag; }; //implementation list
	double getReal()const;
	double getImag()const;
	void setReal(double);
	void setImag(double);
	Complex addComplex(const Complex&);
	Complex subtractComplex(const Complex&);
	Complex multiplyComplex(const Complex&);
	void print();

};