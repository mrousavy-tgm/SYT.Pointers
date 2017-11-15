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
}
