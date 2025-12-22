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
		mvalue =  menu_value();
		if (mvalue == 1) {
			add_student();
		}
		else if (mvalue == 5) {
			continue; //edit it back to break jsut for testing reasons
		}
	}










	//test print
	
	for (int i=0; i < max; i++) {
		if (student[i].id1 != 0) {
			if (grades[i].id2 != 0) {
				printf("schueler.csv\n");
				printf("%d | %s %s \n", student[i].id1, student[i].name, student[i].nachname);
				printf("noten.csv\n");
				printf("%d | %d | %d | %d | %d | %d\n", grades[i].id2, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);
			}
		}
	}

	fclose(schueler);
	fclose(noten);
	return 0;
}