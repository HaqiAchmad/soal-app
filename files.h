#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <chrono>

namespace files{
    using namespace std;
    using namespace decor;
//    using namespace funct;
    using namespace getValues;
//    using namespace getValues;

void addAccount(){

    char Checking[15] = {'@','g','m','a','i','l','.','c','o','m'};
    char CheckYmai[15] = {'@','y','a','h','o','o','.','c','o','m'};
    char CopyOf[10];
    bool Login = true;
    string Nama ="", Gmail="", errMessage="", errName="", errPassword="";

    fstream addAcc;
    addAcc.open("C:\\MinGW\\codeblock\\Soal APP\\Database\\user\\UserAccount.txt", ios:: app | ios::in | ios::out);

    change:
        system("cls"); textcolor(15);

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << errName <<endl;
    cout <<"Masukan nama anda  : ";
        getline(cin ,Nama);
        getName(Nama); // untuk mendapatkan nilai dari variabel nama

            if (Nama.length() <= 2){
                errName = "Nama terlalu pendek!!";
                goto change;
            }

    // opsi untuk mengubah nama atau lanjut
    cout << Nama <<" akan selalu di gunakan dalam program"<<endl;
    cout <<"ingin mengantinya ? ";
        char pil;
        cin >> pil;

    if (pil == 'y' || pil == 'Y'){ // jika pilihan y user akan menganti nama
        goto change;
    }else if (pil == 'n' || pil == 'N'){ // jika n user akan tidak ingin menganti nama

    }else{
        goto change;
    }


    while (Login == true){

        Terdaftar: // goto
        bool accRegistered = false; // akan berubah menjadi true jika akun gmail sudah terdaftar var ini digunakan untuk menampilkan pesan error
        throwsPass: // goto
        system("cls");

        cout << errPassword <<endl;
        cout << "Masukan gmail anda : ";
            cin >> Gmail;
        getGmail(Gmail);

    /// mengecek yang di masukan user gmail atau bukan
    int lengthStr = Gmail.length();
    char chAry [lengthStr];
    strcpy(chAry, Gmail.c_str());

        char Search = '@'; char buffer; int lengthScr = 0; int Else = 0;
            for (int j = 0; j < Gmail.length(); j++){
                buffer = chAry[j];
                    if (buffer == Search){
                        lengthScr = j;
                        for (int c = 0; c < 10; c++){
                            CopyOf[c] = chAry[lengthScr];
                            lengthScr++;
                                }
                    }else {
                    Else++;
                    }
            }




        int GM,tru,Fail = 0;
        for (int r = 0; r < 10; r++){
            tru = Checking[r];
            GM = CopyOf[r];
                if (tru!= GM){
                    Fail = Fail+1;
                }
        }

       // Gmail = Userid; // Variable Gmail akan di outputkan keluar method
        if (Fail > 0){
            Login = true;
            errMessage = " //Masukan gmail anda contoh : hakiahmad756@gmail.com ";
        }
        else {
            Login = false;
        }
    }

    string Pass,KonPass;
    bool isPassword = true;
    string pesan = "  <Success>";

    /// user memasukan password
    while(isPassword == true){

       ThrowPassword: system("cls");
       textcolor(15); cout <<"\nMasukan Gmail anda  : "; textcolor(8); cout << Gmail; textcolor(12); cout << pesan <<endl;

       textcolor(15); cout <<"Masukan Password    : "; textcolor(8);
          //  cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin,Pass);

         if (Pass.length() <= 5){
            pesan = "  //Password harus >= 6 character";
            system("cls");
            goto ThrowPassword; /// jika password kurang <= 6 maka di throw keatas
         }else
         {
            textcolor(15); cout <<"Konfirmasi Password : "; textcolor(8);
            getline(cin,KonPass);

            /// mengecek apakah password == konfirmasi password
            if (Pass == KonPass){
                break;
        }else if (Pass != KonPass){
            pesan = "  //Password Tidak Sama!!";
            system("cls");
            goto ThrowPassword;
        }
    }

}
        addAcc << Nama.append("\n");
        addAcc << Gmail.append("\n");
        addAcc << Pass.append("\n");

}


void loginUserAccount(){
    string acco, pass, fnName, fnAcc, fnPass, buffer, errMsg;
    ifstream files;
    files.open("C:\\MinGW\\codeblock\\Soal APP\\Database\\user\\UserAccount.txt");
    bool isFind = false, isBlock;
    int chance = 5;

   notFound:
   system("cls"); textcolor(15);
   textcolor(15); cout << errMsg <<endl;
    cout <<"\nMasukan Gmail Anda : "; textcolor(8);
      cin >> acco;

   while (!files.eof()){
     getline(files, buffer);
        fnName = buffer;
    getline(files, buffer);
        fnAcc = buffer;
    getline(files, buffer);
        fnPass = buffer;
    getName(fnName);

        if (fnAcc == acco){
            isFind = true;
            break;
        }
   }

    getGmail(acco);
//    getGmailacco);
    if (isFind == true){

        system("cls");
        textcolor(12); cout << fnAcc <<" ditemukan!!!"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        while(chance >= 1){
        system("cls");
        textcolor(15); cout <<isFind<<"Masukan Gmail Anda : "; textcolor(8); cout << fnAcc; textcolor(11); cout <<" "<< chance <<" kesempatan lagi!"<<endl;
        textcolor(15); cout <<"Masukan Password   : ";
            getline(cin, pass);

            if (pass == fnPass){
                isBlock = false;
                break;
            }else {
                isBlock = true;
            }
            chance-=1;
        }
    }else if (isFind == false){
        errMsg = acco+" belum terdaftar\n Silahkan cek akun anda kembali \n Jika anda belum mempunyai akun silahkan ketik out pada console";
        //goto notFound;
    }

    if (isBlock == false){
        cout <<"Login Success"<<endl;
    }else if (isBlock != false){
        cout <<fnAcc <<" terblokir"<<endl;

    }


}

void getLoginType(){

    int choose;

   TypingTxt("Welcome", 12, 300, 35, 3);
   textcolor(11);
  notFound:
  kampret(0, 9); cout <<"\n    >> 1. Daftar "<<endl;
  kampret(0, 11); cout <<"    >> 2. Masuk "<<endl;
  cout << "Input code [1/2] ";
        cin>> choose;

        if (choose == 1){
            addAccount();

        }else if (choose == 2){
            loginUserAccount();
        }else {
            system("cls");
            goto notFound;
        }

}


