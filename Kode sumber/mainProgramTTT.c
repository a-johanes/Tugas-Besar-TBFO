//Tubes TBFO TicTacToe
//13517012/Johanes

#include "tictactoe.h"

int main() {
  //KAMUS
  int i,j,k;
  tictactoe m;
  char input[1],xo;
  boolean stop,win;
  //algoritma
  printf("\nTugas Besar TBFO\nMembuat robot Tic Tac Toe yang tidak dapat kalah\n");
  printf("dibuat oleh: Johanes/13517012\n");

  mulai(); //membaca flie external
  baru(&m); //membuat tictactoe baru
  stop = false;
  win = false;
  strcpy(current_state,start_state);
  strcpy(storage[counter],current_state);
  counter++;
  printf("\nKetik 5 untuk mulai dahulu atau\nketik angka yang lain (1..9) untuk komputer mulai dahulu\n");
  printf("komputer akan selalu mulai dari 5\n");
  printf("anda bertanda 'x', komputer bertanda 'o'\n");
  while(!stop) { //mengulang hingga kondisi berhenti
    printf("\nmasukan input anda: ");
    scanf("%s",input);
    ubah_input(&i,&j,input[0]);
    while (elmt(m,i,j)!=' ') { //validasi input
      printf("input salah, ulangi\n");
      printf("\nmasukan input anda: ");
      scanf("%s",input);
      ubah_input(&i,&j,input[0]);
    }
    loading(&m,input[0],&stop,&win); //menjalankan giliran komputer
    tulis(m); //menuliskan papan ke layar
    if (stop) { //jika sudah kondisi berhenti
      printf("\nHasil permainan: ");
      if(win) printf("ANDA KALAH!\n"); //jika menang
      else printf("DRAW\n"); //jika draw
    }
  }
  printf("\n");
  printf("state yang sudah dilewati:\n");
  for(int k=0;k<counter;k++) //menuliskan semua state yang pernah dilewati
    printf("%s\n",storage[k]);
  printf("\npress enter to continue............\n"); //memastikan tidak langusng tertutup cmd nya saat diexekusi langsung
  char tahan;
  scanf("%c",&tahan);
  scanf("%c",&tahan);
  return 0;
}
