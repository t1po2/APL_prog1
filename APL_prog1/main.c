#include "header.h"



int main() {
	srand(time(NULL));

	//opens csv file in read mode 
	FILE* schueler = fopen("schueler.csv", "r");
	FILE* noten = fopen("noten.csv", "r");

	//function checks if the file exists, if not a new file will be created
	if (check_file(schueler, noten) == 1) {
		printf("Keine Datei vorhanden.\nDie Datei schueler.csv und noten.csv wird erstellt.\n");
	}
	else {
		printf("Dateien wurden geladen.\n");
	}


	
	//which Menu Option is selected
	

	int mvalue;
	
	while (1) {
		mvalue = menu_value();
		printf("\nOption: %d wurde ausgewaehlt\n", mvalue);
		printf("\n\n");
		if (mvalue == 1) {
			add_student();
		}
		else if (mvalue == 2) {
			edit_student();
		}
		else if (mvalue == 3) {
			delete();
		}
		else if (mvalue == 4) {
			print_array();
		}
		else if (mvalue == 5) {
			break; //edit it back to break jsut for testing reasons
		}
		else {
			printf("Auswahl ungültig");
		}

	}








	//test print
	
	

	fclose(schueler);
	fclose(noten);
	return 0;
}