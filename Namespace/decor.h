#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <chrono>


namespace decor{

    using namespace std;
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textcolor(int ForgC) {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }

void colorPosition(int horizontal, int vertikal, int color=15){
    gotoxy(horizontal, vertikal);
    textcolor(color);

}
void sound(int code){ ///   ADD -lwinmm  in linker

  string activated = "disable";

  if (activated == "enable"){
    //     switch(code){
    // case 1 :
    //     PlaySound(TEXT("Database\\Sound\\Login.wav"),NULL,SND_SYNC);
    //     break;
    // case 2:
    //     PlaySound(TEXT("Database\\Sound\\Logout.wav"),NULL,SND_SYNC);
    //     break;
    // case 3:
    //     PlaySound(TEXT("Database\\Sound\\Success.wav"),NULL,SND_SYNC);
    //     break;
    // case 4:
    //     PlaySound(TEXT("Database\\Sound\\notify.wav"),NULL,SND_SYNC);
    //     break;
    // case 5:
    //     PlaySound(TEXT("Database\\Sound\\Next.wav"),NULL,SND_SYNC);
    //     break;
    // case 6:
    //     PlaySound(TEXT("Database\\Sound\\Denied.wav"),NULL,SND_SYNC);
    //     break;
    // case 7:
    //     PlaySound(TEXT("Database\\Sound\\Exit.wav"),NULL,SND_SYNC);
    //     break;
    // case 8:
    //     PlaySound(TEXT("Database\\Sound\\Error.wav"),NULL,SND_SYNC);
    //    break;
    //   }

  }else if (activated == "disable"){
     //pass
  }


}

void randC (string randStr,int horizl, int vertkl,int lama, int akhir){

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    int rendem1, rendem2;

        for (int i = 0; i <= akhir; i++){

            rendem1 = timePtr->tm_sec;
            textcolor (1 + rand() & timePtr->tm_sec);
            gotoxy(horizl,vertkl);
            cout << randStr <<endl;
        Sleep(lama);
    textcolor(15);
  }
}
void writeText (string Text,int clrTxt, int sleepTxt, int horzntl, int vrtkl){

    textcolor(clrTxt);
    gotoxy(horzntl,vrtkl);

        for (int i = 0; i < Text.length(); i++){
            cout << Text[i];
                Sleep(sleepTxt);
        }
    textcolor(15);
}
void teksJalan_kanan (string NameStr,int beginLoc, int endLoc, int Nl_vertikal,int colorTxt,int speedJLN){

  int Mulai = beginLoc - NameStr.length(); // Mengambil posisi paling kanan

  textcolor(colorTxt);
    for (int i = Mulai; i >= endLoc; i--){
      gotoxy(i, Nl_vertikal);
        cout << NameStr <<" "<<endl;
        Sleep(speedJLN);
    }

  textcolor(15);
}
void teksJalan_kiri (string NameStr,int beginLoc,int endLoc, int Nl_vertikal,int colorTxt,int speedJLN){

  int Mulai = beginLoc;

  textcolor(colorTxt);
    for (int j = Mulai; j < endLoc; j++){
        gotoxy(j, Nl_vertikal);
            cout <<" "<< NameStr <<endl;
            Sleep(speedJLN);
    }

  textcolor(15);
}


void showRules(int horizontal, int vertikal, array<string, 3> &rules, string errMessage){

    gotoxy(horizontal, vertikal);
    textcolor(9);
      cout <<"_______________________________________________________________________________"<<endl <<endl;

      for (int i = 0; i < 3; i++){
        textcolor(8);
          cout << " - ";
        textcolor(15);
          cout << rules[i];
      }

      textcolor(9);
      cout <<"\n_______________________________________________________________________________"<<endl;
      textcolor(15);
      cout <<"\n Message : "; teksJalan_kanan(errMessage, 79, 11, vertikal+7, 12, 20);

}

void loading (int aw,int akr,int color, int Delay){
    for (;aw <= akr;aw++){
        textcolor(color);
            cout <<"=";
            Sleep(Delay);
    }
    textcolor(15);
}
void loadingGotoxy(int horizontal, int vertikal, int color, int delay, char pil='+'){

    if (pil == '+'){ // jika pil bernilai '+' maka efek loading dimulai dari kiri
        gotoxy(horizontal, vertikal);
        for (int i = 0; i <= 79; i++){
            textcolor(color);
        cout <<'=';
        Sleep(delay);
        }
    }else if (pil == '-'){
        for (int i = horizontal; i >= 0; i--){ // jika pil bernilai '-' maka efek loading dimulai dari kanan
            gotoxy(i, vertikal);
            textcolor(color);
            cout <<'=';
            Sleep(delay);
        }
    }



}


}
