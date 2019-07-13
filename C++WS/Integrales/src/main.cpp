//============================================================================
// Name        : integrales.cpp
// Author      : Stan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "integrales.h"
#include <cmath>

using namespace std;


int main(){
  float a, b, integr, epsilon(0.001);
  int n, iter;
  cout << "Bienvenue dans ce programme de calcul d'intégrale" << endl;
  saisirLimites(a,b);
  //saisirIntervalles(n);
  //afficherCalculs(a,b,n);
  //afficherCalculs2(a,b,n);
  //iter=nitersTrapeze(a,b,epsilon,integr);
  afficherIntervalles(a,b,iter);
  return 0;
}



