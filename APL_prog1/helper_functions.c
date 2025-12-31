#include "header.h"

//shows lsit of data of students and grades
//additional Function for Option 3
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
			printf("\n");
		}
	}
}


//additional Function to calculate average Grade for a student
void calc_grade() {


	for (int i = 0; i < max; i++) {
		if (student[i].id1 == 0) {
			continue;
		}
		int teiler = 5;
		for (int j = 0; j < max; j++) {
			if (student[i].id1 == grades[j].id2) {
				if (grades[j].fach1 == 0) teiler--;
				if (grades[j].fach2 == 0) teiler--;
				if (grades[j].fach3 == 0) teiler--;
				if (grades[j].fach4 == 0) teiler--;
				if (grades[j].fach5 == 0) teiler--;

				if (teiler > 0) {
					student[i].average = (grades[j].fach1 + grades[j].fach2 + grades[j].fach3 +
						grades[j].fach4 + grades[j].fach5) / (float)teiler;
				}
				else {
					student[i].average = 0.0;
				}
				break;

			}
		}
	}
}




void sort_students_by_name() {
	//temporaray place to hold the string  to sort
	t_schueler_generalinfo temp_s;
	t_fachnoten temp_g;

	//comparrison of 2 names
	for (int i = 0; i < max - 1; i++) {
		for (int j = 0; j < max - i - 1; j++) {

			//strcmp compare Charackters
			if (strcmp(student[j].name, student[j + 1].name) > 0) {

				// --- GANZE DATENREIHE TAUSCHEN ---

				//sorting
				temp_s = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp_s;

			}
		}
	}
}