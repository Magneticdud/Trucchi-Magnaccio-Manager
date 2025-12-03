#ifndef COMPAT_DOS_H
#define COMPAT_DOS_H

#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>

/* Map Turbo C functions to modern MSVC equivalents */

#include <windows.h>

/* clrscr: Clears the console screen */
static void clrscr(void) {
  SetConsoleOutputCP(65001);
  system("cls");
}

/* getch: Gets a character from console without echo */
/* MSVC has _getch in conio.h */
#define getch _getch

/* open: Map to _open and ensure flags are correct */
/* O_BINARY is supported by MSVC */
#define open _open
#define close _close
#define read _read
#define write _write
#define lseek _lseek

/* Define standard flags if missing (though they should be in fcntl.h) */
#ifndef O_RDWR
#define O_RDWR _O_RDWR
#endif
#ifndef O_BINARY
#define O_BINARY _O_BINARY
#endif

#endif /* COMPAT_DOS_H */
