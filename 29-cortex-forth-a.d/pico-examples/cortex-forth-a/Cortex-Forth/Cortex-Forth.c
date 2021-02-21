/*
  Forth virtual machine

  This code is in the public domain.

*/

/* rp2040 */
#include <stdio.h>
#include "pico/stdio.h"

/* cortex forth */
#include "Cortex-Forth.h"

#define RAM_SIZE 0x1200
#define S0 0x1000
#define R0 0x0f00
#define NAME(m, f, c, x, y, z) {memory.data [m] = f + c + (x << 8) + (y << 16) + (z << 24);}
#define LINK(m, a) {memory.data [m] = a;}
#define CODE(m, a) {memory.program [m] = a;}
#define DATA(m, a) {memory.data [m] = a;}
#define IMMED 0x80

#define RP2040_PICO
#ifdef RP2040_PICO
#include "rp2040_pico.inc"
#endif

// global variables
union Memory {
  int data [RAM_SIZE];
  void (*program [0]) (void);
} memory;

// String tib = "";
int S = S0; // data stack pointer
int R = R0; // return stack pointer
int I = 0; // instruction pointer
int W = 0; // working register
// uint8_t getKey()
int T = 0; // top of stack
int H = 0; // dictionary pointer, HERE
int D = 0; // dictionary list entry point
int base = 10;
bool state = false; // compiling or not

/*  A word in the dictionary has these fields:
  name  32b word,  a 32 bit int, made up of byte count and three letters
  link  32b word, point to next word in list, 0 says end of list
  code  32b word, a pointer to some actual C compiled code,
        all native code is in this field
  data  32b word, at least, a list to execute or a data field of some kind


*/


// primitive definitions

void _LBRAC (void) {
  state = false; // interpreting
}

void _RBRAC (void) {
  state = true; // compiling
}

void _NOP (void) {
  return;
}

void _EXIT (void) {
  I = memory.data [R++];
}

void _DROP (void) {
  T = memory.data [S++];
}

void _DUP (void) {
  memory.data [--S] = T;
}

void _QDUP (void) {
  if (T) _DUP ();
}

void _KEY (void) {
  _DUP ();
  // uint8_t getKey(void);
  T = getKey();
  // while (!Serial.available ());
  // T = Serial.read ();
//  Serial.write (T);
}

void _EMIT (void) {
  char c = T;
  // Serial.write (c);
  // void putch(char c);
  putch(c);
  _DROP ();
}

void _CR (void) {
  putch('\n');
  // Serial.println (" ");
}

void _OK (void) {
  // if (tib [tib.length () - 1] == 10) Serial.println (" Ok");
  strcpy(print_string, "\n\nOkay my friend\n\n"); // demo use
  printf("%s", print_string);
}

void _SWAP (void) {
  W = memory.data [S];
  memory.data [S] = T;
  T = W;
}

void _OVER (void) {
  _DUP ();
  T = memory.data [S + 1];
}

void interpreter(void) {
   _KEY(); _EMIT(); _CR(); _OK();
}

// Sun Feb 21 20:07:02 UTC 2021
