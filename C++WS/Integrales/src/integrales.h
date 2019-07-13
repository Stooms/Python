/*
 * integrales.h
 *
 *  Created on: 7 juil. 2019
 *      Author: stan
 */

#ifndef INTEGRALES_H_
#define INTEGRALES_H_

float fonction(float x);
float primF(float x);
float integraleExacte(float a, float b);
void saisirLimites(float &a, float &b);
int saisirIntervalles(int& n);
float test_exacte(float a, float b);
float integraleRectangleG(float a, float b, int n);
float integraleRectangleD(float a, float b, int n);
float integraleTrapeze(float a, float b, int n);
float integraleSimpson(float a, float b, int n);
void afficherCalculs(float a, float b, int n);
void afficherCalculs2(float a, float b, int n);
void afficherCalculs3(float a, float b, int n);
int nitersTrapeze(float a, float b, float epsilon, float& integr);
int nitersSimpson(float a, float b, float epsilon, float& integr);
void afficherIntervallesS(float a,float b,int& iter);
void afficherIntervallesT(float a,float b,int& n);
void afficherIntervalles(float a,float b,int& n);

#endif /* INTEGRALES_H_ */
