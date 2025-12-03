/* Programma per avere la droga infinita a magnaccio manager

16/1/05  Versione 2.3  Adattata
16/1/05	Versione 2.2  Funzionante
15/1/05  Versione 2.1  Funzionante a metà
15/1/05  Versione 2.0  Non Funzionante
*/

#include "compat_dos.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <string.h>


unsigned long patch;

int main() {
  FILE *in, *out;
  int handle;
  // unsigned char msg[] = "\0x0\0x0\0x0b\0x54";
  patch = 0x540B0000;
  clrscr();
  printf("Questo programma per magnaccio manager ti riempirà il magazzino di "
         "droga\n\n");
  printf("Premere un tasto per continuare...\n\n");
  getch();
  if ((handle = open("ultima~1.dat", O_RDWR | O_BINARY)) == -1) {
    printf("\n\n\nErrore: Non trovo il file dei salvataggi!\n\nSei sicuro di "
           "avermi messo nella stessa cartella di Magnaccio Manager?\n");
    printf("\nPremere un tasto per continuare...");
    getch();
    return 1;
  }
  lseek(handle, 10, SEEK_SET);
  //   write(handle, msg, strlen(msg));
  write(handle, &patch, 4);
  write(handle, &patch, 4);
  write(handle, &patch, 4);
  write(handle, &patch, 4);
  write(handle, &patch, 4);
  close(handle);
  printf("Praticamente hai la droga infinita!\nPuoi andare a "
         "giocare.\n\n\n\nPer eventuali bug contattami\nL\'Autore non si rende "
         "responsabile di eventuali danni\ncausati da questo programma, primo "
         "fra tutti l\'azzeramento dei progressi nel gioco.");
  getch();
  return (0);
}
