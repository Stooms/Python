#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "integrales.h"
#include <cmath>

using namespace std;

/* Fonction et primitive */

float fonction(float x){
	float y;
	y=cos(x);
	return y;
}

float primF(float x){
  float y;
  y=sin(x);
  return y;
}

/* Paramétrage intégrale */


void saisirLimites(float& a, float& b){
	cout << "Limites d'intégration ? : a = "; 	cin >> a; 	cout << " et b = "; 	cin >> b;
	while (a>b){
		cout << "Vous devez respecter a <= b, veuillez recommencer" << endl;
		cout << "Limites d'intégration ? : a = ";
		cin >> a;
		cout << " et b = ";
		cin >> b;
	}
}

int saisirIntervalles(int& n){
	cout << "Nombre d'intervalles = "; 	cin >> n;
	while (n<1){
		cout << "n doit être plus grand que 1, veuillez recommencer" << endl;
		cout << "Nombre d'intervalles = " << endl;
		cin >> n;
	}
	return n;
}


/* Calcul exact d'intégrale */


float integraleExacte(float a, float b){
  float I;
  I=primF(b)-primF(a);
  return I;
}

float test_exacte(float a, float b){
	float I;
	//cout << "Méthode de calcul exact" << endl;
	//saisirLimites(a,b);
	I=integraleExacte(a,b);
	//printf("Méthodes calcul exact : %f\n",I);
	return I;
}

/* Méthodes des rectangles */

float integraleRectangleG(float a, float b, int n){
	float h, I(0.0);
	//cout << "Méthode des rectangles gauche" << endl;
	//saisirLimites(a,b);
	//saisirIntervalles(n);
	h=(b-a)/float(n);
	for (int i=0;i<n;i++){
		I+=h*fonction(a+i*h);
	}
	//printf("Méthodes des rectangles gauche : %f\n",I);
	return I;
}

float integraleRectangleD(float a, float b, int n){
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

float integraleTrapeze(float a, float b, int n){
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

float integraleSimpson(float a, float b, int n){
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

void afficherCalculs(float a, float b, int n){
	float Iexact, IrectG, IrectD, Itrap;
	//saisirLimites(a,b);
	//saisirIntervalles(n);
	for (int i=2;i<n+1;i++){
		cout << "\n==> " << i << " sous-intervalles" << endl;
		Iexact=test_exacte(a,b);
		printf("Méthode extacte: %f\n",Iexact);
		IrectG=integraleRectangleG(a,b,i);
		printf("Méthodes des rectangles gauche : %f\n",IrectG);
		IrectD=integraleRectangleD(a,b,i);
		printf("Méthodes des rectangles droite : %f\n",IrectD);
		Itrap=integraleTrapeze(a,b,i);
		printf("Méthodes des trapèzes : %f\n",Itrap);
	}
}


void afficherCalculs2(float a, float b, int n){
	float ISimp, ITrap;
	int k;
	//saisirLimites(a,b);
	//saisirIntervalles(n);
	for (int i=2;i<n+1;i++){
		cout << "\n==> " << i << "*2 sous-intervalles" << endl;
		k=2*i;
		ITrap=integraleTrapeze(a,b,k);
		printf("Méthodes des trapèzes : %f\n",ITrap);
		ISimp=integraleSimpson(a,b,i);
		printf("Méthodes de Simpson : %f\n",ISimp);
	}
}

void afficherCalculs3(float a, float b, int n){
	float Iexact, IrectG, IrectD, Itrap;
	//saisirLimites(a,b);
	//saisirIntervalles(n);
	Iexact=test_exacte(a,b);
	printf("\nMéthode extacte: %f\n",Iexact);
	IrectG=integraleRectangleG(a,b,n);
	printf("Méthodes des rectangles gauche : %f\n",IrectG);
	IrectD=integraleRectangleD(a,b,n);
	printf("Méthodes des rectangles droite : %f\n",IrectD);
	Itrap=integraleTrapeze(a,b,n);
	printf("Méthodes des trapèzes : %f\n",Itrap);
}

void afficherIntervallesT(float a,float b,int& iter){
	float epsilon0(0.1), epsilon, Itrap, Iexact;
	int n;
	cout << "Combien d'iterations ?";
	cin >> iter;
	for (int i(0);i<iter;i++){
		epsilon=epsilon0*pow(0.5,i);
		n=nitersTrapeze(a,b,epsilon,Itrap);
		cout << "Trapèze : " << Itrap << " en " << n << " intervalles (" << epsilon << ")" << endl;
	}
	Iexact=integraleExacte(a,b);
	cout << "Exact = " << Iexact;
}

void afficherIntervallesS(float a,float b,int& iter){
	float epsilon0(0.1), epsilon, ISimp, Iexact;
	int n;
	cout << "Combien d'iterations ?";
	cin >> iter;
	for (int i(0);i<iter;i++){
		epsilon=epsilon0*pow(0.5,i);
		n=nitersSimpson(a,b,epsilon,ISimp);
		cout << "Simpson : " << ISimp << " en " << n << " intervalles (" << epsilon << ")" << endl;
	}
	Iexact=integraleExacte(a,b);
	cout << "Exact = " << Iexact;
}

void afficherIntervalles(float a,float b,int& iter){
	float epsilon0(0.1), epsilon, Itrap, ISimp, Iexact;
	int n1, n2;
	cout << "Combien d'iterations ?";
	cin >> iter;
	for (int i(0);i<iter;i++){
		epsilon=epsilon0*pow(0.5,i);
		n1=nitersTrapeze(a,b,epsilon,Itrap);
		n2=nitersSimpson(a,b,epsilon,ISimp);
		cout << "\n==> precision : " << epsilon << endl;
		cout << "Trapeze : " << Itrap << " en " << n1 << " intervalles" << endl;
		cout << "Simpson : " << ISimp << " en " << n2 << " intervalles" << endl;
	}
	Iexact=integraleExacte(a,b);
	cout << "Exact = " << Iexact;
}

/* Convergence */

int nitersTrapeze(float a, float b, float epsilon, float& integr){
	int n(1);
	float delta(epsilon+1);
	while (delta>= epsilon){
		delta=abs(integraleTrapeze(a,b,n+1)-integraleTrapeze(a,b,n));
		n++;
	}
	integr=integraleTrapeze(a,b,n);
	//printf("Méthodes des Trapèzes : %f\n",integr);
	//printf("Nombre d'itérations : %i\n",n);
	return(n);
}

int nitersSimpson(float a, float b, float epsilon, float& integr){
	int n(1);
	float delta(epsilon+1);
	while (delta>= epsilon){
		delta=abs(integraleSimpson(a,b,n+1)-integraleSimpson(a,b,n));
		n++;
	}
	n*=2;
	integr=integraleSimpson(a,b,n);
	//printf("Méthodes des Trapèzes : %f\n",integr);
	//printf("Nombre d'itérations : %i\n",n);
	return(n);
}

