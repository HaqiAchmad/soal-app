#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

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

 void UserLogin (string Userid){

    char Checking[10] = {'@','g','m','a','i','l','.','c','o','m'};
    char CopyOf[10];
    bool LoginUS = true;
    string errMessage = " ";

while(LoginUS == true){
        system("cls");
   textcolor(12); cout << errMessage <<endl;textcolor(15);
    cout <<"Masukan gmail anda  : ";textcolor(8);
    cin >> Userid;

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

           // cout <<"lengthSrc = " << lengthScr <<"\nnot : " << Else <<endl;

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


void jwb(char pil,char jwb);
void jwbn(char pil,char jwbn,char bsr);
void value();
void loading(int aw,int akr);
int Nilai(int val [10]);


int main(){


    string nis,kls,usLogin,versi; versi = "Version : 5.1.1";
    int jrsan; int awal = 0; int akhir = 79;
    char pil;
    bool sigin = true;
    float value1,value2,value3,value4,value5;
    float value6,value7,value8,value9,value10;

    char soal1,soal2,soal3,soal4,soal5,soal6;
    char soal7,soal8,soal9,soal10;

  //  label_continue:
  textcolor(9);
 kampret(23,10); cout <<"Created by : ";textcolor(15); randC("hakiahmad756@gmail.com",36,10,250,25);
        system("cls");
    kampret(29,11);textcolor(12);
    cout <<"Start Program y/n ? =  ";
    cin >> pil;
    cout <<" \n";
     string us,ps,kon;

    if (pil == 'a'){
        us == "admin";
        ps == "123";
        kon == "123";
    }
    else if (pil == 'y' || pil == 'Y'){
            Sound(1);
        while (sigin == true){
                system("cls");
                cout <<" "<<endl;
                textcolor(15);
            UserLogin(usLogin);
                textcolor(15);
            cout <<"Masukan Password    : ";
            textcolor(8);
                cin >> ps;
                textcolor(15);
            cout <<"Konfirmasi Password : ";
            textcolor(8);
                cin >> kon;
            if(ps == kon){
                Sound(3);
                sigin = false;
        }else{
            Sound(6);
            pil == 'y'; pil == 'Y';
            }
     }
     }else if(pil != 'y' || pil != 'Y'){
         Sound(2);
         /*
     while(true){
            textcolor(0);
        cout <<" ";
     }
     */system("cls");textcolor(15);
       randC("Version : 5.1.1",33,10,300,40);
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
for(int i = 0;i <= 69;i++){
    textcolor(12);cout <<"=";
    //cout <<"*";
    Sleep(40);
    // 30,27  7,31
}
bool data = true;
//bool klas = true;
//bool jrusann = true;
while (data == true){
      label_continue:
       //bool jrusann = true;
      //  while (jrusann == true){
            system("cls");
textcolor(15);
cout <<" "<<endl<<endl;
kampret(30,1);cout <<"<<<<<<Welcome>>>>>>"<<endl<<endl<<endl;textcolor(12);
cout <<"ISI Data berikut dengan benar!!!"<<endl<<endl;textcolor(15);
textcolor(10);cout <<"Masukan Nama Anda = ";textcolor(15);cin >> us ;Sound(3);
textcolor(10);cout <<"Masukan Nis       = ";textcolor(15); cin >> nis;
Sound(3);
textcolor(10);cout <<"\nMasukan Kelas     : \n";textcolor(15);
cout <<"\n  1. X (sepuluh)"<<endl;
cout <<"  2. XI (sebelas)"<<endl;
cout <<"  3. XII (duabelas) \n"<<endl;
textcolor(14);cout <<"Kelas [1-3] = ";textcolor(15);cin >>kls;
Sound(3);
textcolor(10);cout <<"\nPilih Jurusan: \n"<<endl;textcolor(15);
cout <<"  1. Teknik Pemesinan \n";
cout <<"  2. Teknik Instalasi Tenaga Listrik \n";
cout <<"  3. Otomasi Industri \n";
cout <<"  4. Tata Boga \n";
cout <<"  5. Tata Busana \n";
cout <<"  6. Rekayasa Perangkat Lunak "<<endl<<endl;textcolor(14);
cout <<"Pilih[1-6] = ";textcolor(15);
cin >> jrsan;

        if (jrsan > 6 || jrsan < 1){
                Sound(8);
            goto label_continue;
        }else {
        data = false;
        Sound(3);
        }
if (kls == "x" || kls == "X" || kls == "10" || kls == "1"){
            data = false;
        }else if (kls == "xi" || kls == "XI" || kls == "11" || kls == "2"){
            data = false;
        }else if (kls == "xii" || kls == "XII" || kls == "12" || kls == "3"){
            data = false;
        }
        else{
                Sound(8);
            goto label_continue;
        }



//}//end while jrusann
//jrsan = jrsn;
textcolor(15);

textcolor(9);

cout <<"\n\nSaving Data";textcolor(15);
    for(int r = 0;r <= 2;r++){
        cout<<". ";
            Sleep(1200);
    }cout <<" "<<endl<<endl<<endl;;
    for(int y = 0;y <= 79;y++){textcolor(11);
    cout <<"=";
    Sleep(8);
    }textcolor(15);
   cout <<" "<<endl<<endl;textcolor(12);

  //  bool jurusann = true;

    cout <<"                          Silahkan cek data anda"<<endl<<endl;textcolor(15);
    cout <<"Nama    : "<< us <<endl;
    cout <<"Nis     : "<< nis <<endl;
    cout <<"Kelas   : ";
        //int clas = kls;
                if(kls == "1" || kls == "x" || kls == "X" || kls == "10"){
                    cout <<"X (sepuluh)"<<endl;
                }else if (kls == "2" || kls == "xi" || kls == "XI" || kls == "11"){
                    cout <<"XI (sebelas)"<<endl;
                    }else if(kls == "3" || kls == "xii" || kls == "XII" || kls == "12"){
                    cout <<"XII (duabelas)"<<endl;
                    }
    cout <<"Jurusan : ";
    int jrs = jrsan;
        //string nmjrsn;
            if (jrs == 1){
                cout <<"Teknik Pemesinan "<<endl;
            }else if (jrs == 2){
                cout <<"Teknik Instalasi Tenaga Listrik "<<endl;
            }else if (jrs == 3){
                cout <<"Otomasi Industri "<<endl;
            }else if (jrs == 4){
                cout <<"Tata Boga "<<endl;
            }else if (jrs == 5){
                cout <<"Tata Busana"<<endl;
            }else if (jrs == 6){
                cout<<"Rekayasa Perangkat Lunak "<<endl;
            }
                int az = 0;
data = true;
          textcolor(6);  cout <<"\nEdit data y/n : ";
           textcolor(7); char pill; cin >> pill;
                if (pill == 'N' || pill == 'n'){
                        Sound(3);
                    data = false;
                }
                else if(pill != 'N' || pill != 'n'){
                    Sound(4);
                    goto label_continue;
                }

}//While Data

 textcolor(15);
       // cout <<" "<<endl;
      //  cout <<"\nGood Luck ("<<us<<") ";
            cout <<" "<<endl;
//cout <<" "<<endl<<endl;
for (int a = 0;a <= 79;a++){textcolor(11);
    cout <<"=";//<<endl;
        Sleep(8);
}


enum jrsn{mesin = 1,listrik, otomasi, busana, boga, rpl};
    switch(jrsan){
        case mesin:
        cout <<"Belum Tersedia \n";
            break;
        case listrik:
        cout <<"Belum Tersedia \n";
            break;
        case otomasi:
        cout <<"Belum Tersedia \n";
            break;
        case boga:
        cout <<"Belum Tersedia \n";
            break;
        case busana:
        cout <<"Belum Tersedia \n";
            break;
        case rpl:
            bool RPL = true;
            while(RPL = true){
                    system("cls");
            cout <<" \n"<<endl;
textcolor(8);
cout <<"Jawablah Pertanyaan Dibawah Ini Denan Baik Dan Jujur!!!"<<endl<<endl;textcolor(15);
cout <<"1. Dalam menyusun satu program langkah pertama yang harus dilakukan adalah . . ."<<endl;
cout <<"   a. Membeli Komputer"<<endl;
cout <<"   b. Menulis algoritma"<<endl;
cout <<"   c. Mempelajari bahasa pemroraman"<<endl;
cout <<"   d. Mempelajari Program"<<endl;
cout <<"   e. Mendownload IDE"<<endl<<endl;
textcolor(12);cout <<"Pilih Jawaban = ";textcolor(7);
    cin >> soal1;
    cout <<" ";
   if(soal1 == 'b' || soal1 == 'B'){
     value1 = 10;
   }
    else if(soal1 != 'b' || soal1 != 'B'){
        value1 = 0;
    }cout <<" "<<endl;
        Sound(5);
        loading(awal,akhir);

    cout <<" "<<endl;textcolor(15);
cout <<"2. Apabila a=5, b=10, maka jika di berikan instruksi a=b; b=a akan menjadi . . ."<<endl;
cout <<"   a. a=0, b=5"<<endl;
cout <<"   b. a=10, b=5"<<endl;
cout <<"   c. a=10, b=0"<<endl;
cout <<"   d. a=b"<<endl;
cout <<"   e. a=10, b=10"<<endl<<endl;
textcolor(7);
textcolor(12);cout <<"Pilih Jawaban = ";textcolor(7);
    cin >> soal2;
    cout <<" ";
   if(soal2 == 'e' || soal2 == 'E'){
     value2 = 10;
   }
    else if(soal2 != 'e' || soal2 != 'E'){
        value2 = 0;
    }cout <<" "<<endl;
    Sound(5);
    loading(awal,akhir);
    cout <<" "<<endl;
    textcolor(15);
    cout <<"3. Siapakah penemu bahasa pemrograman c++ . . ."<<endl<<endl;
    cout <<"   a. Dr.harcules"<<endl;
    cout <<"   b. Prof.niklaus smirth"<<endl;
    cout <<"   c. Bjarne stroustrup"<<endl;
    cout <<"   d. James Gosling"<<endl;
    cout <<"   e. Bill gates"<<endl;
    cout <<" "<<endl;
    textcolor(12);
    cout <<"Pilih Jawaban = ";textcolor(7);
    cin >> soal3;
    if (soal3 == 'c' || soal3 == 'C'){
        value3 = 10;
    }else if(soal3 != 'c' || soal3 != 'C'){
        value3 = 0;
        }
        Sound(5);
        cout <<" "<<endl;
       loading(awal,akhir);

cout <<" "<<endl;
textcolor(15);
cout <<"4. Bilangan yang berisi titik desimal atau jenis bilangan pecahan adalah . . ."<<endl<<endl;
cout <<"   a. String "<<endl;
cout <<"   b. Boolean "<<endl;
cout <<"   c. Real "<<endl;
cout <<"   d. Float "<<endl;
cout <<"   e. Integer "<<endl<<endl;textcolor(12);
cout <<"Pilih Jawaban = ";textcolor(7);//cout <<" ";
cin >> soal4;
if (soal4 == 'c' ||soal4 == 'C'){
    value4 = 10;
}else if(soal4 != 'c' || soal4 != 'C'){
    value4 = 0;
    }
    cout <<" "<<endl;
    Sound(5);
    loading(awal,akhir);
    textcolor(15);
    cout <<" "<<endl;
    cout <<"5. Array linear dapat disebut juga . . ."<<endl<<endl;
    cout <<"   a. Array multi dimensi"<<endl;
    cout <<"   b. Subscript " <<endl;
    cout <<"   c. Indeks array "<<endl;
    cout <<"   d. Array satu dimensi"<<endl;
    cout <<"   e. Array dua dimensi "<<endl<<endl;
    textcolor(12);
    cout <<"Pilih Jawaban = ";textcolor(7);
    cin >> soal5;
    if (soal5 == 'd' || soal5 == 'D'){
        value5 = 10;
    }else if(soal5 != 'd' || soal5 != 'D'){
        value5 = 0;
        }
        cout <<" "<<endl;
    Sound(5);
       loading(awal,akhir);
        textcolor(15);
        cout <<" "<<endl;
        cout <<"6. Pointer digunakan untuk menyimpan . . ."<<endl<<endl;
        cout <<"   a. Bilangan bulat"<<endl;
        cout <<"   b. Bilangan rasional \n";
        cout <<"   c. Karakter \n";
        cout <<"   d. Address memory \n";
        cout <<"   e. Bilangan real \n";
        cout <<" "<<endl;textcolor(12);
        cout <<"Pilih Jawaban = ";textcolor(7);
        cin >> soal6;
        if(soal6 == 'd' || soal6 == 'D'){
            value6 = 10;
        }else if(soal6 != 'd' || soal6 != 'D'){
            value6 = 0;
            }
            cout <<" "<<endl;
        Sound(5);
            loading(awal,akhir);
            cout <<" \n";

            textcolor(15);
            cout <<"7. Pengembalian dari nilai fungsi ke luar fungsi disebut . . ."<<endl<<endl;
            cout <<"   a. Statement/pernyataan "<<endl;
            cout <<"   b. Return "<<endl;
            cout <<"   c. Nama_fungsi "<<endl;
            cout <<"   d. Argument "<<endl;
            cout <<"   e. Tipe_data"<<endl<<endl;textcolor(12);
            cout <<"Pilih jawaban = ";textcolor(7);
            cin >> soal7;
            cout <<" "<<endl;
            if (soal7 == 'b' || soal7 == 'B'){
                value7 = 10;
            }else if(soal7 != 'b' || soal7 != 'B'){
                value7 = 0;
                }
                Sound(5);
                loading(awal,akhir);
                textcolor(15);
            cout <<" "<<endl;
            cout <<"8. Jumblah maksimal panjang string adalah . . ."<<endl;
            cout <<"   a. Tak Terhingga"<<endl;
            cout <<"   b. 200" <<endl;
            cout <<"   c. 255"<<endl;
            cout <<"   d. 300"<<endl;
            cout <<"   e. 355" <<endl<<endl;
            textcolor(12);
            cout <<"Pilih Jawaban = ";textcolor(7);
            cin >> soal8;
            if(soal8 == 'c' || soal8 == 'C'){
                value8 = 10;
            }else if(soal8 != 'c' || soal8 != 'C'){
                value8 = 0;
                }
                cout <<" \n";
                    Sound(5);
                loading(awal,akhir);

                cout <<" \n";textcolor(15);
                cout <<"9. Sintaks java untuk menampilkan kompilasi terhadap berkas program adalah . . ."<<endl;//<<endl;
                cout <<"   a. java \n";
                cout <<"   b. javac \n";
                cout <<"   c. javaclass \n";
                cout <<"   d. javax \n";
                cout <<"   e. Semua salah \n"<<endl;textcolor(12);
                cout <<"Pilih Jawaban = ";textcolor(7);
                    cin >> soal9;
                    if(soal9 == 'b' || soal9 == 'B'){
                        value9 = 10;
                    }else if(soal9 != 'b' || soal9 != 'B'){
                        value9 = 0;
                        }
                        cout <<" "<<endl;
                    Sound(5);
                       loading(awal,akhir);
                cout <<" "<<endl;
               textcolor(15);
         cout <<"10. Perhatikan pengalan program berikut ini :"<<endl<<endl;
        cout <<"       ";textcolor(13);cout <<"public ";textcolor(11);cout <<"class ";textcolor(10);cout <<"Main";textcolor(15);cout <<"{"<<endl;
        textcolor(13);cout <<"       public static";textcolor(11);cout <<" void ";textcolor(10);cout <<"main";textcolor(15);cout <<"(";textcolor(11);cout<<"String";textcolor(12);cout<<" args ";textcolor(13);cout <<"[]";textcolor(15);cout <<"){"<<endl;
        textcolor(11);  cout<<"          int ";textcolor(15);cout<<"a "; textcolor(13);cout<<"= ";textcolor(5);cout<<"21";textcolor(15);cout<<"; ";textcolor(11);cout<<"int ";textcolor(15);cout<<"b "; textcolor(13);cout<<"= ";textcolor(5);cout<<"2";textcolor(15);cout<<";";
        textcolor(11);  cout<<"\n            int ";textcolor(15);cout<<"c "; textcolor(13);cout<<"= ";textcolor(15);cout<<"a ";textcolor(13);cout <<"% ";textcolor(15);cout<<"b; "<<endl;
                      cout <<"              c ";textcolor(13);cout<<"+=";textcolor(5);cout<<"5"<<endl;
        textcolor(11); cout <<"       System";textcolor(15);cout<<".out.";textcolor(11);cout<<"println";textcolor(15);cout<<"(";textcolor(6);char c = '"';cout << c <<"Nilai Awal  = "<< c ;textcolor(12);cout <<"+ ";textcolor(15);cout <<" c);"<<endl;
        textcolor(11); cout <<"       System";textcolor(15);cout<<".out.";textcolor(11);cout<<"println";textcolor(15);cout<<"(";textcolor(6);char f = '"';cout << f <<"Nilai Akhir = "<< f ;textcolor(12);cout <<"+ ";textcolor(15);cout <<" ++c);"<<endl;
                      cout <<"           }"<<endl;
                      cout <<"       } \n"<<endl;//<<endl;
                      cout <<"   Output dari program tersebut adalah . . ."<<endl<<endl;
                       cout <<"   a. Nilai awal = 0, Nilai akhir = 1 \n";
                       cout <<"   b. Nilai awal = 1, Nilai akhir = 1 \n";
                       cout <<"   c. Nilai awal = 0, Nilai akhir = 0 \n";
                       cout <<"   d. Nilai awal = 0.5 ,Nilai akhir =1.5  \n";
                       cout <<"   e. Error "<<endl<<endl;textcolor(12);
                       cout <<"Pilih jawaban = ";textcolor(7);
                        cin >> soal10;
                        if(soal10 == 'a' || soal10 == 'A'){
                            value10 = 10;
                        }else if(soal10 != 'a' || soal10 != 'A'){

                        }
                        cout <<" "<<endl;
                        Sound(5);
                            //cout <<value10<<endl;

                break;
//           int []new= value[1]+value[2]+value[3]+val[4]+val[5]+val[6]+val[7]+val[8]+val[9]+val[10];
                int out = 0;
                    if(out == 0){
                        RPL = false;
                    }
            }//End While RPL
    } //Switch case

            for (int g = 1;g <= 80;g++){
        textcolor(9);
            cout <<"=";
            Sleep(20);
    }
           textcolor(8); cout <<"                              CONGRATULATION "<<endl;

            for (int g = 1;g <= 80;g++){
        textcolor(9);
            cout <<"=";
            Sleep(20);
    }

    float hs = value1+value2+value3+value4+value5+value6+value7+value8+value9+value10;
    char sl1,sl2,sl3,sl4,sl5,sl6,sl7,sl8,sl9,sl10;
    sl1 = 'b';sl2 = 'e';sl3 = 'c';sl4 = 'c';sl5 = 'd';
    sl6 = 'd';sl7 = 'b';sl8 = 'c';sl9 = 'b';sl10 = 'a';

    char bl1,bl2,bl3,bl4,bl5,bl6,bl7,bl8,bl9,bl10;
    bl1 = 'B';bl2 = 'E';bl3 = 'C';bl4 = 'C';bl5 = 'D';
    bl6 = 'D';bl7 = 'B';bl8 = 'C';bl9 = 'B';bl10 = 'A';
        Sound(4);
   textcolor(15); cout <<"Jawaban Anda :"<<endl<<endl;
                 textcolor(10); cout <<"Green";textcolor(15);cout <<"(Benar)"<<endl;
                 textcolor(12); cout <<"Red";textcolor(15);cout <<"(Salah)"<<endl<<endl;

                cout<<"   1.";jwbn(soal1,sl1,bl1);textcolor(15);textcolor(15);cout<<"   2.";jwbn(soal2,sl2,bl2);textcolor(15);cout<<"   3.";jwbn(soal3,sl3,bl3);
                textcolor(15); cout <<"   4.";jwbn(soal4,sl4,bl4);textcolor(15);cout<<"   5.";jwbn(soal5,sl5,bl5);textcolor(15);cout<<"   6.";jwbn(soal6,sl6,bl6);
                textcolor (15);cout <<"   7.";jwbn(soal7,sl7,bl7);textcolor(15);cout<<"   8.";jwbn(soal8,sl8,bl8);textcolor(15);cout<<"   9.";jwbn(soal9,sl9,bl9);
                textcolor (15);cout <<"  10.";jwbn(soal10,sl10,bl10);
                 int benar = hs / 100 * 10;
                 int salah = 10-benar ;textcolor(15);
                 cout <<"\nBenar : ";textcolor(10);cout<< benar <<endl;textcolor(15);
                 cout <<"Salah : ";textcolor(12);cout<< salah <<endl<<endl;textcolor(13);system("pause");
                 cout <<"Press any key to continue . . .";

                        system("cls");



                            textcolor(15);
                   cout <<"Nama        : "<< us <<endl;
    cout <<"Nis         : "<< nis <<endl;
    cout <<"Kelas       : ";
        //int clas = kls;
                if(kls == "1" || kls == "x" || kls == "X" || kls == "10"){
                    cout <<"X (sepuluh)"<<endl;
                }else if (kls == "2" || kls == "xi" || kls == "XI" || kls == "11"){
                    cout <<"XI (sebelas)"<<endl;
                    }else if(kls == "3" || kls == "xii" || kls == "XII" || kls == "12"){
                    cout <<"XII (duabelas)"<<endl;
                    }
    cout <<"Jurusan     : ";
    int jrs = jrsan;
        //string nmjrsn;
            if (jrs == 1){
                cout <<"Teknik Pemesinan "<<endl;
            }else if (jrs == 2){
                cout <<"Teknik Instalasi Tenaga Listrik "<<endl;
            }else if (jrs == 3){
                cout <<"Otomasi Industri "<<endl;
            }else if (jrs == 4){
                cout <<"Tata Boga "<<endl;
            }else if (jrs == 5){
                cout <<"Tata Busana"<<endl;
            }else if (jrs == 6){
                cout<<"Rekayasa Perangkat Lunak "<<endl;
            }

                cout <<"Nilai angka : "<< hs <<endl;
                   int a = hs;string na,lls;
                            if(a <= 100 && a >= 90){
                                na = "A";
                                lls = "LULUS";
                            }else if(a <= 80  && a >= 70){
                                na = "B";
                                lls = "LULUS";
                            }else if(a <= 60  && a >= 40){
                                na = "C";
                                lls = "TIDAK LULUS";
                            }else if (a <= 30 && a >= 0){
                              na = "D";
                              lls = "TIDAK LULUS";
                              }
                     cout <<"Nilai abjad : "<< na;
                    cout <<"\nStatus      : "<<lls<<endl<<endl<<endl<<endl;


                system("pause");

cin.get();
return 0;
}//pill = jawaban user ||| jwb = jawaban yang benar
void jwb(char pil,char jwbn){
    if (pil == jwbn){
        textcolor(10);
        cout <<pil<<endl;
    }else if (pil != jwbn){
        textcolor(12);
        cout <<pil<<endl;
        }

}
void jwbn(char pil,char jwbn,char bsr){
    if (pil == jwbn || pil == bsr){
        textcolor(10);
        cout <<pil<<endl;
    }else if (pil != jwbn || pil != bsr){
        textcolor(12);
        cout <<pil<<endl;
        }

}
void loading (int aw,int akr){
    for (;aw <= akr;aw++){
        textcolor(10);
            cout <<"=";
            Sleep(10);
    }
}
/*int Nilai(){
int jmblaval;
return jmblaval = val1+val2+val3+val4+val5+val6+val7+val8+val9+val10;
}
*/
