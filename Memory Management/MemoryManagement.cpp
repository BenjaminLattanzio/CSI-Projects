#include<iostream>
#include<cstdlib>
#include"MemoryManagement.h"
using namespace std;


int main() {
	MemoryManagement lab2; //instance of memory management
	lab2.firstFit(); //calling instance for each fit
	lab2.bestFit();
	lab2.nextFit();
	lab2.worstFit();

	system("Pause");
	return 0;
}