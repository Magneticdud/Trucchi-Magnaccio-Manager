/* Programma per dare mazzette ai poliziotti di magnaccio manager

16/1/05  Versione 2.35  Corrette poche cose, ora funziona
16/1/05  Versione 2.3  Modificata in editor ma non funziona
16/1/05	 Versione 2.2  Funzionante
15/1/05  Versione 2.1  Funzionante a met�
15/1/05  Versione 2.0  Non Funzionante
*/

#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

int valore,valorex;    

int	 main ()
{ 
	FILE *in, *out;
	int handle;
//	char msg[] = "Hello world";
//    patch=0;
	clrscr();
	printf("Questo programma ti permetter� di modificare la percentuale di polizia a tuo piacimento\n\n");
	printf("Premere un tasto per continuare...\n\n");
	getch();
	printf("Inserire il valore di polizia che preferisci compreso tra zero e novantanove");
	scanf("%d",&valore);
	printf("Hai inserito il valore %d\n",valore);
	while (valore>99||valore<0)
		{
		printf("Devi inserire un valore compreso tra zero e novantanove");
		scanf("%d",&valore);
		}
   valorex=valore*2;

   if ((handle = open("ultima~1.dat", O_RDWR | O_BINARY)) == -1)
   {
	  printf("\n\n\nErrore: Non trovo il file dei salvataggi!\n\nSei sicuro di avermi messo nella stessa cartella di Magnaccio Manager?\n");
      printf("\nPremere un tasto per continuare...");
	  getch();
	  return 1;
   }
   lseek(handle,-6,SEEK_END);
//   write(handle, msg, strlen(msg));
   write(handle, &valorex, 1);
   close(handle);
   printf("Tutto ok!\nPuoi andare a giocare.\n\n\n\nPer eventuali bug contattami\nL\'Autore non si rende responsabile di eventuali danni\ncausati da questo programma, primo fra tutti l\'azzeramento dei progressi nel gioco.");
   getch();
   return (0);
}
