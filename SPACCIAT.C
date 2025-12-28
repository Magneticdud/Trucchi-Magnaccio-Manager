/* Programma per avere spacciatori bravi a Magnaccio manager

17/1/05  Versione 2.3  Con indirizzi di memoria per spacciatori
16/1/05  Versione 2.3  Adattata
16/1/05	 Versione 2.2  Funzionante
15/1/05  Versione 2.1  Funzionante a metà
15/1/05  Versione 2.0  Non Funzionante
*/

#include "compat_dos.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <string.h>

int posizione[17], n;
unsigned long patch;

void definizione_posizione() {
  posizione[1] = 8;
  posizione[2] = 142;
  posizione[3] = 271;
  posizione[4] = 404;
  posizione[5] = 528;
  posizione[6] = 651;
  posizione[7] = 791;
  posizione[8] = 901;
  posizione[9] = 1041;
  posizione[10] = 1163;
  posizione[11] = 1290;
  // posizione di miky gracco
  posizione[12] = 1421;
  // posizione di michele falco
  // posizione[17]=1423;
  posizione[13] = 1559;
  posizione[14] = 1683;
  posizione[15] = 1804;
  posizione[16] = 1928;
  return;
}

int main() {
  FILE *in, *out;
  int handle;
  patch = 0x010063;
  definizione_posizione();
  clrscr();
  printf("Questo programma per magnaccio manager ti modifichera\' le qualita\' "
         "dei tuoi spaccini\n\n");
  printf("Premere un tasto per continuare...\n\n");
  getch();
  if ((handle = open("spacciatori.dat", O_RDWR | O_BINARY)) == -1) {
    printf("\n\n\nErrore: Non trovo il file dei salvataggi!\n\nSei sicuro di "
           "avermi messo nella stessa cartella di Magnaccio Manager?\n");
    printf("\nPremere un tasto per continuare...");
    getch();
    return 1;
  }
  for (n = 1; n <= 16; ++n) {
    lseek(handle, posizione[n], SEEK_SET);
    //   write(handle, msg, strlen(msg));
    write(handle, &patch, 3);
  }
  close(handle);
  printf("Hai modificato i tuoi spaccini!\nPuoi andare a giocare.\n\n\n\nPer "
         "eventuali bug contattami\nL\'Autore non si rende responsabile di "
         "eventuali danni\ncausati da questo programma, primo fra tutti "
         "l\'azzeramento dei progressi nel gioco.");
  getch();
  return (0);
}
