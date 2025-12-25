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
			printf("In welchen Semester ist der Student gerade?:\t");
			scanf(" %d", &student[i].semester);
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
				printf("Fachnote 1:\t");
				scanf("%d", &grades[j].fach1);
				printf("Fachnote 2:\t");
				scanf("%d", &grades[j].fach2);
				printf("Fachnote 3:\t");
				scanf("%d", &grades[j].fach3);
				printf("Fachnote 4:\t");
				scanf("%d", &grades[j].fach4);
				printf("Fachnote 5:\t");
				scanf("%d", &grades[j].fach5);
				break;
			}
			if (j == max - 1) {
				printf("No more slots available");
				return;
			}
		}
	}
	else {
		for (int j = 0; j < max; j++) {
			if (grades[j].id2 ==0) {
				grades[j].id2 = id_buffer;
				grades[j].fach1 = 0;
				grades[j].fach2 = 0;
				grades[j].fach3 = 0;
				grades[j].fach4 = 0;
				grades[j].fach5 = 0;
				break;
			}
		}
	}
}

//edits student llr in the lsit
void edit_student() {



	print_array();

	int id_edit;
	char data_type;
	printf("[s]chueler oder [n]oten bearbeiten\n");
	scanf(" %c", &data_type);
	char edit_name;





	if (data_type == 's') {
		printf("Welche ID möchten sie bearbeiten?\n");
		scanf("%d", &id_edit);
		for (int i = 0; i < max; i++) {
			if (id_edit == student[i].id1) {
				printf("namen aendern? [y]es/[n]o\t");
				scanf(" %c", &edit_name);
				if (edit_name == 'y') {
					printf("Neuen Namen eingeben:\n");
					scanf(" %29s", &student[i].name);
					printf("Neuen Nachnamen eingeben:\n");
					scanf(" %29s", &student[i].nachname);
				}
				printf("In welchem Semester ist der Student gerade?\n");
				scanf("%d", &student[i].semester);
				break;
			}
			else {
				printf("ID nicht gefunden.\n");
			}
		}
	}
	else if (data_type == 'n') {
		printf("Welche ID möchten sie bearbeiten?\n");
		scanf("%d", &id_edit);
		for (int i = 0; i < max; i++) {
			if (id_edit == student[i].id1) {
				printf("Note für Fach 1 eingeben:\t");
				scanf("%d", &grades[i].fach1);
				printf("Note für Fach 2 eingeben:\t");
				scanf("%d", &grades[i].fach2);
				printf("Note für Fach 3 eingeben:\t");
				scanf("%d", &grades[i].fach3);
				printf("Note für Fach 4 eingeben:\t");
				scanf("%d", &grades[i].fach4);
				printf("Note für Fach 5 eingeben:\t");
				scanf("%d", &grades[i].fach5);
				break;
			}
			else {
				printf("ID nicht gefunden.\n");
			}
		}
	}
	else {
		printf("Eingabe ungülttig.\n");
	}
}




//deletes student
void delete_id() {
	print_array();
	int del_id;

	printf("Weclhe ID möchten sie loeschen?\n");
	scanf(" %d", &del_id);
	int found = 0;
	for (int i = 0; i < max; i++) {
		if (student[i].id1 == del_id) {
			student[i].id1 = 0;
			strcpy(student[i].name, ""); // Name auf leeren String setzen
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
			break;
		}
	}
	if (found == 0) {
		printf("Id %d wurde nicht gefunden\n", del_id);
	}
}


//Menuoption 4 shows info of student
void find_id() {
	int loop1 = 1;
	char find_id;
	int search_id;
	int found = 0;

	while (loop1 = 1) {
		printf("Fachnoten des Schuelers einsehen? [y]es/[n]o\t");
		scanf(" %c", &find_id);
		if (find_id == 'y') {
			printf("Geben sie die ID ein:\t");
			scanf(" %d", &search_id);
			printf("------------\n");
			for (int i = 0; i < max; i++) {
				if (grades[i].id2 == search_id) {
					printf("ID: %d\nFach1: %d\nFach2: %d\nFach3: %d\nFach4: %d\nFach5: %d\n", grades[i].id2, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);
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
			continue;
		}
	}

}


//Save and Exit Application
void save_exit(FILE* schueler, FILE* noten) {
	schueler = fopen("schueler.csv", "w");
	noten = fopen("noten.csv", "w");

	for (int i = 0; i < max; i++) {
		if (student[i].id1 != 0) {
			fprintf(schueler, "%d, %s, %s, %d, %f\n", student[i].id1, student[i].name, student[i].nachname, student[i].semester, student[i].average);
		}
	}

	for (int i = 0; i < max; i++) {
		if (grades[i].id2 != 0) {
			fprintf(noten, "%d, %d, %d, %d, %d, %d\n", grades[i].id2, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);

		}
	}
}








