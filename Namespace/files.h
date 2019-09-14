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
    using namespace getValues;
    using namespace decor;


void addAccount(){

    char Checking[15] = {'@','g','m','a','i','l','.','c','o','m'};
    char CheckYmai[15] = {'@','y','a','h','o','o','.','c','o','m'};
    char CopyOf[10];
    bool Login = true;
    string Nama ="", Gmail="", errName="", errGmail="", errPassword="";

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
                errName = "Nama terlalu pendek!!"; // jika input nama kurang dari 2 character maka akan goto change:
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

        cout << errGmail <<endl;
        cout << "Masukan gmail anda : ";
            cin >> Gmail;
        getGmail(Gmail); // mendapatkan value dari variabel Gmail

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



        // mengecek apakah yang dimasuakan user gmail atau bukan
        int GM,tru; bool Fail = false;
        for (int r = 0; r < 10; r++){
            tru = Checking[r];
            GM = CopyOf[r];
                if (tru!= GM){
                    Fail = true;
                }
        }

       // Gmail = Userid; // Variable Gmail akan di outputkan keluar method
        if (Fail == true){
            Login = true;
            errGmail = " //Masukan gmail anda contoh : hakiahmad756@gmail.com ";
        }
        else {
            Login = false;
        }
    }// end while

    string Pass,KonPass;
    bool isPassword = true;
    string pesan = "  <Success>";

    /// user memasukan password
    while(isPassword == true){

        // menampilkan gmail yang dimasukan user ke console
       ThrowPassword: system("cls");
       textcolor(15); cout <<"\nMasukan Gmail anda  : "; textcolor(8); cout << Gmail; textcolor(12); cout << pesan <<endl;

       textcolor(15); cout <<"Masukan Password    : "; textcolor(8);
            getline(cin,Pass);

         if (Pass.length() <= 5){  // jika password kurang <= 6 maka di throw keatas
            pesan = "  //Password harus >= 6 character";
            system("cls");
            goto ThrowPassword;
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
    string inputUser, pass, fnName, fnAcc, fnPass, buffer, errMsg;
    ifstream files;
    files.open("C:\\MinGW\\codeblock\\Soal APP\\Database\\user\\UserAccount.txt");
    bool isFind = false, isBlock;
    int chance = 5;

   notFound:
   system("cls"); textcolor(15);
   textcolor(15); cout << errMsg <<endl;
    cout <<"\nMasukan Gmail Anda : "; textcolor(8);
      cin >> inputUser;

   while (!files.eof()){

    getline(files, buffer);
        fnName = buffer;
    getline(files, buffer);
        fnAcc = buffer;
    getline(files, buffer);
        fnPass = buffer;
    getName(fnName);

        if (fnAcc == inputUser){ // jika akun di temukan maka bool isFind akan true
            isFind = true;
            break;
        }
   }
    getGmail(inputUser); // mendapatkan value dari variabel inputUser

    if (isFind == true){

        // action jika bool isFind bernilai true
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
        errMsg = inputUser+" belum terdaftar\n Silahkan cek akun anda kembali \n Jika anda belum mempunyai akun silahkan ketik out pada console";
        //goto notFound;
    }

    if (isBlock == false){
        cout <<"Login Success"<<endl;
    }else if (isBlock != false){
        cout <<fnAcc <<" terblokir"<<endl;

    }

}

void getLoginType(){

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    char choose; string ucapan; 
    int Jam = timePtr->tm_hour; // <-- mendapatkan waktu di komputer

    // string Motivasi = "cara termudah jadi pandai adalah belajar dari hal terbodoh yang pernah kamu lakukan.";
    // string Motivasi = "Dengan begitu kemampuanmu akan lebih berkembang lagi. Dan pastinya, kamu tak akan jatuh ke lubang yang sama dua kali. Kata kata motivasi belajar ini cocok banget nih buat yang lagi menyesali kesalahan di masa lalu.";
    string Motivasi = "Padahal sebenarnya, pendidikan yang kamu sebut menjengkelkan ini berkah lho. Karena berkatnya mungkin kamu bisa jadi orang hebat, bisa meraih cita cita yang diidamkan dan bisa meraih kehidupan yang berkecukupan di masa depan.";
    string spasi = "-             ";

    // mendeteksi waktu apakah pagi, siang, sore, petang atau malam
    if (Jam <= 9 && Jam >= 5){ // pagi dimulai jam 5 sampai 9
        ucapan = "Selamat Pagi";
    }else if (Jam <= 14 && Jam >= 10){ // siang dimulai jam 10 sampai 14
        ucapan = "Selamat Siang";
    }else if (Jam <= 17 && Jam >= 15){ // sore dimulai jam 15 sampai 17
        ucapan = "Selamat Sore";
    }else if (Jam <= 19 && Jam >= 18){ // petang dimulai jam 18 sampai 19
        ucapan = "Selamat Petang";
    }else if (Jam <= 23 && Jam >= 20){ // malam dimulai jam 20 sampai 23
        ucapan = "Selamat Malam";
    }else if (Jam <= 4 && Jam >= 0){ // malam dimulai jam 0 sampai 4
        ucapan = "Selamat Malam";
    }

    notFound: // goto : jika input dari user tidak ditemukan

    cout << endl <<endl;
    decor::loading(1,80,9,1); // menampilkan efek garis di gotoxy(0,3);

    decor::gotoxy(0,22);
    decor::loading(1,80,9,1); // menampilkan efek garis di gotoxy(0,22);


    // menambahkan spasi di tengah" kata (agar tampilan lebih cantik saat di tampilkan di console)
    if (Motivasi.length() >= 66){ 
    Motivasi.insert(66, spasi); 
    }
    if (Motivasi.length() >= 147){
    Motivasi.insert(147, spasi);
    }
    if (Motivasi.length() >= 226){
    Motivasi.insert(226, spasi);
    }
    if (Motivasi.length() >= 306){
    Motivasi.insert(306, spasi);
    }
    if (Motivasi.length() >= 385){
        Motivasi.insert(385, spasi);
    }

    // menampilkan ucapan Selamat Pagi/Siang/Sore/Petang/Malam di gotoxy (33,4) dengan color light green
    decor::gotoxy(33,4); decor::textcolor(10); 
    cout << ucapan <<endl;

    // menampilkan value variabel Motivasi di gotoxy(1,15);
    decor::gotoxy(3,15); decor::textcolor(15);
    cout <<"Note : "; decor::textcolor(8); cout << Motivasi <<endl; 

    // menapilkan pilihan menu Created account di gotoxy(3,9);
    decor::gotoxy(3, 9); decor::textcolor(10);
    cout <<">>"; decor::textcolor(15); cout <<" 1. ";decor::textcolor(12); cout <<"Created account!"<<endl;
    // menampilkan pilihan menu Have a account already? di gotoxy(3,10);
    decor::gotoxy(3, 10); decor::textcolor(10);
    cout <<">>"; decor::textcolor(15); cout <<" 2. ";decor::textcolor(12); cout <<"Have a account already?"<<endl;
    // menampilkan Input Code[1/2]? : di gotoxy (3,14) dengan color light yellow
    decor::gotoxy(3, 12); decor::textcolor(14);
    cout <<"Input code[1/2]? "; 
    decor::textcolor(15); cout <<"-> "; decor::gotoxy(24,12); cout <<" <-" <<endl; // membuat efek anak panah
    // mendapatkan input dari user
    decor::textcolor(11); decor::gotoxy(23, 12);
    cin >> choose; 

        if (choose == '1'){
            addAccount(); // menambahkan akun
        }else if (choose == '2'){
            loginUserAccount(); // Log in dengan akun yang sudah ada
        }else {
            system("cls");
            goto notFound; // jika pilihan tidak ditemukan maka akan dilempar ke atas lagi
        }



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
