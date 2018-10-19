//adt tictactoe
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char mem[4][4];
} tictactoe; //tipe data tictactoe
//merupakan suatu tipe data array yang berisi karakter 'x', 'o', atau ' ' (spasi)

#define maxLength 52 //panjang string maximal dari setiap string
#define state 44 //jumlah state
#define symbol 9 //jumlah symbol

extern char transition[state][symbol+1][maxLength]; //transition table
extern char start_state[5]; //state awal;
extern char current_state[5]; //state sekarang
extern char final_state[13][5]; //list final states
extern char storage[9][5];
extern int counter;

#define elmt(m,i,j) (m).mem[(i)][(j)]

void baru(tictactoe *m);
//membuat tictactoe baru yang isinya ' ' (spasi) pada semua elemennya

void tulis(tictactoe m);
//prosedur menampilkan tictactoe ke layar

void isi(tictactoe *m, int i, int j, char input);
//prosedur mengisi tabel tictactoe

void ubah_input(int *i, int *j, char x);
//prosedur yang mengubah char x menjadi indeks pada array

boolean win_state();
//fungsi yang menyatakan final state sebagai menang atau draw

void cek_finish(tictactoe m,boolean *stop, boolean *win);
//mengecek apakah sudah state final dan apakah menang

void olah_state(tictactoe *m, char input);
//prosedur yang menjalankan giliran komputer berdasarkan input dan state sekarang

void loading(tictactoe *m,char input, boolean *stop, boolean *win);
//prosedur yang merupakan proses berpikirnya komputer untuk mengintepretasi
//kondisi yang ada

void mulai();
//prosedur yang dilakukan saat awal program berjalan
//yaitu membaca informasi dari file external
void delta(char input);
//merupakan transition function untuk dfa
//menerima input current_state dan mengembalikan state selanjutnya

#endif
