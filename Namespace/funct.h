#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <chrono>

using namespace getValues;

namespace funct{
    using namespace std;
    using namespace decor;

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
textcolor(12);cout <<"Pilih Jawaban : "; textcolor(8);
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
void printUserValue (array <char, 10> &Data, array <char, 10> &Correct){

    int N_Angka;
    char N_Abjad;
    string Status;

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
     getVal(N_Angka);
     getVal_abj(N_Abjad);
     getStatus(Status);
}
void UserData (){

string User, Nis, Kelas, Jrusan;
bool data = true;
string us,nis,kls,jrsan; string errKelas =" "; string errJrusan = " ";
while (data == true){
      label_continue:
          errJrusan = " "; errKelas = " ";

            system("cls");
textcolor(15);
cout <<" "<<endl<<endl;
gotoxy(30,1);cout <<"<<<<<<Welcome>>>>>>"<<endl<<endl<<endl;textcolor(12);
cout <<"ISI Data berikut dengan benar!!!"<<endl<<endl;textcolor(15);
textcolor(10);cout <<"Masukan Nama Anda = ";textcolor(15); cout << setName() <<endl;
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
    cout <<"Nama    : "<< setName() <<endl;
    cout <<"Nis     : "<< nis <<endl;    getNis(nis);
    cout <<"Kelas   : "<< Kelas <<endl;  getKelas(Kelas);
    cout <<"Jurusan : "<< Jrusan <<endl; getJurusan(Jrusan);


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
void printDataSiswa (){
system("cls");
    textcolor(15);
    cout <<endl<<endl;
    cout <<"Nama        : " << setName() <<endl;
    cout <<"Nis         : " << setNis() <<endl;
    cout <<"Kelas       : " << setkelas <<endl;
    cout <<"Jurusan     : " << setJurusan() <<endl;
    cout <<"Nilai       : " << setVal() <<endl;
    cout <<"Nilai abjad : " << setVal_abj() <<endl;
    cout <<"Status      : " << setStatus() <<endl;

    gotoxy(2,19);system("pause"); system("cls");

}

 void appClose(){

     Sound(2); system("cls");textcolor(15);
         randC("5.2.4",33,10,300,21);
         gotoxy(25,19);cout <<endl;
            textcolor(12);
        system("pause");
        textcolor(0);

 }



}// end namaspace
