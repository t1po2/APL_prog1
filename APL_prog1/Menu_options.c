#include "header.h"



//function to select menu optins

int menu_value() {

	int option_value;


	printf("--------Optionen--------\n");
	printf("1: Neuen Schueler Hinzufuegen\n");	//adds new student in schueler.csv and noten.csv
	printf("2: Schuelerdaten bearbeiten\n");	//edit Schueler in s.csv und n.csv
	printf("3: Schuelerdaten loeschen\n");		//Delets student in both Files
	printf("4: Schuelerdaten öffnen\n");		//more info abt the student -> shows data from both Files
	printf("5: Speichern und beenden\n");		// save and exit 

	
	


	//Option error
	while (1) {
		printf("Option auswaehlen:\t");
		scanf("%d", &option_value);
		if (option_value > 0 && option_value < 6) {
			break;
		}
		else {
			printf("Auswahloption nicht vorhanden\n");
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



	int id_buffer;


	for (int i = 0; i < max; i++) {
		if (student[i].id1 == 0) {
			student[i].id1 = id_generator;
			printf("Name:\t");
			scanf("%29s", student[i].name);
			printf("Nachname:\t");
			scanf("%29s", student[i].nachname);
			id_buffer = student[i].id1;
			break;
		}
		if (i == max - 1) {
			printf("No more slots available");
			return;
		}
	}
	char input;

	printf("Fachnoten eintratgen? [y]es/[n]o");
	scanf(" %c", &input);
	if (input == 'y') {
		for (int j = 0; j < max; j++) {
			if (grades[j].id2 == 0) {
				grades[j].id2 = id_buffer;
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
}







