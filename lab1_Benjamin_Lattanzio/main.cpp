#include<iostream>
#include "Complex.h"

using namespace std;

int main() {
	Complex numOne, numTwo, numThree;
	numOne.setReal(9.5);
	numOne.setImag(10.3);
	numTwo.setReal(7.8);
	numTwo.setImag(5.3);
	numThree = numTwo.addComplex(numOne);
	numThree.print();
	numThree = numTwo.subtractComplex(numOne);
	numThree.print();
	numThree = numTwo.multiplyComplex(numOne);
	numThree.print();
	system("pause");
	return 0;
}