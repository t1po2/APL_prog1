#include "header.h"



int main() {
	srand(time(NULL));



	//opens csv file in read mode 
	FILE* schueler = fopen("schueler.csv", "r");
	FILE* noten = fopen("noten.csv", "r");

	//this literation checks if file exists and if yes than Data will be saved to a array if not a new File will be created for schueler.csv


	int counter_schueler = 0;
	int counter_noten = 0;

	if (schueler == NULL) {
		printf("Keine schueler.csv Datei vorhanden.\n");
		schueler = fopen("schueler.csv", "w");

	}
	else {
		for (int i = 0; i < max; i++) {
			int zeilen_check = fscanf(schueler, "%d, %[^,], %[^,], %d, %f", &student[i].id1, student[i].name, student[i].nachname, &student[i].semester, &student[i].average);
			
			if (zeilen_check == EOF) {
				break;
			}
			if (zeilen_check != 5) {
				counter_schueler++;
				char c;
				while ((c = fgetc(schueler)) != '\n' && c != EOF);		//clears Puffer of garbage values
				i--;
				continue;
			}
			
		}
		printf("Daten von schueler.csv sind geladen.\n");
		printf("Es konnten %d Datensaetze nicht geladen werden, aufgrund fehlener Werte.\n", counter_schueler);
	}


	//this literation checks if file exists and if yes than Data will be saved to a array if not a new File will be created for noten.csv
	if (noten == NULL) {
		printf("Keine noten.csv Datei vorhanden.\n");
		noten = fopen("noten.csv", "w");
		
	}
	else {
		for (int i = 0; i < max; i++) {
			int zeilen_check = fscanf(noten, "%d, %d, %d, %d, %d, %d", &grades[i].id2, &grades[i].fach1, &grades[i].fach2, &grades[i].fach3, &grades[i].fach4, &grades[i].fach5);

			if (zeilen_check == EOF) {
				break;
			}
			if (zeilen_check != 6) {
				counter_noten++;
				char c;
				while ((c = fgetc(schueler)) != '\n' && c != EOF);			//clears Puffer of garbage values
				i--;
				continue;
			}
			
		}
		printf("Daten von noten.csv sind geladen.\n");
		printf("Es konnten %d Datensaetze nicht geladen werden, aufgrund fehlener Werte.\n", counter_noten);
		
	}
	
	fclose(schueler);
	fclose(noten);
	schueler = fopen("schueler.csv", "w");
	noten = fopen("noten.csv", "w");

	grades_filler();

	//Menu

	int mvalue;
	
	
	while (1) {
		
		mvalue = menu_value();
		if (mvalue == 9) {
			printf("Auswahl ungueltig\n");
		}
		else if (mvalue == 1) {
			printf("\n\n");
			printf("\nOption: %d wurde ausgewaehlt\n", mvalue);
			add_student();
			
		}
		else if (mvalue == 2) {
			printf("\n\n");
			printf("\nOption: %d wurde ausgewaehlt\n", mvalue);
			edit_student();
			
		}
		else if (mvalue == 3) {
			printf("\n\n");
			printf("\nOption: %d wurde ausgewaehlt\n", mvalue);
			delete_id();
		}
		else if (mvalue == 4) {
			printf("\n\n");
			printf("\nOption: %d wurde ausgewaehlt\n", mvalue);
			print_array();
			find_id();
			
		}
		else if (mvalue == 5) {
			printf("\n\n");
			printf("\nOption: %d wurde ausgewaehlt\n", mvalue);
			calc_grade();
			save_exit(schueler, noten);
			break; //edit it back to break jsut for testing reasons
		}
		calc_grade();
	}










	//test print
	
	
	
	fclose(schueler);
	fclose(noten);
	return 0;
}