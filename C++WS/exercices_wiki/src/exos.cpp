//============================================================================
// Name        : exos.cpp
// Author      : Stan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "exos.h"
using namespace std;

const int N=10;

void exo1(){

	int t[N], i, nb = 0;

	for (i=0; i<N; i++) {
		std::cout << "Tapez un entier ";
		std::cin >> t[i];
	}

	for (i=0; i<N; i++) {
		if(t[i]>=10) {
			nb++;
		}
	}

	std::cout << "Le nombre d'entiers supérieurs ou égaux à 10 est : " << nb << std::endl;
}


void exo2(){
    int t[N], i, V;
    bool trouve;

    for (i=0; i<N; i++) {
        std::cout << "Tapez un entier : ";
        std::cin >> t[i];
    }

    std::cout << "Tapez la valeur de V : ";
    std::cin >> V;

    trouve = false;
    i = 0;
    while (!trouve && i<N) {
        if (t[i]==V) {
            trouve=true;
        } else {
            i++;
        }
    }

    if (trouve) {
        std::cout << "La valeur V se trouve dans le tableau" << std::endl;
    } else {
        std::cout << "La valeur V ne se trouve pas dans le tableau" << std::endl;
    }
}


void exo3(){

	int t[N],i,max;

	for (i=0; i<N; i++) {
		std::cout << i << " : tapez un entier ";
		std::cin >> t[i];
	}

	max=t[0];

	for (i=1; i<N; i++) {
		if(t[i]>max) {
			max=t[i];
		}
	}

	std::cout << "Le maximum est : " << max << endl;
}

void exo4(){
    int t[N], i, V;
    bool trouve;

    for (i=0; i<N; i++) {
        std::cout << "Tapez un entier : ";
        std::cin >> t[i];
    }

    std::cout << "Tapez la valeur de V : ";
    std::cin >> V;

    trouve = false;
    i = 0;
    while (!trouve && i<N) {
        if (t[i]==V) {
            trouve=true;
            t.erase(i);
        } else {
            i++;
        }
    }

    for (i=0; i<N-1; i++) {
        std::cout << "t[" << i << "] = " << t[i];
    }
}




