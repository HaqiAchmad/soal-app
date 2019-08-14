#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

void kampret(int x, int y);
void textcolor(int ForgC);
void Sound(int a);

void UserLogin (string Userid); /**< Fungsi user login */
void printQuest(int numQs, string Quest, string jwb1, string jwb2, string jwb3, string jwb4, string jwb5, char &UserJwb); /**< Menanpilkan soal ke console */
void printUserValue (array <char, 10> &Data, array <char, 10> &Correct,int &N_Angka,char &N_Abjad, string &Status); /**<Menghitung dan  Menapilkan jwh yang benar dan salah */
void UserData (string &User, string &Nis, string &Kelas, string &Jrusan); /**< Mengambil data siswa dari user */
void printDataSiswa (string Name, string Nis, string Kelas, string Jurusan, int N_angk, char N_abjd, string status);  /**< Menampikan Data siswa */

void randC (string randStr,int horizl, int vertkl,int lama,int akhir);
void TypingTxt (string Text,int clrTxt, int sleepTxt, int horzntl, int vrtkl); /**< Membuat teks seperti di ketik */
void TextjlnRight (string TxtStr,int beginLoc,int endLoc, int Nl_vertikal,int colorTxt,int speedJLN); /**< Membuat teks berjalan dari kiri */
void TextjlnLeft (string TxtStr,int beginLoc,int endLoc, int Nl_vertikal,int colorTxt,int speedJLN);
void loading (int aw,int akr,int color, int Delay);


int main(){

    string nis,kls,usLogin,versi; versi = "Version : 5.2.0";
    string usName,usNis,usKelas,usJurusan;
    string Soal,j1,j2,j3,j4,j5;
    char Start;
    char N_abjad; string status; int N_angka;
     array <char, 10> AnswrTrue;
     array <char, 10> JwbUser;

    TypingTxt("Created by : ",12,150,23,10);  randC("Achmad Baihaqi",36,10,200,15);
        system("cls");

    Restart:
    kampret(29,11);textcolor(9);
    cout <<"Start Program y/n ? =  "; textcolor(4);
    cin >> Start;
    cout <<" \n";

    if (Start == 'y' || Start == 'Y'){
            Sound(1);
            UserLogin(usLogin);

     }else if(Start != 'y' || Start != 'Y'){
         Sound(2);
       system("cls");textcolor(15);
       randC(versi,33,10,300,21);
        kampret(25,19);cout <<endl;
            textcolor(12);
        system("pause");
        textcolor(0);
        return 0;

     }

    cout <<" "<<endl<<endl;
    textcolor(9);cout<<"Process";
        for(int c = 0;c <= 2;c++){
            textcolor(15);cout<<".";
            Sleep(1380);
        }


        cout <<" \n"<<endl;textcolor(15);
    cout <<"Loading  ";
loading(0,69,13,12);


userdata:
UserData(usName,usNis,usKelas,usJurusan);

system("cls");
    if (usKelas == "X (sepuluh)" && usJurusan == "Rekayasa Perangkat Lunak"){
        AnswrTrue = {'a','e','c','a','b','a','d','d','e','a'};

        Soal = "Data yang berisi sederet karakter disebut...";
        j1 = "String"; j2 = "Array"; j3 = "Integer"; j4 = "Boolean"; j5 = "Float";
        printQuest(1, Soal, j1,j2,j3,j4,j5, JwbUser[0]);

       Soal = "Pointer digunakan untuk menyimpan ...";
       j1 = "Bilangan bulat"; j2 = "Karakter"; j3 = "Variabel";
       j4 = "Memory"; j5 = "Alamat memory";
       printQuest(2, Soal, j1,j2,j3,j4,j5, JwbUser[1]);

       Soal ="Operator referensi biasa disebut juga sebagai...";
       j1 = "Pointer"; j2 = "Nilai"; j3 = "Operator alamat"; j4 = "Memory"; j5 = "Variabel";
       printQuest(3 , Soal, j1,j2,j3,j4,j5, JwbUser[2]);

       Soal = "Operator referensi dilambangkan dengan...";
       j1 = "&"; j2 = "*"; j3 = "%"; j4 = ";"; j5 = "=";
       printQuest(4 ,Soal, j1,j2,j3,j4,j5, JwbUser[3]);

        Soal = "Yang di maksud dengan assignment operator adalah...";
       j1 = "Penjumblahan"; j2 = "Pemberi nilai"; j3 = "Ekspresi pemrograman"; j4 = "Notasi editor"; j5 = "Variabel";
       printQuest(5 ,Soal, j1,j2,j3,j4,j5, JwbUser[4]);

        Soal = "Membalik urutan pada string disebut...";
       j1 = "strrev"; j2 = "Sterlen"; j3 = "Strcat"; j4 = "strlwr"; j5 = "stripr";
       printQuest(6 ,Soal, j1,j2,j3,j4,j5, JwbUser[5]);

         Soal = "Menghitung panjang string dapat dilakukan dengan menggunakan fungsi...";
       j1 = "Compare"; j2 = "equals"; j3 = "append"; j4 = "Length"; j5 = "Merubahnya ke char array";
       printQuest(7 ,Soal, j1,j2,j3,j4,j5, JwbUser[6]);

        Soal = "Funsi dari index pada array yaitu....";
       j1 = "Menunjukan letak atau posisi dari elemwn array"; j2 = "Menggabungkan Nilai dan data dalam suatu program";
       j3 = "Momofikasi tampilan agar terlihat sederhana"; j4 = "Memberika nilai awal terhadap suatu variabel";
       j5 = "Mengolongkan semua variabel yang sama";
       printQuest(8 ,Soal, j1,j2,j3,j4,j5, JwbUser[7]);

        Soal = "Penanganan error dengan throws diletakkan di...";
       j1 = "Di dalam class"; j2 = "Di dalam method"; j3 = "Diluar method"; j4 = "Pendeklarasian class"; j5 = "pendeklarasian method";
       printQuest(9 ,Soal, j1,j2,j3,j4,j5, JwbUser[8]);

        Soal = "Untuk mengurutkan array kita memggunakan sort yang terdapat pada package...";
       j1 = "java.util.Arrays"; j2 = "java.lang.StringBuilder"; j3 = "java.io.Exception"; j4 = "java.util.Scanner"; j5 = "java.io.FileInputStream";
       printQuest(10 ,Soal, j1,j2,j3,j4,j5, JwbUser[9]);

       printUserValue(JwbUser,AnswrTrue, N_angka, N_abjad,status);

       printDataSiswa(usName, usNis, usKelas, usJurusan, N_angka, N_abjad, status);
       goto Restart;

    }else {

    TextjlnRight("Untuk saat ini hanya tersedia kelas x jurusan rpl saja!!",79, 14, 10 , 14, 250);
   kampret(3,20); system("pause");
    goto userdata;
    }





cin.get();
return 0;
}


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

