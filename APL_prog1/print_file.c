#include "header.h"

void print_data(FILE* schueler) {
	printf("ID | Name  Nachname | Note\n");
	for (int i = 0; i < max; i++) {
		if (fscanf(schueler, "%d, %[^,], %[^,], %d", &student[i].id1, student[i].name, student[i].nachname, &student[i].average) == 4) {
			printf("%d, %s %s, %d\n", student[i].id1, student[i].name, student[i].nachname, student[i].average);
		}
	}

}