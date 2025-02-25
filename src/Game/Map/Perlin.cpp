/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Perlin
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>

const double pi = 3.14159265;

static int pas1D = 0;
static int nombre_octaves1D = 0;
static int taille = 0;
static double* valeurs1D;

static int pas2D = 0;
static int nombre_octaves2D = 0;
static int hauteur = 0;
static int longueur = 0;
static int longueur_max = 0;
static double* valeurs2D;

void initBruit1D(int t, int p, int n) {
    nombre_octaves1D = n;
    if(taille != 0)
        free(valeurs1D);
    taille = t;
    pas1D = p;

    valeurs1D = (double*) malloc(sizeof(double) * (int) ceil(taille * pow(2, nombre_octaves1D  - 1)  / pas1D));

    srand(time(NULL));
    int i;
    for(i = 0; i < ceil(taille *  pow(2, nombre_octaves1D  - 1)  / pas1D); i++)
        valeurs1D[i] = (double) rand() / RAND_MAX;
}

void destroyBruit1D() {
    if(taille != 0)
        free(valeurs1D);
    taille = 0;
}

static double bruit1D(int i) {
    return valeurs1D[i];
}

static double interpolation_cos1D(double a, double b, double x) {
   double k = (1 - cos(x * pi)) / 2;
    return a * (1 - k) + b * k;
}

static double fonction_bruit1D(double x) {
   int i = (int) (x / pas1D);
   return interpolation_cos1D(bruit1D(i), bruit1D(i + 1), fmod(x / pas1D, 1));
}


double bruit_coherent1D(double x, double persistance) {
    double somme = 0;
    double p = 1;
    int f = 1;
    int i;

    for(i = 0 ; i < nombre_octaves1D ; i++) {
        somme += p * fonction_bruit1D(x * f);
        p *= persistance;
        f *= 2;
    }
    return somme * (1 - persistance) / (1 - p);
}

void initBruit2D(int l, int h, int p, int n) {
    nombre_octaves2D = n;
    if(taille != 0)
        free(valeurs2D);
    longueur = l;
    hauteur = h;
    pas2D = p;
    longueur_max = (int) ceil(longueur * pow(2, nombre_octaves2D  - 1)  / pas2D);
    int hauteur_max = (int) ceil(hauteur * pow(2, nombre_octaves2D  - 1)  / pas2D);

    valeurs2D = (double*) malloc(sizeof(double) * longueur_max * hauteur_max);

    srand(time(NULL));
    int i;
    for(i = 0; i < longueur_max * hauteur_max; i++)
        valeurs2D[i] = ((double) rand()) / RAND_MAX;
}

void destroyBruit2D() {
    if(longueur != 0)
        free(valeurs2D);
    longueur = 0;
}

static double bruit2D(int i, int j) {
    return valeurs2D[i * longueur_max + j];
}

static double interpolation_cos2D(double a, double b, double c, double d, double x, double y) {
   double y1 = interpolation_cos1D(a, b, x);
   double y2 = interpolation_cos1D(c, d, x);
   return  interpolation_cos1D(y1, y2, y);
}

static double fonction_bruit2D(double x, double y) {
   int i = (int) (x / pas2D);
   int j = (int) (y / pas2D);
   return interpolation_cos2D(bruit2D(i, j), bruit2D(i + 1, j), bruit2D(i, j + 1), bruit2D(i + 1, j + 1), fmod(x / pas2D, 1), fmod(y / pas2D, 1));
}

double bruit_coherent2D(double x, double y, double persistance) {
    double somme = 0;
    double p = 1;
    int f = 1;
    int i;

    for(i = 0 ; i < nombre_octaves2D ; i++) {
        somme += p * fonction_bruit2D(x * f, y * f);
        p *= persistance;
        f *= 2;
    }
    return somme * (1 - persistance) / (1 - p);
}