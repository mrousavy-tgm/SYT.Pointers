#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// Berechne das Volumen eines Kegels
void kegel(double radius, double hoehe, double* out_volumen, double* out_oberflaeche) {
	*out_volumen = (1.0/3.0) * M_PI * (radius * radius) * hoehe;
	double s1 = hoehe * hoehe + radius * radius;
	double s = sqrt(s1);
	*out_oberflaeche = (M_PI * radius * s) + (M_PI * (radius * radius));
}

// Berechne 6 zufällige Lotto zahlen (zwischen 1 und 45)
void lottoTip(int* out_1, int* out_2, int* out_3, int* out_4, int* out_5, int* out_6) {
	*out_1 = (double)rand() / RAND_MAX * 45;
	*out_2 = (double)rand() / RAND_MAX * 45;
	*out_3 = (double)rand() / RAND_MAX * 45;
	*out_4 = (double)rand() / RAND_MAX * 45;
	*out_5 = (double)rand() / RAND_MAX * 45;
	*out_6 = (double)rand() / RAND_MAX * 45;
}

// Vergleiche Zahlen miteinander
int istGleich(int z, int z1, int z2, int z3, int z4, int z5, int z6) {
    return z == z1;     // Angabe unklar!!!
}

// Print kegel info
void printKegel(double radius, double hoehe) {
    double* volumen, oberflaeche;
    kegel(radius, hoehe, &volumen, &oberflaeche);
    printf("Kegel Volumen: %f, Oberfläche: %f\n", volumen, oberflaeche);
}

// Erzeugt einen Lotto Tip und printed ihn auf der Konsole
void printLottoTip() {
    int* z1, z2, z3, z4, z5, z6;
    lottoTip(&z1, &z2, &z3, &z4, &z5, &z6);
    printf("Lotto tips: %i, %i, %i, %i, %i, %i\n", z1, z2, z3, z4, z5, z6);
}

// Print Kegel 30 mal
void printKegelListe() {
    for(int i = 0; i < 30; i++)
        printKegel((int)((double)rand() / RAND_MAX * 100), (int)((double)rand() / RAND_MAX * 100));
}

// Kegel read & calc
void kegelEinlesenUndBerechnen() {
    printf("Bitte geben Sie radius ein: ");
    int radius = getchar() - '0';
    printf("\n");
    getchar();
    printf("Bitte geben Sie höhe ein: ");
    int hoehe = getchar() - '0';
    printf("\n");
    printKegel(radius, hoehe);
}

// 30 lotto tips
void printLottoTips() {
    for(int i = 0; i < 30; i++)
        printLottoTip();
}

// Main func
int main(void) {
	srand(time(0));
	printf("Arbeiten mit Pointer:\n");
	double* volumen = (double*)malloc(sizeof(double));
	double* oberflaeche = (double*)malloc(sizeof(double));
	kegel(5, 10, volumen, oberflaeche);
	printf("Volumen: %f | Oberfläche %f\n", *volumen, *oberflaeche);
	
	int* rnd_1 = (int*)malloc(sizeof(int));
	int* rnd_2 = (int*)malloc(sizeof(int));
	int* rnd_3 = (int*)malloc(sizeof(int));
	int* rnd_4 = (int*)malloc(sizeof(int));
	int* rnd_5 = (int*)malloc(sizeof(int));
	int* rnd_6 = (int*)malloc(sizeof(int));
	lottoTip(rnd_1, rnd_2, rnd_3, rnd_4, rnd_5, rnd_6);
	printf("1: %i, 2: %i, 3: %i, 4: %i, 5: %i, 6: %i\n", *rnd_1, *rnd_2, *rnd_3, *rnd_4, *rnd_5, *rnd_6);
    printLottoTip();
    printKegel(5, 10);
    printKegelListe();
    printLottoTips();
    kegelEinlesenUndBerechnen();
}
