#include "header.h"

int menu_value() {

	int option_value;


	printf("--------Optionen--------\n");
	printf("1: Neuen Schueler Hinzufuegen\n");	//adds new student in schueler.csv and noten.csv
	printf("2: Schuelerdaten bearbeiten\n");		//edit Schueler in s.csv und n.csv
	printf("3: Schuelerdaten loeschen\n");		//Delets student in both Files
	printf("4: Schuelerdaten öffnen\n");			//more info abt the student -> shows data from both Files
	printf("5: Speichern und beenden\n");			// save and exit 

	
	


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

