#include "header.h"

void print_data(FILE* schueler) {
	printf("ID | Name  Nachname | Semester | Note\n");
	for (int i = 0; i < max; i++) {
		if (fscanf(schueler, "%d, %[^,], %[^,], %d, %f", &student[i].id1, student[i].name, student[i].nachname,&student[i].semester, &student[i].average) == 5) {
			printf("%d, %s %s, %d, %f\n", student[i].id1, student[i].name, student[i].nachname, student[i].semester, student[i].average);
		}
	}

}


//shows current arrayss ( for testing) later on i want to chose in which array i want to look into
//add search function for detailed info of a student with open scanf and if == 0tahn exit option/searchfunction
void print_array() {
	printf("\n");
	printf("schueler.csv\n");
	printf("------------\n");
	printf("ID  | Name Nachname                                              | Semester | Durschnittsnote\n\n");
	printf("----|------------------------------------------------------------|----------|--------------------\n");
	
	for (int i = 0; i < max; i++) {
		if (student[i].id1 != 0) {
			char displayname[60];
			strcpy(displayname, student[i].name);
			strcat(displayname, " ");
			strcat(displayname, student[i].nachname);
			printf("%-4d| %-59s|     %d    | %f\n", student[i].id1, displayname, student[i].semester, student[i].average);


		}
	}
	printf("----------------------------------------------------------------------------------------------\n");
	printf("noten.csv\n");
	printf("------------\n");
	printf("ID  | Fach 1 | Fach 2 | Fach 3 | Fach 4 | Fach 5\n\n");
	for (int i = 0; i < max; i++) {
		if (grades[i].id2 != 0) {
			printf("%d|   %d    |   %d    |   %d    |   %d    |   %d \n", grades[i].id2, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);
		}
	}
	printf("----------------------------------------------------------------------------------------------\n");
	printf("\n");
}		