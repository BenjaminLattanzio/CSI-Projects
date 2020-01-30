#include "Complex.h"
#include <iostream>

using namespace std;

double Complex::getReal()const {
	return real;
}
double Complex::getImag()const {
	return imag;
}
void Complex::setReal(double inReal) {
	real = inReal;
}
void Complex::setImag(double inImag) {
	imag = inImag;
}
Complex Complex::addComplex(const Complex& input) { //This is where I add the real and imaginary numbers together. 
	Complex value;
	value.real = this->real + input.getReal();
	value.imag = this->imag + input.getImag();
	return value;
}

Complex Complex::subtractComplex(const Complex& input) { //This is where I subtract the real and imaginary numbers.
	Complex value;
	value.real = this->real - input.getReal();
	value.imag = this->imag - input.getImag();
	return value; 
}
Complex Complex::multiplyComplex(const Complex& input) {// Where I multiply the real and imaginary numbers.
	Complex value;
	value.real = this->real * input.getReal() - this->imag * input.getImag();
	value.imag = this->real * input.getImag() + this->imag * input.getReal();
	return value;

}
void Complex::print() {// diplaying the results.
	cout << "Real: " << this->real << endl;
	cout << "Imag: " << this->imag << endl;
	cout << endl;

}