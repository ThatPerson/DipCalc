#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "isotopes.c"

float calc_dipolar(struct Isotope A, struct Isotope B, float bl) {
	// bond length in Angstroms
	float h = 6626;
	return (A.gamma * B.gamma * h) / (pow(bl,3) * 4 * pow(M_PI,2));
}

float calc_distance(struct Isotope A, struct Isotope B, float D) {
	// bond length in Angstroms
	float h = 6626;
	return pow((A.gamma * B.gamma * h) / (4 * pow(M_PI, 2) * D), 1/3.);
	//return (A.gamma * B.gamma * h) / (pow(bl,3) * 4 * pow(M_PI,2));
}

struct Isotope get_isotope(int number, char name[8]) {
	int i;
	for (i = 0; i < 127; i++) {
		if (number == isotopes[i].number && strcmp(name, isotopes[i].name) == 0) {
			return isotopes[i];
		}
	}
	return isotopes[0];
}

int main(int argc, char *argv[]) {
	struct Isotope A,B;
	if (argc < 4) {
		printf("Please pass args");
		return -1;
	}
	int mode = -1;
	if (argc == 5)
		mode = (strcmp(argv[4], "d") == 0)?0:1; 
	
	
	int tmp;
	char tmpC[8];
	sscanf(argv[1], "%d%s", &tmp, tmpC);
	A = get_isotope(tmp, tmpC);
	sscanf(argv[2], "%d%s", &tmp, tmpC);
	B = get_isotope(tmp, tmpC);
	float val = atof(argv[3]);
	if (mode == -1) {
		if (val > 100) {
			// presumably a dipolar coupling; calc_length unless
			mode = 0;
		} else {
			mode = 1;
		}
	}
	
	float dist, dipo;
	if (mode == 0) {
		dist = calc_distance(A, B, val);
		printf("Bond Length: %0.2f A\n", dist);
	} else if (mode == 1) {
		dipo = calc_dipolar(A, B, val);
		printf("Dipolar Coupling: %0.2f Hz\n", dipo);
	}
	return 1;
}
	
