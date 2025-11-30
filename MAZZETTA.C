/* Programma per dare mazzette ai poliziotti di magnaccio manager

16/1/05	 Versione 2.2  Funzionante
15/1/05  Versione 2.1  Funzionante a metà
15/1/05  Versione 2.0  Non Funzionante
*/

#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

//unsigned char patch;    

int	 main ()
{ 
	FILE *in, *out;
	int handle;
//	char msg[] = "Hello world";
//    patch=0;
	clrscr();
    printf("Questo programma ti farà diminuire la percentuale di polizia fino allo 0\%\n\n");
	printf("Premere un tasto per continuare...\n\n");
	getch();
   if ((handle = open("ultima~1.dat", O_RDWR | O_BINARY)) == -1)
   {
	  printf("\n\n\nErrore: Non trovo il file dei salvataggi!\n\nSei sicuro di avermi messo nella stessa cartella di Magnaccio Manager?\n");
      printf("\nPremere un tasto per continuare...");
	  getch();
	  return 1;
   }
   lseek(handle,-6,SEEK_END);
//   write(handle, msg, strlen(msg));
   write(handle, 0x0, 1);
   close(handle);
   printf("Adesso tutti i poliziotti sono morti!!!\nPuoi andare a giocare.\n\n\n\nPer eventuali bug contattare tipika@libero.it\nL\'Autore non si rende responsabile di eventuali danni\ncausati da questo programma, primo fra tutti l\'azzeramento dei progressi nel gioco.");
   getch();
   return (0);
}
