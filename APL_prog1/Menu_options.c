#include "header.h"



//function to select menu optins

int menu_value() {

	int option_value;


	printf("\n--------Optionen--------\n");
	printf("1: Neuen Schueler Hinzufuegen\n");	//adds new student in schueler.csv and noten.csv
	printf("2: Schuelerdaten bearbeiten\n");	//edit Schueler in s.csv und n.csv
	printf("3: Schuelerdaten loeschen\n");		//Delets student in both Files
	printf("4: Schuelerdaten anzeigen\n");		//more info abt the student -> shows data from both Files
	printf("5: Speichern und beenden\n");		// save and exit 

	
	
	

	//Option error
	while (1) {
		printf("Option auswaehlen:\t");
		if (scanf("%d", &option_value) == 0) {
			scanf("%*s"); // "Frisst" das ungültige Zeichen/Wort einfach auf
			option_value = 9; // Setze es auf 9, damit das Programm "ungültig" sagt
			break;
		}
		else if (option_value > 0 && option_value < 6) {
			break;
		}
		else {
			option_value = 9;
			break;
		}
	}
	
	return option_value;
}






//Function to let add new students
//Option: 1

void add_student() {


	int id_generator;
	bool id_unique;


	//check if id is not alr used
	do {
		id_generator = (rand() % 9000) + 1000;
		id_unique = true;

		for (int x = 0; x < max; x++) {
			if (student[x].id1 == id_generator) {
				id_unique = false;
				break;
			}
		}
	} while (!id_unique);



	int id_buffer=0;

	//adds new student to student array
	for (int i = 0; i < max; i++) {
		if (student[i].id1 == 0) {
			student[i].id1 = id_generator;
			printf("Neuer Schueler wird hinzugefuegt:\n");
			printf("Name:\t");
			scanf(" %29s", student[i].name);
			printf("Nachname:\t");
			scanf(" %29s", student[i].nachname);
			
			student[i].semester = check_datatype("In welchen Semester ist der Student gerade ? :\t");
			id_buffer = student[i].id1;
			break;
		}
		if (i == max - 1) {
			printf("No more slots available");
			return;
		}
	}
	char input;

	//adds new grades to grades array
	printf("Fachnoten eintratgen? [y]es/[n]o\n");
	scanf(" %c", &input);
	if (input == 'y') {
		for (int j = 0; j < max; j++) {
			if (grades[j].id2 == 0) {
				grades[j].id2 = id_buffer;
				printf("Neue Fachnoten eintragen:\n");
				grades[j].fach1 = check_datatype("Fachnote 1:\t");
				if (grades[j].fach1 < 1 || grades[j].fach1 >6) {
					grades[j].fach1 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
				}
				grades[j].fach2 = check_datatype("Fachnote 2:\t");
				if (grades[j].fach2 < 1 || grades[j].fach2 >6) {
					grades[j].fach2 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
				}
				grades[j].fach3 = check_datatype("Fachnote 3:\t");
				if (grades[j].fach3 < 1 || grades[j].fach3 >6) {
					grades[j].fach3 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
				}
				grades[j].fach4 = check_datatype("Fachnote 4:\t");
				if (grades[j].fach4 < 1 || grades[j].fach4 >6) {
					grades[j].fach4 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
				}
				grades[j].fach5 = check_datatype("Fachnote 5:\t");
				if (grades[j].fach5 < 1 || grades[j].fach5 >6) {
					grades[j].fach5= check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
				}
				break;
			}
			if (j == max - 1) {
				printf("No more slots available");
				return;
			}
		}
	}
	else if (input=='n') {
		for (int k = 0; k< max; k++) {
			if (grades[k].id2 == 0) {
				grades[k].id2 = id_buffer;
				grades[k].fach1 = 0;
				grades[k].fach2 = 0;
				grades[k].fach3 = 0;
				grades[k].fach4 = 0;
				grades[k].fach5 = 0;
				break;
			}
		}
	}
	else {
		printf("Eingabe ungueltig.\nFachnoten werden 0 gesetzt.\nIm Menu aenderbar.\n\n");
		for (int k = 0; k < max; k++) {
			if (grades[k].id2 == 0) {
				grades[k].id2 = id_buffer;
				grades[k].fach1 = 0;
				grades[k].fach2 = 0;
				grades[k].fach3 = 0;
				grades[k].fach4 = 0;
				grades[k].fach5 = 0;
				break;
			}
		}
	}
}

