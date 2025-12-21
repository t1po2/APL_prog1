#include "header.h"

void print_data(FILE* schueler) {
	printf("ID | Name  Nachname | Semester | Note\n");
	for (int i = 0; i < max; i++) {
		if (fscanf(schueler, "%d, %[^,], %[^,], %d, %f", &student[i].id1, student[i].name, student[i].nachname,&student[i].semester, &student[i].average) == 4) {
			printf("%d, %s %s, %d, %f\n", student[i].id1, student[i].name, student[i].nachname, student[i].semester, student[i].average);
		}
	}

}