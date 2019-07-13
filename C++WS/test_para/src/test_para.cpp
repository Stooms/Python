//============================================================================
// Name        : test_para.cpp
// Author      : Stan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	#pragma omp parallel
	printf("Hello\n");
	printf("World\n");
	return 0;
}
