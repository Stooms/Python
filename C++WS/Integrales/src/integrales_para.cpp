#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "integrales.h"
#include <cmath>
#include "omp.h"

using namespace std;



/* Méthodes des rectangles */

float integraleRectangleG_para(float a, float b, int n){
	float h, I(0.0);
	//cout << "Méthode des rectangles gauche" << endl;
	//saisirLimites(a,b);
	//saisirIntervalles(n);
	h=(b-a)/float(n);
	#pragma omp parallel for reduction(+:I)
	for (int i=0;i<n;i++){
		I+=h*fonction(a+i*h);
	}
	//printf("Méthodes des rectangles gauche : %f\n",I);
	return I;
}

float integraleRectangleD_para(float a, float b, int n){
	float h, I(0.0);
	//cout << "Méthode des rectangles droite" << endl;
	//saisirLimites(a,b);
	//saisirIntervalles(n);
	h=(b-a)/float(n);
	for (int i=1;i<n+1;i++){
		I+=h*fonction(a+i*h);
	}
	//printf("Méthodes des rectangles droite : %f\n",I);
	return I;
}

/* Méthodes des trapèzes */

float integraleTrapeze_para(float a, float b, int n){
	float h, I(0.0);
	h=(b-a)/float(n);
	for (int i=1;i<n;i++){
		I+=h*fonction(a+i*h);
	}
	I+=h*(0.5*fonction(a)+0.5*fonction(b));
	//printf("Méthodes des trapèzes : %f\n",I);
	return I;
}

/* Méthode de Simpson */

float integraleSimpson_para(float a, float b, int n){
	float h, I(0.0);
	h=(b-a)/float(n);
	for (int i=1;i<n;i++){
		I+=h/6.0*(2.0*fonction(a+i*h)+4.0*fonction(a+i*h+h/2.0));
	}
	I+=h/6.0*(fonction(a)+fonction(b)+4.0*fonction(a+h/2.0));
	//printf("Méthodes de Simpson : %f\n",I);
	return I;
}

/* Affichage des calculs */

void afficherCalculs_para(float a, float b, int n){
	float Iexact, IrectG, IrectD, Itrap;
	//saisirLimites(a,b);
	//saisirIntervalles(n);
	Iexact=test_exacte(a,b);
	printf("\nMéthode extacte: %f\n",Iexact);
	IrectG=integraleRectangleG_para(a,b,n);
	printf("Méthodes des rectangles gauche : %f\n",IrectG);
	IrectD=integraleRectangleD_para(a,b,n);
	printf("Méthodes des rectangles droite : %f\n",IrectD);
	Itrap=integraleTrapeze_para(a,b,n);
	printf("Méthodes des trapèzes : %f\n",Itrap);
}
