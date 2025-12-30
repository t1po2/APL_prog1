#include "header.h"

//this function checks if file alr exists, if not than a new one will be created
int check_file(FILE* schueler, FILE* noten) {
	if (schueler == NULL) {
		schueler = fopen("schueler.csv", "w");
		noten = fopen("noten.csv", "w");
		return 1;
	}
	else {
		for (int i = 0; i < max; i++) {
			fscanf(schueler, "%d, %[^,], %[^,], %d, %f", &student[i].id1, student[i].name, student[i].nachname, &student[i].semester, &student[i].average);
			fscanf(noten, "%d, %d, %d, %d, %d, %d", grades[i].id2, grades[i].fach1, grades[i].fach2, grades[i].fach3, grades[i].fach4, grades[i].fach5);
			return 2;
		}
	}

}






//Checks if Input is correct datatype
int check_datatype(const char* aufforderung) {
    int wert;
    printf("%s", aufforderung);

    // Solange scanf keine Zahl findet...
    while (scanf("%d", &wert) != 1) {
        printf("Fehler: Bitte gib eine Zahl ein!\n");
        printf("%s", aufforderung);

        //clear Puffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // safety m
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return wert;
}


// if a error occurs with creating id2 or there is no id2 for id1 than this function will fill the gap
void grades_filler() {
    //checks if id1=id2 in both files
    for (int i = 0; i < max; i++) {
        if (student[i].id1 == 0) continue;

        int found = 0;

        for (int j = 0; j < max; j++) {
            if (student[i].id1 == grades[j].id2) {
                found = 1;
                break;
            }
        }

        //if not found a identical id will be created with grades = 0
        if (found == 0) {
            for (int k = 0; k < max; k++) {
                if (grades[k].id2 == 0) {
                    grades[k].id2 = student[i].id1;
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
}