void UserLogin (string Userid){

    char Checking[10] = {'@','g','m','a','i','l','.','c','o','m'};
    char CopyOf[10];
    bool LoginUS = true;
    string errMessage = " ";

while(LoginUS == true){
        system("cls");
        setan:
   textcolor(12); cout << errMessage <<endl;textcolor(15);
    cout <<"Masukan gmail anda  : ";textcolor(8);
    cin >> Userid;
    if (Userid == "admin"){
        break;
    }else if (Userid == "hakiahmad756@gmail.com"){
        errMessage = "Masukan gmail yang lain!!";
         system("cls");
   goto setan;

    }

    int lengthStr = Userid.length();
    char chAry [lengthStr];
    strcpy(chAry, Userid.c_str());

        char Search = '@'; char buffer; int lengthScr = 0; int Else = 0;
            for (int j = 0; j < Userid.length(); j++){
                buffer = chAry[j];
                    if (buffer == Search){
                        lengthScr = j;
                    }else {
                    Else++;
                    }
            }

            for (int c = 0; c < 10; c++){
                CopyOf[c] = chAry[lengthScr];
                lengthScr++;
            }


        int a,b,Fail; Fail = 0;
        for (int r = 0; r < 10; r++){
            a = Checking[r];
            b = CopyOf[r];
                if (a != b){
                    Fail = Fail+1;
                }
        }

        if (Fail > 0){
            LoginUS = true;
            errMessage = " //Masukan gmail anda contoh : hakiahmad756@gmail.com ";
        }
        else {
            LoginUS = false;
        }

    }
    string Pass,KonPass;
    bool Password = true;

        while (Password = true){
                if (Userid == "admin"){
                    break;
                }
                textcolor(15);
            cout <<"Masukan Password    : ";textcolor(8);
                cin >> Pass;
            textcolor(15);
            cout <<"Konfirmasi Password : ";textcolor(8);
                cin >> KonPass;

                if (Pass == KonPass){
                    break;
                }else {
                Password = true;
                system("cls");textcolor(15);
                cout <<"\nMasukan gmail anda  : ";textcolor(8);cout<< Userid;
    textcolor(12); cout <<"  <Password Tidak Sama>"<<endl;
                }
        }

 }
