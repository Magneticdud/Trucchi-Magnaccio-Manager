/* Programma per avere mafiosi amici a Magnaccio manager

17/1/05  Versione 2.46  Con indirizzi di memoria per mafiosi
17/1/05  Versione 2.4  Con indirizzi di memoria per spacciatori
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

int posizione[15], n;
unsigned long patch;

void definizione_posizione() {
  posizione[1] = 14;
  posizione[2] = 149;
  posizione[3] = 298;
  posizione[4] = 403;
  posizione[5] = 554;
  posizione[6] = 670;
  posizione[7] = 788;
  posizione[8] = 924;
  // tabaran 1064
  posizione[9] = 1064;
  // foster 1177
  posizione[10] = 1177;
  // sanvitale 1316
  posizione[11] = 1316;
  // puddu 1441
  posizione[12] = 1441;
  // don vitaliano 1563
  posizione[13] = 1563;
  // paoluccio 1690
  posizione[14] = 1690;
  return;
}

int main() {
  FILE *in, *out;
  int handle;
  patch = 0x63;
  definizione_posizione();
  clrscr();
  printf("Questo programma per magnaccio manager ti modifichera\' le qualita\' "
         "dei tuoi spaccini\n\n");
  printf("Premere un tasto per continuare...\n\n");
  getch();
  if ((handle = open("mafiosi.dat", O_RDWR | O_BINARY)) == -1) {
    printf("\n\n\nErrore: Non trovo il file dei salvataggi!\n\nSei sicuro di "
           "avermi messo nella stessa cartella di Magnaccio Manager?\n");
    printf("\nPremere un tasto per continuare...");
    getch();
    return 1;
  }
  for (n = 1; n <= 14; ++n) {
    lseek(handle, posizione[n], SEEK_SET);
    //   write(handle, msg, strlen(msg));
    write(handle, &patch, 1);
  }
  close(handle);
  printf("Sei amico di tutti i mafiosi!\nPuoi andare a giocare.\n\n\n\nPer "
         "eventuali bug contattami\nL\'Autore non si rende responsabile di "
         "eventuali danni\ncausati da questo programma, primo fra tutti "
         "l\'azzeramento dei progressi nel gioco.");
  getch();
  return (0);
}
