/* Programma per verificare la conformità della classifica

18/1/05  Versione 2.5  Adattata
17/1/05  Versione 2.46  Con indirizzi di memoria per mafiosi
17/1/05  Versione 2.4  Con indirizzi di memoria per spacciatori
16/1/05  Versione 2.3  Adattata
16/1/05	 Versione 2.2  Funzionante
15/1/05  Versione 2.1  Funzionante a metà
15/1/05  Versione 2.0  Non Funzionante
*/

#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

int posizione,n;
char valore;
unsigned long patch;    

int definizione_posizione()
{
     posizione=330;
	 return 0;
}

int	 main ()
{ 
	FILE *in, *out;
	int handle;
	patch=0x10;
	definizione_posizione();
	clrscr();
	printf("Questo programma verifica la correttezza della classifica di magnaccio manager");
	printf("\n\nPremere un tasto per continuare...\n\n");
	getch();
	if ((handle = open("classi~1.dat", O_RDONLY | O_BINARY)) == -1)
	{
	  printf("\n\n\nErrore: Non trovo il file della classifica!\n\nSei sicuro di avermi messo nella stessa cartella di Magnaccio Manager?\n");
      printf("\nPremere un tasto per continuare...");
	  getch();
	  return 1;
	}
	lseek(handle,posizione,SEEK_SET);
	read(handle, &valore, 1);
	printf("Info di debug: v=%d, p=%d",valore,patch);   
//   write(handle, msg, strlen(msg));
//	write(handle, &patch, 1);
	if (valore==patch)
		printf("\n\nIl gioco è stato hackerato!!!");
	else
		printf("\n\nTutto ok l\'utente era onesto");
    close(handle);
   getch();
   return (0);
}
