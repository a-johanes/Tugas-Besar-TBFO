//implementasi tictactoe.h
#include "tictactoe.h"

  char transition[state][symbol+1][maxLength]; //transition table
  char start_state[5]; //state awal;
  char current_state[5]; //state sekarang
  char final_state[13][5]; //list final states
  char storage[9][5];
  int counter;

void baru(tictactoe *m)
//membuat tictactoe baru yang isinya ' ' (spasi) pada semua elemennya
{
  //kamus
  int i,j;
  //algoritma
  for (i=1;i<=3;i++) {
    for (j=1;j<=3;j++) {
      elmt(*m,i,j) = ' '; //mengisi setiap elemen dengan spasi
    }
  }
  counter =0;
}

void tulis(tictactoe m)
//prosedur menampilkan tictactoe ke layar
{
  //kamus
  int i,j;
  //algoritma
  for (i=1;i<=3;i++) {
    for (j=1;j<=3;j++) {
      printf("%c",elmt(m,i,j)); //menuliskan elemen tiap kolom ke samping
      if (j!=3) printf("|");
    }
    printf("\n"); //pindah baris baru untuk baris berikutnya
    if (i!=3) printf("~~~~~\n");
  }
}

void isi(tictactoe *m, int i, int j, char input)
//prosedur mengisi tabel tictactoe
{
  elmt(*m,i,j) = input;
}

void ubah_input(int *i, int *j, char x)
//prosedur yang mengubah char x menjadi indeks pada array
{
  //algoritma
  switch (x) {
    case '1' ... '3' :
      *i = 1;
      *j = (int)(x-'0');
      break;
    case '4' ... '6' :
      *i = 2;
      *j = (int)(x-'0') - 3;
      break;
    case '7'...'9' :
      *i = 3;
      *j = (int)(x-'0') -6;
      break;
    default : *i = *j = 0;
  }
}

boolean win_state()
//fungsi yang menyatakan final state sebagai menang atau draw
{
  //kamus
  boolean tmp;
  //algoritma
  tmp = (strcmp("q23",current_state)==0) || (strcmp("q24",current_state)==0);
  return !tmp;
}

void cek_finish(tictactoe m,boolean *stop, boolean *win)
//mengecek apakah sudah state final dan apakah menang
{
  //kamus
  int i;
  //algoritma
  i = 0;
  while (i<10 && strcmp(final_state[i],current_state)!=0) {
    i++;
  }//i==15 || final_state[i]==state
  *stop = (strcmp(final_state[i],current_state)==0);
  if (*stop) {
    *win = win_state(current_state);
  }
}

