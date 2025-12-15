#include "header.h"



//this function checks if file alr exists, if not than a new one will be created
int check_file(FILE* schueler, FILE* noten) {
	if (schueler == NULL) {
		schueler = fopen("schueler.csv", "w");
		noten = fopen("noten.csv", "w");
		return 1;
	}
	return 0;
}
