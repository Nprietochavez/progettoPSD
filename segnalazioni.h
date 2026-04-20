#ifndef SEGNALAZIONI_H
#define SEGNALAZIONI_H

typedef struct
{
    int id;
    char nome[50];
    char categoria[50];
    char descrizione[100];
    int urgenza;
    int stato;
} Segnalazione;

//funciones
void aggiungiSegnalazione(Segnalazione lista[], int *count);
void visualizza(Segnalazione lista[], int count);
void cercaPerID(Segnalazione lista[], int count);
void cambiaStato(Segnalazione lista[], int count);
void eliminaSegnalazione(Segnalazione lista[], int *count);
void stampaSegnalazione(Segnalazione s);

#endif
