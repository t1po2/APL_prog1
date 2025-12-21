#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
#include "header.h"



void add_student() {
	
	srand(time(NULL));

	int id_generator = (rand() % 9000) + 1000;


	for (int i = 0; i < max; i++) {
		if (student[i].id1 == 0) {
			student[i].id1 = id_generator;
			printf("Name:\t");
			scanf("%29s", student[i].name);
			printf("Nachname:\t");
			scanf("%29s", student[i].nachname);
			break;
		}
	}

	
	


}