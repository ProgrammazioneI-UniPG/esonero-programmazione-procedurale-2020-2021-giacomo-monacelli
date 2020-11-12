//includo le librerie e dichiaro le variabili che utilizzerò all'interno del programma
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char M [128],K[128],C[128], richiesta;
int i, j, lunghezza_M, lunghezza_K;
time_t t;

int main () {
//faccio inserire la stringa all'utente e verifico che sia di 128 caratteri al massimo, in caso contrario dovrà inserirne un'altra
  printf ("Inserisca una stringa di massimo 128 caratteri:\n");
  do {
    scanf ("%s", M);
    lunghezza_M = strlen(M);
    if (lunghezza_M>127) {
      printf ("La stringa inserita non è valida, ne inserisca un'altra:\n");
    }
  } while (lunghezza_M>127);
  fflush (stdin);
//faccio visualizzare all'utente la dimensione della sringa da lui inserita
  printf ("La stringa che ha inserito è formata da %d caratteri\n", lunghezza_M);
//lascio scegliere all'utente ciò che vuole fare
  printf ("Inserica un numero per scegliere l'opzione desiderata:\n0 se vuole terminare;\n1 se vuole inserire lei la chiave di codifica;\n2 se vuole che la chiave di codifica sia generata;\n");
  scanf ("%s", &richiesta);
//utilizzo la dichiarazione switch per sviluppare poi i casi che corrispondono alla scelta dell'utente
  here: switch (richiesta) {
//é stata scelta l'opzione di terminare il programma, dunque dopo aver inserito lo 0 il programma si terminerà
    case ('0'):
      printf ("Ha scelto di uscire dal programma, arrivederci!\n");
      break;
//nel caso 1 all'utente viene chiesto di inserire la chiave di codifica; se la chiave è accettabile, il programma va avanti, altrimenti l'utente dovrà inserire un'altra chiave che sia accettabile
    case ('1'):
      printf ("Inserisca una chiave di codifica di lunghezza uguale o superiore della stringa precedentemente inserita, ma sempre minore di 128 caratteri altrimenti non verrà considerata:\n");
      do {
        fgets (K, 128, stdin);
        fflush (stdin);
        lunghezza_K = strlen(K);
        continue;
      } while (lunghezza_K < lunghezza_M);
      break;
//avendo scelto il caso 2, la chiave viene prima generata e poi visualizzata dall'utente
    case ('2'):
      printf ("La chiave creata è:");
      srand ((unsigned) time(NULL));
      for (int i=0; i < strlen(M); i++)
      {
        K[i] = (33 + rand() %93); //creo così i caratteri random, evitando i caratteri speciali dell'ASCII
        printf ("%c", K[i]);
      }
      lunghezza_K = strlen (K);
      break;
//nel caso im cui l'utente non inserisca un numero che non sia tra quelli richiesti, verrà visualizzata la richiesta di inserire uno dei tre valori finchè l'utente non inserirà uno dei valori giusti
    default :
      while (richiesta !='0' || richiesta!='1' || richiesta !='2') {
        printf ("Per favore inserisca un numero tra 0,1 e 2 in base all'opzione che ha deciso di fare\n");
        scanf ("%s", &richiesta);
        goto here;
      }
      break;
  }
//verrà visualizzata sia la stringa codifica sia la stringa originale nel caso in cui la chiave è stata inserita o generata
  if (richiesta != '0') {
    for (int j=0; j < 128; j++) {
        C[j] = M[j]^K[j];
        M[j] = C[j]^K[j];
    }
    printf ("\nLa stringa cifrata risultante è: %s\n", C);
    printf ("La stringa originaria è: %s\n", M);
  }
  return 0;
}
