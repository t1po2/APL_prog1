#include "header.h"



int main() {

	//opens csv file in read mode 
	FILE* schueler = fopen("schueler.csv", "r");
	FILE* noten = fopen("noten.csv", "r");

	//function checks if the file exists, if not a new file will be created
	if (check_file(schueler, noten) == 1) {
		printf("Keine Datei vorhanden.\nDie Datei schueler.csv und noten.csv wird erstellt.\n");
	}
	else {
		print_data(schueler);
	}

	
	//which Menu Option is selected
	
	printf("%d\n", menu_value());
	/*while (1) {
		if (menu_value() == 1) {

		}
	}*/
	


	fclose(schueler);
	fclose(noten);
	return 0;
}