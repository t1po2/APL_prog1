#include "header.h"

<<<<<<< HEAD
=======
void delete() {
    print_array();
    int del_id;

    printf("Weclhe ID möchten sie loeschen?\n");
    scanf(" %d", &del_id);

    for (int i = 0; i < max; i++) {
        if (student[i].id1 == del_id) {
            student[i].id1 = 0;
            strcpy(student[i].name, ""); // Name auf leeren String setzen
            strcpy(student[i].nachname, "");
            student[i].semester = 0;
            student[i].average = 0;
            break;
        }
        else {
            printf("ID nicht gefunden.");
        }
    }
}

>>>>>>> 1cb44d84390ee7929ab1d5e1e9003f97f192e161
