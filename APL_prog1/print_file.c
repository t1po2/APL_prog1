#include "header.h"

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
			printf("%-4d| %-59s|     %d    | %.2f\n", student[i].id1, displayname, student[i].semester, student[i].average);
		}
	}
}
