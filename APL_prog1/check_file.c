#include "header.h"



//this function checks if file alr exists, if not than a new one will be created
int check_file(FILE* schueler, FILE* noten) {
	if (schueler == NULL) {
		schueler = fopen("schueler.csv", "w");
		noten = fopen("noten.csv", "w");
		return 1;
	}
	else {
		// Daten einlesen am besten ist wenn schueler eingelesen wrd und dnann die ID auf schueler.csv mit ID auf noten.csv verglichen wird und dann dazu eine ein datens atz erzeugt wird wenn nichts vorhanden ist
	}
	return 0;
}

