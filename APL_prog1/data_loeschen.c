#include "header.h"

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