void printQuest(int numQs, string Quest, string jwb1, string jwb2, string jwb3, string jwb4, string jwb5, char &UserJwb){
char jwbUser;

if (numQs == 1){
textcolor(8);
cout <<"Jawablah Pertanyaan Dibawah Ini Denan Baik Dan Jujur!!!"<<endl<<endl;
}

textcolor(15);
cout << numQs <<". "<< Quest<<endl<<endl;
cout <<"   a. "<< jwb1 <<endl;
cout <<"   b. "<< jwb2 <<endl;
cout <<"   c. "<< jwb3 <<endl;
cout <<"   d. "<< jwb4 <<endl;
cout <<"   e. "<< jwb5 <<endl<<endl;
textcolor(12);cout <<"Pilih Jawaban = ";textcolor(7);
    cin >> jwbUser; cout <<endl;
    Sound(5);
    loading(0,79,10,8);
    cout <<endl;

        UserJwb = jwbUser;

    if (numQs == 10){
loading(0,79,9,20);
    textcolor(8); cout <<"                              CONGRATULATION "<<endl;
loading(0,79,9,20);
}

}
void printUserValue (array <char, 10> &Data, array <char, 10> &Correct,int &N_Angka, char &N_Abjad, string &Status){


    textcolor(15); cout <<"Jawaban anda :"<<endl<<endl;
    textcolor(10); cout <<"Green"; textcolor(15); cout <<"(Benar)"<<endl;
    textcolor(12); cout <<"Red"; textcolor(15); cout <<"(Salah)"<<endl<<endl;
        // Menghitung jawaban dari user
    char a,b; int tru,fls; tru = 0; fls = 0;
    for (int i = 0; i < Data.size(); i++){
         textcolor(0); Data[i] = putchar(tolower(Data[i])); // merubah jwban user ke lower case
        a = Data[i]; // Data = Jawaban dari user
        b = Correct[i]; // Correct = Jawaban yang benar
    // Menampilkan jawaban user
            if (a == b){
                textcolor(15);
                    cout <<"  "<< i+1 <<".";
                textcolor(10);
                cout << Data[i] <<endl;
                    tru = tru+1;
            }else {
                textcolor(15);
                    cout <<"  "<< i+1 <<".";
                textcolor(12);
                cout << Data[i] <<endl;
                    fls = fls+1;
            }
            Sleep(200);
    }
    cout <<" "<<endl;
    textcolor(15); cout <<"Benar : "; textcolor(10); cout << tru <<endl; N_Angka = tru;
    textcolor(15); cout <<"Salah : "; textcolor(12); cout << fls <<endl<<endl<<endl;
    system("pause");
    textcolor(15);
    //Merubah ke nilai abjad
            int Val = tru;
                            if(Val <= 10 && Val >= 9){
                                N_Abjad = 'A';
                                Status = "LULUS";
                            }else if(Val <= 8  && Val >= 7){
                                N_Abjad = 'B';
                                Status = "LULUS";
                            }else if(Val <= 6  && Val >= 4){
                                N_Abjad = 'C';
                                Status = "TIDAK LULUS";
                            }else if (Val <= 3 && Val >= 0){
                               N_Abjad = 'D';
                               Status = "TIDAK LULUS";
                              }
}
void UserData (string &User, string &Nis, string &Kelas, string &Jrusan){

bool data = true;
string us,nis,kls,jrsan; string errKelas =" "; string errJrusan = " ";
while (data == true){
      label_continue:
          errJrusan = " "; errKelas = " ";

            system("cls");
textcolor(15);
cout <<" "<<endl<<endl;
kampret(30,1);cout <<"<<<<<<Welcome>>>>>>"<<endl<<endl<<endl;textcolor(12);
cout <<"ISI Data berikut dengan benar!!!"<<endl<<endl;textcolor(15);
textcolor(10);cout <<"Masukan Nama Anda = ";textcolor(15);cin >> us ;
User = us;  Sound(3);
textcolor(10);cout <<"Masukan Nis       = ";textcolor(15);
cin >> nis;  Nis = nis;
Sound(3);
gKelas:
textcolor(10);cout <<"\nMasukan Kelas     : "; textcolor(12); cout<<"   "<< errKelas <<endl; textcolor(15);
cout <<"\n  1. X (sepuluh)"<<endl;
cout <<"  2. XI (sebelas)"<<endl;
cout <<"  3. XII (duabelas) \n"<<endl;
textcolor(14);cout <<"Kelas [1-3] = ";textcolor(15);
cin >>kls;  Sound(3);
gJurusan:
textcolor(10);cout <<"\nPilih Jurusan: "; textcolor(12); cout <<"    "<< errJrusan <<endl<<endl; textcolor(15);
cout <<"  1. Teknik Pemesinan \n";
cout <<"  2. Teknik Instalasi Tenaga Listrik \n";
cout <<"  3. Otomasi Industri \n";
cout <<"  4. Tata Boga \n";
cout <<"  5. Tata Busana \n";
cout <<"  6. Rekayasa Perangkat Lunak "<<endl<<endl;textcolor(14);
cout <<"Pilih[1-6] = ";textcolor(15);
cin >> jrsan;

if (jrsan == "1" || jrsan == "2" || jrsan == "3" || jrsan == "4" || jrsan == "5" || jrsan == "6"){
        data = false;
        Sound(3);
       }else {
            Sound(8); errJrusan = "Jurusan tidak terdatar? Masukan lagi!!!";
            system("cls");
            goto gJurusan;
       }

if (kls == "x" || kls == "X" || kls == "10" || kls == "1"){
        Kelas = "X (sepuluh)";
            data = false;
        }else if (kls == "xi" || kls == "XI" || kls == "11" || kls == "2"){
           Kelas = "XI (sebelas)";
                data = false;
        }else if (kls == "xii" || kls == "XII" || kls == "12" || kls == "3"){
            Kelas = "XII (duabelas)";
            data = false;
        }
        else{
                Sound(8);
                errKelas = "Kelas tidak terdaftar? Cek lagi!!";
                system("cls");
            goto gKelas;
        }


 string jrs = jrsan;
        //string nmjrsn;
            if (jrs == "1"){
                Jrusan = "Teknik Pemesinan";
            }else if (jrs == "2"){
                Jrusan = "Teknik Instalasi Tenaga Listrik";
            }else if (jrs == "3"){
                Jrusan =  "Otomasi Industri";
            }else if (jrs == "4"){
                 Jrusan = "Tata Boga";
            }else if (jrs == "5"){
                 Jrusan = "Tata Busana";
            }else if (jrs == "6"){
                 Jrusan = "Rekayasa Perangkat Lunak";
            }

textcolor(15);  textcolor(9);

cout <<"\n\nSaving Data";textcolor(15);
    for(int r = 0;r <= 2;r++){
        cout<<". ";
            Sleep(1200);
    }cout <<" "<<endl<<endl<<endl;;
   loading(0,79,11,8);
   cout <<" "<<endl<<endl;textcolor(12);


    cout <<"                          Silahkan cek data anda"<<endl<<endl;textcolor(15);
    cout <<"Nama    : "<< us <<endl;
    cout <<"Nis     : "<< nis <<endl;
    cout <<"Kelas   : "<< Kelas <<endl;
    cout <<"Jurusan : "<< Jrusan <<endl;


data = true;
          textcolor(6);  cout <<"\nEdit data y/n : ";
           textcolor(7); char pill; cin >> pill;
                if (pill == 'N' || pill == 'n'){
                    Sound(3);
                    data = false;
                }else if(pill != 'N' || pill != 'n'){
                    Sound(4);
                    goto label_continue;
                }
}//While Data

 textcolor(15);
            cout <<endl;

 loading(0,79,11,8);
}
void printDataSiswa (string Name, string Nis, string Kelas, string Jurusan, int N_angk, char N_abjd, string status){
system("cls");
    textcolor(15);
    cout <<endl<<endl;
    cout <<"Nama        : " << Name <<endl;
    cout <<"Nis         : " << Nis <<endl;
    cout <<"Kelas       : " << Kelas <<endl;
    cout <<"Jurusan     : " << Jurusan <<endl;
    cout <<"Nilai       : " << N_angk*10 <<endl;
    cout <<"Nilai abjad : " << N_abjd <<endl;
    cout <<"Status      : " << status <<endl;

    kampret(2,19);system("pause"); system("cls");

}

void randC (string randStr,int horizl, int vertkl,int lama,int akhir){
        for (int i = 0; i <= akhir; i++){
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
