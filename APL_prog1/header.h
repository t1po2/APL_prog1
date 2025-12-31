#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define max 50


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



int check_file(FILE* schueler, FILE* noten); //check if file exists
int menu_value(); //input menu option
void add_student(); //adds new student
void edit_student(); //edit student iwth ID input
void print_array(); // prints out current array
void find_id();//shows info of student by inputtting ID
void save_exit(FILE* schueler, FILE* noten);
void delete_id();//Deletes Student ID and grades;
void calc_grade();//calcs average grade
int check_datatype(const char* aufforderung); //little addition to avoid false inputs
void grades_filler();//error in files automated grades and matching id will be filled 
void sort_students_by_name(); //sorts name alphabetically 