//edits students info 
//Option: 2
void edit_student() {



	print_array();

	
	

	int loop = 1;

	while (loop == 1) {
		int id_edit;
		char edit_type;
		printf("[s]chueler oder [n]oten bearbeiten. Beliebige Taste drücken um ins Menu zurueck zu kehren.\n");
		scanf(" %c", &edit_type);


		if (edit_type == 's') {
			id_edit = check_datatype("Welche ID möchten sie bearbeiten?\n");
			int found = 0;
			for (int i = 0; i < max; i++) {
				if (id_edit == student[i].id1) {
					printf("Neuen Namen eingeben:\n");
					scanf(" %29s", &student[i].name);
					printf("Neuen Nachnamen eingeben:\n");
					scanf(" %29s", &student[i].nachname);
					student[i].semester = check_datatype("In welchen Semester ist der Student gerade ? :\t");
					found = 1;
					break;
				}
				else if (found == 0) {
					printf("ID nicht gefunden.\n");
					break;
				}
			}
		}
		else if (edit_type == 'n') {
			id_edit = check_datatype("Welche ID möchten sie bearbeiten?\n");
			int found = 0;
			for (int j = 0; j < max; j++) {
				if (id_edit == student[j].id1) {
					printf("Neue Fachnoten eintragen:\n");
					grades[j].fach1 = check_datatype("Fachnote 1:\t");
					if (grades[j].fach1 < 1 || grades[j].fach1 >6) {
						grades[j].fach1 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
					}
					grades[j].fach2 = check_datatype("Fachnote 2:\t");
					if (grades[j].fach2 < 1 || grades[j].fach2 >6) {
						grades[j].fach2 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
					}
					grades[j].fach3 = check_datatype("Fachnote 3:\t");
					if (grades[j].fach3 < 1 || grades[j].fach3 >6) {
						grades[j].fach3 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
					}
					grades[j].fach4 = check_datatype("Fachnote 4:\t");
					if (grades[j].fach4 < 1 || grades[j].fach4 >6) {
						grades[j].fach4 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
					}
					grades[j].fach5 = check_datatype("Fachnote 5:\t");
					if (grades[j].fach5 < 1 || grades[j].fach5 >6) {
						grades[j].fach5 = check_datatype("Bitte geben sie eine Note zwichen 1 und 6 an:\t");
					}
					found = 1;
					break;
				}
				else if (found == 0) {
					printf("ID nicht gefunden.\n");
					break;
				}
			}
		}
		else {
			loop = 0;
			break;
		}
	}
}




//deletes student
//Option:3
void delete_id() {
	print_array();
	int del_id;

	del_id = check_datatype("Weclhe ID möchten sie loeschen?\n");
	int found = 0;


	for (int i = 0; i < max; i++) {
		if (student[i].id1 == del_id) {
			student[i].id1 = 0;
			strcpy(student[i].name, ""); // sets name to a empty string
			strcpy(student[i].nachname, "");
			student[i].semester = 0;
			student[i].average = 0;
			grades[i].id2 = 0;
			grades[i].fach1 = 0;
			grades[i].fach2 = 0;
			grades[i].fach3 = 0;
			grades[i].fach4 = 0;
			grades[i].fach5 = 0;
			found = 1;
			for (int j = i; j < max - 1; j++) {
				student[j] = student[j + 1];
				grades[j] = grades[j + 1];
			}
			// deletes last slot of array because deleted info are just at the end
			student[max - 1].id1 = 0;
			strcpy(student[max - 1].name, "");
			strcpy(student[max - 1].nachname, "");
			student[max - 1].semester = 0;
			student[max - 1].average = 0;

			grades[max - 1].id2 = 0;
			grades[max - 1].fach1 = 0;
			break;
		}
	}
	if (found == 0) {
		printf("Id %d wurde nicht gefunden\n", del_id);
	}
}


 
//shows info of student
//Option:4
void find_id() {
	int loop1 = 1;
	char find_id;
	int search_id;
	int found = 0;

	while (loop1 = 1) {
		printf("Fachnoten des Schuelers einsehen? [y]es/[n]o\t");
		scanf(" %c", &find_id);
		if (find_id == 'y') {
			search_id = check_datatype("ID eingeben:\t");
			printf("------------\n");
			for (int i = 0; i < max; i++) {
				if (grades[i].id2 == search_id) {
					char name[60];
					for (int k = 0; k < max; k++) {
						if (student[k].id1 == search_id) {
							char displayname[60];
							strcpy(displayname, student[k].name);
							strcat(displayname, " ");
							strcat(displayname, student[k].nachname);
							strcpy(name, displayname);
							break;
						}
					}
					printf("ID: %d\n%s\nFach1: %d\nFach2: %d\nFach3: %d\nFach4: %d\nFach5: %d\n\n", grades[i].id2,name, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);
					found = 1;
					break;
				}	
			}
			if (found == 0) {
				printf("ID %d konnte nicht gefunden werden.\n", search_id);
			}
		}
		
		else if (find_id == 'n') {
			break;
		}
		else {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			 continue;
		}
	}

}


//Save and Exit Application
//Option:5
void save_exit(FILE* schueler, FILE* noten) {


	//all students with id !=0 are not printed on to the File
	for (int i = 0; i < max; i++) {
		if (student[i].id1 == 0) {
			continue;
		}
		else {
			fprintf(schueler, "%d, %s, %s, %d, %f\n", student[i].id1, student[i].name, student[i].nachname, student[i].semester, student[i].average);
		}
	}

	for (int i = 0; i < max; i++) {
		if (grades[i].id2 == 0) {
			continue;
		}
		else {
			fprintf(noten, "%d, %d, %d, %d, %d, %d\n", grades[i].id2, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);
		}
	}
	printf("-Erfolgreich gespeichert-");
	return ;
}






