/* Programma per avere le puttane brave a Magnaccio manager

17/1/05  Versione 2.45 NON FUNZIONA Con indirizzi di memoria per puttane
17/1/05  Versione 2.4  Con indirizzi di memoria per spacciatori
16/1/05  Versione 2.3  Adattata
16/1/05	 Versione 2.2  Funzionante
15/1/05  Versione 2.1  Funzionante a met…
15/1/05  Versione 2.0  Non Funzionante
*/

#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

int posizione[33],n;
unsigned long patch;    

void definizione_posizione()
{
     posizione[1]=9;
     posizione[2]=135;
     posizione[3]=267;
     posizione[4]=;
     posizione[5]=528;
     posizione[6]=651;
     posizione[7]=791;
     posizione[8]=901;
     posizione[9]=1041;
     posizione[10]=1163;
     posizione[11]=1290;
     posizione[12]=1421;
     posizione[13]=8;
     posizione[14]=8;
     posizione[15]=8;
     posizione[16]=8;
     posizione[17]=8;
     posizione[18]=8;
     posizione[19]=8;
     posizione[20]=8;
     posizione[21]=8;
     posizione[22]=8;
     posizione[23]=8;
     posizione[24]=8;
     posizione[25]=8;
     posizione[26]=8;
     posizione[27]=8;
     posizione[28]=8;
     posizione[29]=8;
     posizione[30]=8;
     posizione[31]=8;
     posizione[32]=8;
     return 0;
}

int	 main ()
{ 
	FILE *in, *out;
	int handle;
	patch=0x010063;
	definizione_posizione();
	clrscr();
	printf("Questo programma per magnaccio manager ti modifichera\' le qualita\' delle tue puttane\n\n");
	printf("Premere un tasto per continuare...\n\n");
	getch();
   if ((handle = open("data\puttane.dat", O_RDWR | O_BINARY)) == -1)
   {
	  printf("\n\n\nErrore: Non trovo il file dei salvataggi!\n\nSei sicuro di avermi messo nella stessa cartella di Magnaccio Manager?\n");
      printf("\nPremere un tasto per continuare...");
	  getch();
	  return 1;
   }
   for ( n=l; n <= 32; ++n )
   {
       lseek(handle,posizione[n],SEEK_SET);
//   write(handle, msg, strlen(msg));
       write(handle, &patch, 3);
   }
   close(handle);
   printf("Hai modificato le tue puttane!\nPuoi andare a giocare.\n\n\n\nPer eventuali bug contattare tipika@libero.it\nL\'Autore non si rende responsabile di eventuali danni\ncausati da questo programma, primo fra tutti l\'azzeramento dei progressi nel gioco.");
   getch();
   return (0);
}
