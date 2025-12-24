#include "header.h"



//this function checks if file alr exists, if not than a new one will be created
int check_file(FILE* schueler, FILE* noten) {
	if (schueler == NULL) {
		schueler = fopen("schueler.csv", "w");
		noten = fopen("noten.csv", "w");
		return 1;
	}
	else {
		for (int i = 0; i < max; i++) {
			fscanf(schueler, "%d, %[^,], %[^,], %d, %f", &student[i].id1, student[i].name, student[i].nachname, &student[i].semester, &student[i].average);
			fscanf(noten, "%d, %d, %d, %d, %d, %d", grades[i].id2, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);
			return 2;
		}
	}

}

