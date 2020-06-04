#ifndef DATZAM_H
#define DATZAM_H

#define MAX_LEN 20
#define MAX_ZAM 10

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#endif

typedef struct {
	int den, mesiac, rok;
} Datum;

typedef struct {
	char meno[MAX_LEN];
	Datum d_narod;
} OsobneUdaje;

typedef struct Zamestnanec {
	int id;
	char pozicia[MAX_LEN];
	double plat;
	OsobneUdaje udaje;
} Zamestnanec;




Zamestnanec genZamestnanca();
void genZamestnancov(Zamestnanec db[]);
void printZamestnanec(const Zamestnanec* z);
void printALL(Zamestnanec db[], int n);
#endif
