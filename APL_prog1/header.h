#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define max 10

//general data of students
typedef struct {
	int id1;
	char name[30];
	char nachname[30];
	int semester;
	float average;					//--> durchschnitt von t_fachnoten
}t_schueler_generalinfo;

t_schueler_generalinfo student[max];
//specific grades of students to calculate average
typedef struct {
	int id2;
	int fach1;
	int fach2;
	int fach3;
	int fach4;
	int fach5;
	
}t_fachnoten;

t_fachnoten grades[max];



int check_file(FILE* schueler, FILE* noten);
void print_data(FILE* schueler);
int menu_value();
void add_student();
void edit_student();