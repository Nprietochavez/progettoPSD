#include <stdio.h>
#include "segnalazioni.h"

int main()
{

    Segnalazione lista[100];
    int count = 0; // para contar cuantas segnalazione llevo guardadas
    int scelta;
    do
    {
        printf("\n----MENU----\n");
        printf("1. Aggiungi segnalazione\n");
        printf("2. Visualizza ttutte\n");
        printf("3. Cerca per ID\n");
        printf("4. cambia stato\n");
        printf("5. Elimina segnalazione\n");
        printf("0. Esci\n");
        printf("opcion:\n ");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            aggiungiSegnalazione(lista,&count);
            break;
        case 2:
           visualizza(lista,count);
           break;
        case 3:
        {

           cercaPerID(lista,count);
            break;
        }
        case 4:
        {
            cambiaStato(lista,count);
           
            break;
        }

        case 5: {
            eliminaSegnalazione(lista,&count);
            break;
        }
        case 0:
            printf("\nSalir");
            break;
        default:
            printf("Opcion no valiuda\n");
        }
    } while (scelta != 0);

    return 0;
}