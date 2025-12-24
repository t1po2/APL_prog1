#include "header.h"	


void calc_grade() {
	int teiler = 5;

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 6; j++) {
			if (student[i].id1 == grades[j].id2) {
				if (grades[j].fach1 == 0) {
					teiler--;
				}
				if (grades[j].fach2 == 0) {
					teiler--;
				}
				if (grades[j].fach3 == 0) {
					teiler--;
				}
				if (grades[j].fach4 == 0) {
					teiler--;
				}
				if (grades[j].fach5 == 0) {
					teiler--;
				}
				if (teiler > 0 && teiler < 6) {
					student[i].average = (grades[j].fach1+ grades[j].fach2+grades[j].fach3+ grades[j].fach4+grades[j].fach5) / (float)teiler;
				}
				if (teiler == 0 || teiler > 5) {
					break;
				}	
			}
			if (student[i].id1 == 0) {
				continue;
			}
		}
	}
}