void olah_state(tictactoe *m, char input)
//prosedur yang menjalankan giliran komputer berdasarkan state sekarang
{
  //kamus
  int i,j;
  //algoritma
  delta(input);
  //pendefinisian state
  if (strcmp("q1",current_state)==0) {
    ubah_input(&i,&j,'1');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q2",current_state)==0) {
    ubah_input(&i,&j,'8');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q3",current_state)==0) {
    ubah_input(&i,&j,'7');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q4",current_state)==0) {
    ubah_input(&i,&j,'6');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q5",current_state)==0) {
    ubah_input(&i,&j,'4');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q6",current_state)==0) {
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q7",current_state)==0) {
    ubah_input(&i,&j,'2');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q8",current_state)==0) {
    ubah_input(&i,&j,'7');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q9",current_state)==0) {
    ubah_input(&i,&j,'6');
    if (elmt(*m,i,j)=='o') ubah_input(&i,&j,'8');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q10",current_state)==0) {
    ubah_input(&i,&j,'4');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q11",current_state)==0) {
    ubah_input(&i,&j,'3');
    if (elmt(*m,i,j)=='o') ubah_input(&i,&j,'8');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q12",current_state)==0) {
    ubah_input(&i,&j,'7');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q13",current_state)==0) {
    ubah_input(&i,&j,'4');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q14",current_state)==0) {
    ubah_input(&i,&j,'2');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q15",current_state)==0) {
    ubah_input(&i,&j,'7');
    if (elmt(*m,i,j)=='o') ubah_input(&i,&j,'6');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q16",current_state)==0) {
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q17",current_state)==0) {
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q18",current_state)==0) {
    ubah_input(&i,&j,'2');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q19",current_state)==0) {
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q20",current_state)==0) {
    ubah_input(&i,&j,'7');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q21",current_state)==0) {
    ubah_input(&i,&j,'4');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q22",current_state)==0) {
    ubah_input(&i,&j,'9');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q23",current_state)==0) {
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
    char x='1';
    ubah_input(&i,&j,x);
    while (x!='9' && elmt(*m,i,j)!=' ') {
      x++;
      ubah_input(&i,&j,x);
    } //x=='9' || elmt(*m,i,j)==' '
    isi(m,i,j,'o');
    while (x!=':' && elmt(*m,i,j)!=' ') {
      x++;
      ubah_input(&i,&j,x);
    } //x=='9' || elmt(*m,i,j)==' '
    if (x!=':') isi(m,i,j,'x');
  } else if (strcmp("q24",current_state)==0) {
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
    char x='9';
    ubah_input(&i,&j,x);
    while (x!='1' && elmt(*m,i,j)!=' ') {
      x--;
      ubah_input(&i,&j,x);
    } //x=='9' || elmt(*m,i,j)==' '
    isi(m,i,j,'o');
    while (x!='0' && elmt(*m,i,j)!=' ') {
      x--;
      ubah_input(&i,&j,x);
    } //x=='9' || elmt(*m,i,j)==' '
    if (x!='0') isi(m,i,j,'x');
  } else if (strcmp("q25",current_state)==0) {
    ubah_input(&i,&j,'5');
    isi(m,i,j,'o');
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q26",current_state)==0) {
    ubah_input(&i,&j,'5');
    isi(m,i,j,'o');
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q27",current_state)==0) {
    ubah_input(&i,&j,'5');
    isi(m,i,j,'o');
    ubah_input(&i,&j,'1');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q28",current_state)==0) {
    ubah_input(&i,&j,'5');
    isi(m,i,j,'o');
    ubah_input(&i,&j,'1');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q29",current_state)==0) {
    ubah_input(&i,&j,'6');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q30",current_state)==0) {
    ubah_input(&i,&j,'5');
    isi(m,i,j,'o');
    ubah_input(&i,&j,'1');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q31",current_state)==0) {
    ubah_input(&i,&j,'1');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q32",current_state)==0) {
    ubah_input(&i,&j,'5');
    isi(m,i,j,'o');
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q33",current_state)==0) {
    ubah_input(&i,&j,'7');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q34",current_state)==0) {
    ubah_input(&i,&j,'4');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q35",current_state)==0) {
    ubah_input(&i,&j,'9');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q36",current_state)==0) {
    ubah_input(&i,&j,'6');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q37",current_state)==0) {
    ubah_input(&i,&j,'3');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q38",current_state)==0) {
    ubah_input(&i,&j,'8');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q39",current_state)==0) {
    ubah_input(&i,&j,'8');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q40",current_state)==0) {
    ubah_input(&i,&j,'8');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q41",current_state)==0) {
    ubah_input(&i,&j,'6');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  } else if (strcmp("q42",current_state)==0) {
    ubah_input(&i,&j,'4');
    isi(m,i,j,'o');
    ubah_input(&i,&j,input);
    isi(m,i,j,'x');
  }
}

void loading(tictactoe *m,char input, boolean *stop, boolean *win)
//prosedur yang merupakan proses berfikirnya komputer untuk mengintepretasi
//kondisi yang ada
{
  //algoritma
  olah_state(m,input);
  cek_finish(*m,stop,win);
}

void mulai() {
  //kamus
  FILE *info;
  char *retval;
  int i,j;
  char tmp[maxLength],*parse;
  //algoritma
  info = fopen("informasi.txt","r"); //dibuka untuk dibaca
  for (i=1;i<=64;i++) retval = fgets(tmp,maxLength,info); //skip 86 baris pertama
  retval = fgets(tmp,maxLength,info); //baca start_state
  parse = strtok(tmp,"\n");
  strcpy(start_state,parse);
  for (i=1;i<=2;i++) retval = fgets(tmp,maxLength,info); //skip 2 baris
  //membaca final_state
  for (i=0;i<10;i++) {
    retval = fgets(tmp,maxLength,info);
    parse = strtok(tmp,"\n");
    strcpy(final_state[i],parse);
  }
  for (i=1;i<=2;i++) retval = fgets(tmp,maxLength,info); //skip 2 baris
  //membaca transition table
  for (i=0;i<state;i++){
    retval = fgets(tmp,maxLength,info);
    parse = strtok(tmp," \n");
    j = 0;
    strcpy(transition[i][j],parse); //ambil elemen pertama
    j++;
    for (j;j<symbol+1;j++) {
        parse = strtok(NULL," \n");
        strcpy(transition[i][j],parse); //elemen baris pertama
    }
  }

  fclose(info); //ditutup
}

void delta(char input) {
  //prosedur mengisi current_state dengan state selanjutnya berdasarkan input
  //kamus
  int i;
  char *first,tmp[4];
  //algoritma
  first = (&current_state[1]);
  strcpy(tmp,first);
  i = atoi(tmp);
  strcpy(current_state,transition[i][(int)(input-'0')]);
  strcpy(storage[counter],current_state);
  counter++;
}
