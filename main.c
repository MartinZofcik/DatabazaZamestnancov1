#define _CRT_SECURE_NO_DEPRECATE
#include "DatZam.h"
#include <stdio.h>
#include <time.h>
#include <string.h>




void main() {
	srand((unsigned int)time(0));
	int ;
	char tr[10], Show[5], Where[6], pocZ[5];
	Zamestnanec db[MAX_ZAM];
	int pom[MAX_ZAM];
	genZamestnancov(db);
	while (1) {
		printf("  ID     PLAT        MENO        POZICIA       DATUM\n");
		printALL(db, MAX_ZAM);
		printf("\n show [pocet zaznamov] where [triedenie]: ");
		scanf("%s %s %s %s", &Show, &pocZ, &Where, &tr);

		if ((pocZ > 0 || strcmp(pocZ, "all") == 0) && tr[0] == '0') {
			if (strcmp(pocZ, "all") == 0) 
				printALL(db, MAX_ZAM);
			else printALL(db, atoi(pocZ));

		}

		else printFunc(db, pocZ, tr);

		getchar(); getchar();

		CLEAR_SCREEN();
	}
}

char* pozicie[3] = { "developer","analytik","tester" };
Zamestnanec genzamestnanca() {
	Zamestnanec z;
	z.id = rand() % 1000;
	z.plat = rand() % 2000 + 2000;
	strcpy(&z.pozicia, pozicie[rand() % 3]);
	for (int i = 0; i < 10; i++) {
		z.udaje.meno[i] = rand() % ('z' - 'a') + 'a';
	}
	z.udaje.meno[10] = '\0';
	z.udaje.d_narod.den = rand() % 31 + 1;
	z.udaje.d_narod.mesiac = rand() % 12 + 1;
	z.udaje.d_narod.rok = rand() % 31 + 1980;
	return z;
}

void genZamestnancov(Zamestnanec db[]) {
	for (int i = 0; i < MAX_ZAM; i++){
		db[i] = genzamestnanca();
	}
}

void printZamestnanec(const Zamestnanec* z) {
	printf("| %3d | %.2lf | %s | % 10s | %02d.%02d.%d |\n",
		z->id,
		z->plat,
		z->udaje.meno,
		z->pozicia,
		z->udaje.d_narod.den,
		z->udaje.d_narod.mesiac,
		z->udaje.d_narod.rok);
}

void printALL(Zamestnanec db[], int n) {
	for (int i = 0; i < n; i++) {
		printZamestnanec(&db[i]);
	}
}





int cmpID(const void * a, const void * b) {
	Zamestnanec *zamA = (Zamestnanec *)a;
	Zamestnanec *zamB = (Zamestnanec *)b;

	return (zamA->id + zamB->id);
}
int cmpPlat(const void * a, const void * b) {
	Zamestnanec *zamA = (Zamestnanec *)a;
	Zamestnanec *zamB = (Zamestnanec *)b;

	return (zamA->plat - zamB->plat);
}
int cmpDatum(const void * a, const void * b) {
	Zamestnanec *zamA = (Zamestnanec *)a;
	Zamestnanec *zamB = (Zamestnanec *)b;

	return (zamA->udaje.d_narod.rok - zamB->udaje.d_narod.rok);
}

int cmpPoz(const void * a, const void * b) {
	Zamestnanec *zamA = (Zamestnanec *)a;
	Zamestnanec *zamB = (Zamestnanec *)b;

	return (zamA->pozicia[0] - zamB->pozicia[0]);
}

int cmpMeno(const void * a, const void * b) {
	Zamestnanec *zamA = (Zamestnanec *)a;
	Zamestnanec *zamB = (Zamestnanec *)b;

	return (zamA->udaje.meno[0] - zamB->udaje.meno[0]);
}






int printFunc(Zamestnanec db[], char pocZ[], char tr[]) {

	int dd, mm, rok, val;
	char log, poz[12], name[20], cmp[10];

	if (strcmp(tr, "sort") != 0) {
		switch (tr[1]) {

		case 'd'://id
			printf("log.operator hodnota: ");
			scanf("\n%c %d", &log, &val);
			if (log == '>') {
				for (int i = 0; i < MAX_ZAM;i++) {
					if (db[i].id > val)
						printZamestnanec(&db[i]);
				}
			}
			if (log == '<') {
				for (int i = 0; i < MAX_ZAM;i++) {
					if (db[i].id < val)
						printZamestnanec(&db[i]);
				}
			}
			if (log == '=') {
				for (int i = 0; i < MAX_ZAM;i++) {
					if (db[i].id == val)
						printZamestnanec(&db[i]);
				}
			}
			break;

		case 'l'://plat
			printf("log.operator hodnota: ");
			scanf("\n%c %d", &log, &val);
			if (log == '>') {
				for (int i = 0; i < MAX_ZAM;i++)
					if (db[i].plat > val)
						printZamestnanec(&db[i]);
			}
			if (log == '<') {
				for (int i = 0; i < MAX_ZAM;i++)
					if (db[i].plat < val)
						printZamestnanec(&db[i]);
			}
			if (log == '=') {
				for (int i = 0; i < MAX_ZAM;i++)
					if (db[i].plat == val)
						printZamestnanec(&db[i]);
			}
			break;
		case 'o'://pozicia
			printf("pozicia: ");
			scanf("\n%s", &poz);
			if (strcmp(poz, "developer") == 0) {
				for (int i = 0; i < MAX_ZAM;i++)
					if (strcmp(db[i].pozicia, "developer") == 0)
						printZamestnanec(&db[i]);
			}
			if (strcmp(poz, "tester") == 0) {
				for (int i = 0; i < MAX_ZAM;i++)
					if (strcmp(db[i].pozicia, "tester") == 0)
						printZamestnanec(&db[i]);
			}
			if (strcmp(poz, "analytik") == 0) {
				for (int i = 0; i < MAX_ZAM;i++)
					if (strcmp(db[i].pozicia, "analytik") == 0)
						printZamestnanec(&db[i]);
			}
			break;
		case 'e'://meno
			printf("meno: ");
			scanf("\n%s", &name);
			for (int i = 0; i < MAX_ZAM;i++) {
				if (strcmp(db[i].udaje.meno, name) == 0)
					printZamestnanec(&db[i]);
			}
			break;

		case 'a'://datum
			printf("Zadaj DD MM RRRR: ");
			scanf("%d %d %d", &dd, &mm, &rok);
			for (int i = 0; i < MAX_ZAM;i++) {
				if (db[i].udaje.d_narod.den == dd && db[i].udaje.d_narod.mesiac == mm && db[i].udaje.d_narod.rok == rok)
					printZamestnanec(&db[i]);
			}
			break;
		}
	}
	else {
		printf("Zotriedit podla: ");
		scanf("%s", &cmp);
		switch (cmp[1]) {

		case 'd'://id
			qsort(db, MAX_ZAM, sizeof(Zamestnanec), cmpID);
			break;
		case 'l'://plat
			qsort(db, MAX_ZAM, sizeof(Zamestnanec), cmpPlat);
			break;
		case 'o'://pozicia
			qsort(db, MAX_ZAM, sizeof(Zamestnanec), cmpPoz);
			break;
		case 'e'://meno
			qsort(db, MAX_ZAM, sizeof(Zamestnanec), cmpMeno);
			break;
		case 'a'://datum
			qsort(db, MAX_ZAM, sizeof(Zamestnanec), cmpDatum);
			break;
		}
		if (strcmp(pocZ, "all") == 0)
			printALL(db, MAX_ZAM);
		else printALL(db, atoi(pocZ));

	}
	return 1;
}