 void appClose(){

     Sound(2); system("cls");textcolor(15);
         randC("5.2.4",33,10,300,21);
         kampret(25,19);cout <<endl;
            textcolor(12);
        system("pause");
        textcolor(0);
        return 0;

 }

void readDataUser(){
    ifstream dataUser;
    dataUser.open("C:\\MinGW\\codeblock\\Soal APP\\Database\\user\\DataStatusUser.txt",ios::in);
    string data="",buffer;

    system("cls"); textcolor(8);
    while(!dataUser.eof()){
            getline(dataUser,data);
                cout << data <<endl;
    }
    system("pause");
      textcolor(9);
}

void readUserAccount(){

   ifstream dataUser;
    dataUser.open("C:\\MinGW\\codeblock\\Soal APP\\Database\\user\\UserAccount.txt",ios::in);
    string buffer;

    system("cls"); textcolor(8);
    while(!dataUser.eof()){
            getline(dataUser, buffer);
                cout <<"Username : "<< buffer <<endl;
            getline(dataUser, buffer);
                cout <<"Gmail    : "<< buffer <<endl;
            getline(dataUser, buffer);
                cout <<"Password : "<< buffer <<endl<<endl;
    }
    system("pause");
      textcolor(9);
}


void getOption(){
     string choose; loop:
     kampret(29,11);textcolor(10);
     cout <<"Start Program y/n ? =  "; textcolor(9);
     cin >> choose;

     // ok == sudah di buat
     system("cls");
     if (choose == "y" || choose == "Y"){
        getLoginType();

     }else if (choose == "n" || choose == "N" || choose == "out"){
          appClose(); // ok

     }else if (choose == "read.data" || choose == "##"){
        readDataUser(); // ok
        system("cls");
        goto loop;

     }else if (choose == "read.acc" || choose == "#!"){
        readUserAccount(); //ok
        system("cls");
        goto loop;
     }

}

 void writeDataUser(){

    ofstream DataUser; DataUser.open("C:\\MinGW\\codeblock\\Soal APP\\Database\\user\\DataStatusUser.txt",ios::app);

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

            system("cls");
    int Hrs = timePtr->tm_hour, Min = timePtr->tm_min;
    int day = timePtr->tm_wday, nowDay = timePtr->tm_mday;
    int month = timePtr->tm_mon+1, year = timePtr->tm_year+1900;

    string nmDay = "";
   switch(day){
        case 1:
            nmDay = "Sen, ";
            break;
        case 2:
            nmDay = "Sel, ";
            break;
        case 3:
            nmDay = "Rab, ";
            break;
        case 4:
            nmDay = "Kam, ";
            break;
        case 5:
            nmDay = "Jum, ";
            break;
        case 6:
            nmDay = "Sab, ";
            break;
        case 0:
            nmDay = "Min, ";
            break;
       }

    string line = "\n";
    /// convert int to string
    stringstream hrs, mnt, nwdy, mon, yrs;
    hrs << Hrs; mnt << Min; nwdy << nowDay; mon << month; yrs << year;

    string jam = hrs.str(), menit = mnt.str(), harini = nwdy.str(), bulan = mon.str(), tahun = yrs.str();

    DataUser <<"Gmail    : "; DataUser << setGmail().append("\n");
    DataUser <<"Username : "; DataUser << setName().append("\n");
    DataUser <<"Nis      : "; DataUser << setNis().append("\n");
    DataUser <<"Kelas    : "; DataUser << setKelas().append("\n");
    DataUser <<"Jurusan  : "; DataUser << setJurusan().append("\n");
    DataUser <<"Nilai    : "; DataUser << setVal()*10;
    DataUser <<"\nStatus   : "; DataUser << setStatus().append("\n");
    DataUser <<"Login Time : "; DataUser << jam.append(":"+menit+" ");
    DataUser << nmDay.append(harini+":"+bulan+":"+tahun+"\n\n");

    }
}
