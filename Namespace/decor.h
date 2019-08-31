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
    void kampret(int x, int y){
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
void Sound(int a){
    //+  ADD -lwinmm  in linker
    switch(a){
case 1 :
   PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\Login.wav"),NULL,SND_SYNC);
    break;
case 2:
    PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\Logout.wav"),NULL,SND_SYNC);
    break;
case 3:
    PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\Success.wav"),NULL,SND_SYNC);
    break;
case 4:
    PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\notify.wav"),NULL,SND_SYNC);
    break;
case 5:
    PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\Next.wav"),NULL,SND_SYNC);
    break;
case 6:
    PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\Denied.wav"),NULL,SND_SYNC);
    break;
case 7:
    PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\Exit.wav"),NULL,SND_SYNC);
    break;
case 8:
    PlaySound(TEXT("C:\\MinGW\\codeblock\\Soal APP\\Sound\\Error.wav"),NULL,SND_SYNC);
    break;
    }
}

void randC (string randStr,int horizl, int vertkl,int lama,int akhir){

     time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    for (int i = 0; i <= akhir; i++){

  int toValue = timePtr->tm_sec;
  int RandClr = 1 + (rand() & 14);
  int VarClr = 1 + (rand() & 14);

     textcolor(RandClr+VarClr);
      kampret(horizl,vertkl);  cout << randStr <<endl;
        Sleep(lama);
    textcolor(15);
  }
}
void TypingTxt (string Text,int clrTxt, int sleepTxt, int horzntl, int vrtkl){
    int length = Text.length();
    char Teksch[length];
strcpy(Teksch, Text.c_str());
    textcolor(clrTxt);
        kampret(horzntl,vrtkl);
    for (int i = 0; i < length; i++){
        cout << Teksch[i];
            Sleep(sleepTxt);
    }
    textcolor(15);
}
void TextjlnRight (string NameStr,int beginLoc, int endLoc, int Nl_vertikal,int colorTxt,int speedJLN){
int Mulai = beginLoc - NameStr.length(); // Mengambil posisi paling kanan
    for (int i = Mulai; i >= endLoc; i--){
             textcolor(colorTxt);
        kampret(i,Nl_vertikal); cout << NameStr <<" "<<endl;
    Sleep(speedJLN);
    }

textcolor(15);
}
void TextjlnLeft (string NameStr,int beginLoc,int endLoc, int Nl_vertikal,int colorTxt,int speedJLN){
    int Mulai = beginLoc;
        for (int j = Mulai; j < endLoc; j++){
               // system("cls");
            textcolor(colorTxt);
            kampret(j,Nl_vertikal);
                cout <<" "<< NameStr <<endl;
                Sleep(speedJLN);
        }
        textcolor(15);

}
void loading (int aw,int akr,int color, int Delay){
    for (;aw <= akr;aw++){
        textcolor(color);
            cout <<"=";
            Sleep(Delay);
    }
    textcolor(15);
}


}
