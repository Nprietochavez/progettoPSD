#include <stdio.h>
#include <string.h>
#include "segnalazioni.h"

void visualizza(Segnalazione lista[], int count){
    printf("\n--- TUTTE LE SEGNALAZIONI----\n");

    for(int i =0; i<count; i++){
        printf("ID: %d\n", lista[i].id);
        printf("Nome: %s\n",lista[i].nome);
        printf("Categoria: %s\n",lista[i].categoria);

        if(lista[i].stato==0)
            printf("Stato: Aperta\n");
        else if(lista[i].stato==1)
            printf("stato: in lavorazione\n");
        else
            printf("Stato: Chiusa\n");

        printf("--------------\n");
    }
}

void aggiungiSegnalazione(Segnalazione lista[], int *count){

    printf("introduce ID: ");
            scanf("%d", &lista[*count].id);

            printf("Intrduce el nombre: ");
            scanf(" %[^\n]", lista[*count].nome);

            printf("Introduce categoria: ");
            scanf(" %[^\n]", lista[*count].categoria);

            printf("Introduce descripcion: ");
            scanf(" %[^\n]", lista[*count].descrizione);

            printf("Introduce urgencia (1-3): ");
            scanf("%d", &lista[*count].urgenza);

            printf("Introduce estado (0 abierta, 1 proceso, 2 cerrada): ");
            scanf("%d", &lista[*count].stato);

            (*count)++;

}

void stampaSegnalazione(Segnalazione s) {
    printf("ID: %d\n", s.id);
    printf("Nome: %s\n", s.nome);
    printf("Categoria: %s\n", s.categoria);
    printf("Descrizione: %s\n", s.descrizione);

    if(s.stato == 0)
        printf("Stato: Aperta\n");
    else if(s.stato == 1)
        printf("Stato: In lavorazione\n");
    else
        printf("Stato: Chiusa\n");

    printf("---------------------\n");
}

void cercaPerID(Segnalazione lista[], int count){
     int n, trovato = 0;
            printf("Introduce ID: ");
            scanf("%d", &n);

            for (int i = 0; i < count; i++)
            {
                if (lista[i].id == n)
                {
                    stampaSegnalazione(lista[i]);
                    trovato = 1;
                   
                }
            }
            if (!trovato)
                printf("No trovato\n");
}

void cambiaStato(Segnalazione lista[], int count){
     int n, statonew;
     int trovato=0;
            printf("Introduce el id para cambiar de estado: ");
            scanf("%d", &n);

           

            for (int i = 0; i < count; i++)
            {
                if (lista[i].id == n)
                {
                    printf("Segnalazione atttuale:\n");
                    stampaSegnalazione(lista[i]);
                    printf("Introduce nuevo estado (0 abierta, 1 proceso, 2 cerrada): ");
                    scanf("%d", &statonew);
                    lista[i].stato = statonew;
                    stampaSegnalazione(lista[i]);
                    trovato=1;
                }
                
            }
            if(!trovato){
                printf("Segnalazione non trovata\n");
            }
}

void eliminaSegnalazione(Segnalazione lista[],int *count){
    
            int n;
            int trovato =0;
            
            printf("Inserci ID da eliminare: ");
            scanf("%d", &n);

            for(int i = 0; i<*count; i++){
                if(lista[i].id==n){
                    //mover hacia atras
                    for(int j = i; j<*count-1; j++){
                        lista[j]=lista[j+1];
                    }
                (*count)--;
                trovato=1;
                printf("segnalazione eliminata\n");
                break;
                }
            }
            if(!trovato){
                printf("Segnalazione non trovata\n");
            }
}

void filtraPerStato(Segnalazione lista[], int count){

    int stato;
    int trovato=0;

    printf("Inserisci stato da filtrare (0 aperta, 1 in lavorazione, 2 chiusa)");
    scanf("%d", &stato);

    for(int i =0; i<count; i++){
        if(lista[i].stato==stato){
            stampaSegnalazione(lista[i]);
            trovato=1;
        }
    }
    if(!trovato){
        printf("Nessuna segnalazione trovata\n");
    }
}