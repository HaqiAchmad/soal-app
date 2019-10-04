#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <chrono>
#include <array>





using namespace values;

namespace funct{
    using namespace std;
    using namespace decor;

string toLower(string &input){

    string buffer = input;
    for (int i = 0; i <= input.length(); i++){
        buffer[i] = putchar(tolower(buffer[i]));
    }

   return input = buffer;
}

string intToStr(int input){

    string str;
    stringstream ss;
    ss << input;

    return str = ss.str();

}

string getTimeNow(){

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    string timeNow="", nameDay="";

    // mendapatkan waktu sekarang
    int hrs = timePtr->tm_hour;
    int mnt = timePtr->tm_min;
    int dayIntWeek = timePtr->tm_wday;
    int dayIntMonth = timePtr->tm_mday;
    int month = timePtr->tm_mon+1;
    int year = timePtr->tm_year+1900;

   // mengecek sekarang hari apa(senin/selasa/rabu/dll)
   switch(dayIntWeek){
        case 1:
            nameDay = "Sen, ";
            break;
        case 2:
            nameDay = "Sel, ";
            break;
        case 3:
            nameDay = "Rab, ";
            break;
        case 4:
            nameDay = "Kam, ";
            break;
        case 5:
            nameDay = "Jum, ";
            break;
        case 6:
            nameDay = "Sab, ";
            break;
        case 0:
            nameDay = "Min, ";
            break;
       }

    // convert int to strings
    string jam = funct::intToStr(hrs);
    string menit = funct::intToStr(mnt);
    string hari = funct::intToStr(dayIntMonth);
    string bulan = funct::intToStr(month);
    string tahun = funct::intToStr(year);

    return timeNow + jam + ":" + menit + " " + nameDay + hari + ":" + bulan + ":" + tahun;
}


void toBinaryFile(){


    values::Accounts akun;
    fstream txtFile; txtFile.open("database\\user\\AccountInformation.txt");
    fstream binFile; binFile.open("database\\user\\AccountInformation.bin",ios::out | ios::app | ios::binary);

    string bufEmail, bufPass, bufNama, bufNis, bufKelas, bufJurusan, ignored;

    while(!txtFile.eof()){

        getline(txtFile, bufNama);
        getline(txtFile, bufEmail);
        getline(txtFile, bufPass);
        getline(txtFile, bufNis);
        getline(txtFile, bufKelas);
        getline(txtFile, bufJurusan);
        getline(txtFile, ignored);
        getline(txtFile, ignored);



        cout << bufNama.substr(13, bufNama.length()) <<endl;
        cout << bufEmail.substr(13, bufEmail.length()) <<endl;
        cout << bufPass.substr(13, bufPass.length()) <<endl;
        cout << bufNis.substr(13, bufNis.length()) <<endl;
        cout << bufKelas.substr(13, bufKelas.length()) <<endl;
        cout << bufJurusan.substr(13, bufJurusan.length()) <<endl;

        system("pause");

        akun.nama = bufNama.substr(13, bufNama.length());
        akun.email = bufNama.substr(13, bufEmail.length());
        akun.password = bufNama.substr(13, bufPass.length());
        akun.nis = bufNama.substr(13, bufNis.length());
        akun.kelas = bufNama.substr(13, bufKelas.length());
        akun.jurusan = bufNama.substr(13, bufJurusan.length());


        binFile.write(reinterpret_cast<char*>(&akun), sizeof(akun));


    }
}


values::Accounts readBinaryFile(int posisi){


    values::Accounts akun;
    fstream file; file.open("database\\user\\AccountInformation.bin", ios::in | ios::binary);

    file.seekp((posisi-1) * sizeof(values::Accounts));
    file.read(reinterpret_cast<char*>(&akun), sizeof(values::Accounts));

    return akun;

}

void readFile(fstream &data){

    string buffer, baca = "";
    long index = 0;
    // string bufAry [100000];

    while(!data.eof()){

        data >> buffer;
        cout << baca <<endl;
        cout << buffer <<endl;
        Sleep(100);
    }

}


void printDataBinary(values::Accounts myData){


    string myName = myData.nama, myEmail = myData.email , myPass = myData.password;


    cout << myName  <<endl;
    cout << myEmail   <<endl;
    cout << myPass  <<endl;
    cout << myData.nis.length()  <<endl;
    cout << myData.kelas.length() <<endl;
    cout << myData.jurusan.length()  <<endl;

}

bool containNumbers(string text){

    char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char check;
    bool contain;
    for(int i = 0; i < text.length(); i++){
        for(int j = 0; j < 10; j++){
            check = text[i];
            if(check == numbers[j]){
                contain = true;
                break;
            }else{
                contain = false;
            }
        }
    }

    return contain;
}


bool containEmail(string email, string &errMessage){

    int pos1 = email.find("@"); // mencari @
    int pos2 = email.find(".com"); // mencari .com

    /*
     note : pajang email harus di antara 6 hingga 30 character
     jika lebih atau kurang maka hasilnya akan false
     */
    if (pos1 <= 30 && pos1 >= 6 && pos2 < 50 && pos2 >= 6){
        return true;

    }else if (pos1 > 30){
        errMessage = "Panjang email anda lebih dari 30 character!";
        return false;
    }else if (pos1 < 6){
        errMessage = "Panjang email anda kurang dari 6 character!";
        return false;
    }else{
        errMessage = "Masukan email contoh : Project@mycode.com";
        return false;
    }

}


bool isPassword(string password, string konPassword, string &errMessage){

    bool contain = containNumbers(password);

    if (contain == false && password.length() > 8 && password == konPassword){
        errMessage = "Gunakan kombinasi angka!";
        return false;
    }else if (password.length() <= 8){
        errMessage = "Gunakan 8 karakter atau lebih untuk kata sandi anda!";
        return false;
    }else if (password != konPassword){
        errMessage = "Kata sandi tidak cocok!";
        return false;
    }else{
        return true;
    }


}

void copyFile(fstream &file, fstream &blankFile){

    string buffer;
    while(!file.eof()){

        getline(file, buffer);
        blankFile << buffer.append("\n");


    }

}

void changePassword(string inputEmail){

    fstream account; account.open("database\\user\\UserAccount.txt", ios::in);
    fstream infoAcc; infoAcc.open("database\\user\\AccountInformation.txt", ios::in);
    fstream bufAccount; bufAccount.open("database\\user\\temp UserAccount.txt", ios::trunc | ios::out);
    fstream bufInfoAcc; bufInfoAcc.open("database\\user\\temp AccountInformation.txt",ios::trunc | ios::out);

    string newPassword, konPassword, errMessage, getTime, ignore;
    values::Accounts bufferAcc, bufferInfo;

    wrong:
    system("cls");
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    decor::loadingGotoxy(0, 4, 9, 10);
    decor::loadingGotoxy(79, 20, 9, 10, '-');
    decor::colorPosition(0, 22, 12);
    cout << errMessage <<endl;


    decor::colorPosition(0, 6 ,15);
    cout <<"Email\t\t\t: " << inputEmail <<endl;

    cout <<"Password baru\t\t: ";
        getline(cin, newPassword);
        if (newPassword.length() < 8){
            errMessage = "Password harus >= 8 character!";
            goto wrong;
        }else if(funct::containNumbers(newPassword) == false){
            errMessage = "Password harus mengandung angka!";
            goto wrong;
        }

    cout <<"Konfirmasi Password\t: ";
        getline(cin, konPassword);
        if(konPassword != newPassword){
            errMessage = "Konfirmasi password tidak cocok!";
            goto wrong;
        }


        while(!account.eof()){

            getline(account, bufferAcc.nama);
            getline(account, bufferAcc.email);
            getline(account, bufferAcc.password);

            if (bufferAcc.email == inputEmail){

                bufAccount << bufferAcc.nama.append("\n");
                bufAccount << bufferAcc.email.append("\n");
                bufAccount << newPassword.append("\n");

            }else{

                bufAccount << bufferAcc.nama.append("\n");
                bufAccount << bufferAcc.email.append("\n");
                bufAccount << bufferAcc.password.append("\n");

            }

        }



       while(!infoAcc.eof()){

            getline(infoAcc, bufferInfo.nama);
            getline(infoAcc, bufferInfo.email);
            getline(infoAcc, bufferInfo.password);
            getline(infoAcc, bufferInfo.nis);
            getline(infoAcc, bufferInfo.kelas);
            getline(infoAcc, bufferInfo.jurusan);
            getline(infoAcc, getTime);
            getline(infoAcc, ignore);



            if (bufferInfo.email.substr(13) == inputEmail){

                bufInfoAcc << bufferInfo.nama.append("\n");
                bufInfoAcc << bufferInfo.email.append("\n");
                bufInfoAcc << "Password   : "; bufInfoAcc << newPassword;
                bufInfoAcc << bufferInfo.nis.append("\n");
                bufInfoAcc << bufferInfo.kelas.append("\n");
                bufInfoAcc << bufferInfo.jurusan.append("\n");
                bufInfoAcc << getTime.append("\n\n");
            }else {

                bufInfoAcc << bufferInfo.nama.append("\n");
                bufInfoAcc << bufferInfo.email.append("\n");
                bufInfoAcc << bufferInfo.password.append("\n");
                bufInfoAcc << bufferInfo.nis.append("\n");
                bufInfoAcc << bufferInfo.kelas.append("\n");
                bufInfoAcc << bufferInfo.jurusan.append("\n");
                bufInfoAcc << getTime.append("\n\n");
            }
       }

      
      account.close();
      account.open("databse\\user\\UserAccount.txt", ios::trunc);
      account.close();
      account.open("database\\user\\UserAccount.txt", ios::out);
      account.close();
      remove("database\\user\\UserAccount.txt");

      if (remove("database\\user\\UserAccount.txt") != 0){
        cout << remove("database\\user\\UserAccount.txt");
        cout <<"anjing";
      }


}


void forgotPassword(string inputEmail){

    fstream account; account.open("database\\user\\UserAccount.txt", ios::in);
    fstream infoAcc; infoAcc.open("database\\user\\AccountInformation.txt", ios::in);
    string inputNis, inputKelas, inputJurusan, ignore;
    values::Accounts buffer;
    int cocok = 0;


    system("cls");
    while(!infoAcc.eof()){

        getline(infoAcc, buffer.nama);
        getline(infoAcc, buffer.email);
        getline(infoAcc, buffer.password);
        getline(infoAcc, buffer.nis);
        getline(infoAcc, buffer.kelas);
        getline(infoAcc, buffer.jurusan);
        getline(infoAcc, ignore);
        getline(infoAcc, ignore);

            if (buffer.email.substr(13) == inputEmail){

                decor::textcolor(15);
                cout << "\n\nMasukan nis anda     : "; decor::textcolor(8);
                    cin >> inputNis;

                decor::textcolor(15);
                cout << "Masukan kelas anda   : \n";
                cout <<"\t1. sepuluh\n";
                cout <<"\t2. sebelas\n";
                cout <<"\t3. duabelas\n";
                cout <<"input code[1-3]? "; decor::textcolor(8);
                    cin >> inputKelas;

                decor::textcolor(15);
                cout << "Masukan jurusan anda : \n";
                cout <<"\t1. Teknik Pemesinan \n";
                cout <<"\t2. Teknik Instalasi Tenaga Listrik \n";
                cout <<"\t3. Otomasi Industri \n";
                cout <<"\t4. Tata Boga \n";
                cout <<"\t5. Tata Busana \n";
                cout <<"\t6. Rekayasa Perangkat Lunak "<<endl;
                cout <<"Input code[1-6]? "; decor::textcolor(8);
                    cin >> inputJurusan;

                    break;
            }

    }

    if (buffer.nis.substr(13) == inputNis){
        cocok += 1;
    }else{
        cocok -= 1;
    }

    if (inputKelas == "1" && buffer.kelas.substr(13) == "X (sepuluh)"){
        cocok += 1;
    }else if(inputKelas == "2" && buffer.kelas.substr(13) == "XI (sebelas)"){
        cocok += 1;
    }else if(inputKelas == "3" && buffer.kelas.substr(13) == "XII (duabelas)"){
        cocok += 1;
    }else{
        cocok -= 1;
    }

    if(inputJurusan == "1" && buffer.jurusan.substr(13) == "Teknik Pemesinan"){
        cocok += 1;
    }else if(inputJurusan == "2" && buffer.jurusan.substr(13) == "Teknik Instalasi Tenaga Listrik"){
        cocok += 1;
    }else if(inputJurusan == "3" && buffer.jurusan.substr(13) == "Otomasi Industri"){
        cocok += 1;
    }else if(inputJurusan == "4" && buffer.jurusan.substr(13) == "Tata Boga"){
        cocok += 1;
    }else if(inputJurusan == "5" && buffer.jurusan.substr(13) == "Tata Busana"){
        cocok += 1;
    }else if(inputJurusan == "6" && buffer.jurusan.substr(13) == "Rekayasa Perangkat Lunak"){
        cocok += 1;
    }


    if (cocok >= 3){
        funct::changePassword(inputEmail);
    }else {
        cout << "data tidak cocok " << cocok <<endl;
    }

    system("pause");

}

bool searchKata_file(string search, string path){

    string buffer;
    bool isFind;
    fstream file;
    file.open(path,ios::in);

    while(!file.eof()){
        getline(file, buffer);

             if(buffer == search){
                 isFind = true;
                 break;
             }else {
                 isFind = false;
             }
    }
    return isFind;
}



void getAccountInformation(string inputEmail){


    ifstream file; file.open("Database\\user\\AccountInformation.txt");

    string findName="", findEmail="", findPassword="", findNis="", findKelas="", findJurusan="", findDibuat="", ignoreLine="";

    while(!file.eof()){

        getline(file, findName);
        getline(file, findEmail);
        getline(file, findPassword);
        getline(file, findNis);
        getline(file, findKelas);
        getline(file, findJurusan);
        getline(file, ignoreLine);
        getline(file, ignoreLine);

            if (findEmail.substr(13, findEmail.length()) == inputEmail){

                values::setName(findName.substr(13, findName.length()));
                values::setEmail(findEmail.substr(13, findEmail.length()));
                values::setPassword(findPassword.substr(13, findPassword.length()));
                values::setNis(findNis.substr(13, findNis.length()));
                values::setKelas(findKelas.substr(13, findKelas.length()));
                values::setJurusan(findJurusan.substr(13, findJurusan.length()));

                break;
            }


    }


 } 


 void writeDataUser(){

    ofstream DataUser; DataUser.open("Database\\user\\DataStatusUser.txt",ios::app);

    DataUser <<"Email    : "; DataUser << values::getEmail().append("\n");
    DataUser <<"Username : "; DataUser << values::getName().append("\n");
    DataUser <<"Nis      : "; DataUser << values::getNis().append("\n");
    DataUser <<"Kelas    : "; DataUser << values::getKelas().append("\n");
    DataUser <<"Jurusan  : "; DataUser << values::getJurusan().append("\n");
    DataUser <<"Mapel    : "; DataUser << values::getMapel().append("\n");
    DataUser <<"Nilai    : "; DataUser << values::getVal()*10;
    DataUser <<"\nStatus   : "; DataUser << values::getStatus().append("\n");
    DataUser <<"ExamTime : "; DataUser << funct::getTimeNow().append("\n\n");


}



void printUserValue (array <char, 10> &inputAnsw, array <char, 10> &correct){

    int N_Angka;
    char N_Abjad;
    string Status;

    decor::textcolor(15); cout <<"Jawaban anda :"<<endl<<endl;
    decor::textcolor(10); cout <<"Green"; decor::textcolor(15); cout << "(Benar)" << endl;
    decor::textcolor(12); cout <<"Red"; decor::textcolor(15); cout << "(Salah)" << endl <<endl;

    char a,b;
    int tru = 0, fls = 0;
    for (int i = 0; i < inputAnsw.size(); i++){

        decor::textcolor(0);
        inputAnsw[i] = putchar(tolower(inputAnsw[i]));  // merubah jwban user ke lower case
        correct[i] = putchar(tolower(correct[i]));
        a = inputAnsw[i];      // Data = Jawaban dari user
        b = correct[i];  // Correct = Jawaban yang benar

           // Menampilkan jawaban user ke console
            if (a == b){
                decor::textcolor(15);
                    cout <<"  "<< i+1 <<".";
                decor::textcolor(10);
                    cout << inputAnsw[i] <<endl;
                    tru = tru+1;
            }else {
                decor::textcolor(15);
                    cout <<"  "<< i+1 <<".";
                decor::textcolor(12);
                    cout << inputAnsw[i] <<endl;
                    fls = fls+1;
            }

    Sleep(200);
    }


    cout <<" "<<endl;
    decor::textcolor(15); cout <<"Benar : "; decor::textcolor(10); cout << tru <<endl; N_Angka = tru;
    decor::textcolor(15); cout <<"Salah : "; decor::textcolor(12); cout << fls <<endl<<endl<<endl;
    system("pause");
    decor::textcolor(15);


            //Merubah ke nilai abjad
        if(tru <= 10 && tru >= 9){
            N_Abjad = 'A';
            Status = "LULUS";
        }else if(tru <= 8  && tru >= 7){
            N_Abjad = 'B';
            Status = "LULUS";
        }else if(tru <= 6  && tru >= 4){
            N_Abjad = 'C';
            Status = "TIDAK LULUS";
        }else if (tru <= 3 && tru >= 0){
            N_Abjad = 'D';
            Status = "TIDAK LULUS";
        }


     setVal(N_Angka);
     setVal_abj(N_Abjad);
     setStatus(Status);
}


void printDataSiswa (){
    system("cls");

    decor::textcolor(15);
    cout <<endl<<endl;
    cout <<"Nama        : " << values::getName() <<endl;
    cout <<"Nis         : " << values::getNis() <<endl;
    cout <<"Kelas       : " << values::getKelas() <<endl;
    cout <<"Jurusan     : " << values::getJurusan() <<endl;
    cout <<"Mapel       : " << values::getMapel() <<endl;
    cout <<"Nilai       : " << values::getVal() <<endl;
    cout <<"Nilai abjad : " << values::getVal_abj() <<endl;
    cout <<"Status      : " << values::getStatus() <<endl;

    decor::gotoxy(2,19);
    system("pause");
    system("cls");

}


void chooseLesson(){

   system("cls");
   char input;
   string mapel="";
 //================================================================================================================
    decor::loadingGotoxy(0, 14, 3, 9, '+');
    decor::loadingGotoxy(79, 23, 3, 9, '-');



 //===============================================================================================================


    decor::colorPosition(27,1,12);
        cout << "Pilih mata pelajaran" <<endl;


        if (values::getKelas() == "X (sepuluh)"){

            decor::colorPosition(0, 5, 15);
            cout <<" >> 1. Bahasa Indonesia"<<endl;
            cout <<" >> 2. Matematika"<<endl;
            cout <<" >> 3. Fisika"<<endl;
            cout <<" >> 4. Kimia"<<endl;
            cout <<" >> 5. Bahasa Inggris"<<endl;


            decor::textcolor(9);
            cout <<"\nInput Code : " ; decor::textcolor(4);
                cin >> input;

                switch(input){
            case '1':
                values::setPath("X\\Bahasa Indonesia.txt");
                mapel = "Bahasa Indonesia";
                break;
            case '2':
                values::setPath("X\\Matematika.txt");
                mapel = "Matematika";
                break;
            case '3':
                values::setPath("X\\Fisika.txt");
                mapel = "Fisika";
                break;
            case '4':
                values::setPath("X\\Kimia.txt");
                mapel = "Kimia";
                break;
            case '5':
                values::setPath("X\\Bahasa Inggris.txt");
                mapel = "Bahasa Inggris";
                break;
                }


        }else if (values::getKelas() == "XI (sebelas)"){

        }else if (values::getKelas() == "XII (duabelas)"){

        }

    setMapel(mapel);

}

void showQuestion(){

    string direktori = "Database\\question\\" + values::getPath();
    ifstream lesson;  lesson.open(direktori);
    string ques="", answ1="", answ2="", answ3="", answ4="", answ5="", answTrue="";
    char inputAnsw;
    array <char, 10> correct;
    array <char, 10> userAnsw;

    system("cls");
    decor::textcolor(8);
    cout <<"Jawablah pertanyaan di bawah ini dengan benar!!"<<endl <<endl;

    int number = 1, True = 0;
    while(!lesson.eof()){

        getline(lesson, ques);
        getline(lesson, answ1);
        getline(lesson, answ2);
        getline(lesson, answ3);
        getline(lesson, answ4);
        getline(lesson, answ5);
        getline(lesson, answTrue);

            // menambahkan enter jika ques.length >= 76 (agar tulisan terlihat rapih)
            if (ques.length() >= 76){
                ques.insert(76, "-   ");
            }

            decor::textcolor(15);
                cout << number << ". " << ques <<endl <<endl;
                cout <<"   a. " << answ1 <<endl;
                cout <<"   b. " << answ2 <<endl;
                cout <<"   c. " << answ3 <<endl;
                cout <<"   d. " << answ4 <<endl;
                cout <<"   e. " << answ5 <<endl << endl;

                decor::textcolor(12);
                    cout <<"Pilih Jawaban : "; decor::textcolor(8);
                        cin >> inputAnsw;

                        cout << endl;
                        decor::loading(0, 79, 10, 8);
                        cout << endl;

                  correct[number-1] =  answTrue[0];
                  userAnsw[number-1] = inputAnsw;

        number++;

    }



    printUserValue(userAnsw, correct);

}


void readDataUser(){

    ifstream dataUser;
    dataUser.open("Database\\user\\DataStatusUser.txt",ios::in);
    string data="",buffer;

    system("cls"); decor::textcolor(8);
    while(!dataUser.eof()){
            getline(dataUser,data);
                cout << data <<endl;
    }
    system("pause");
      decor::textcolor(9);
}

void readUserAccount(){

   ifstream dataUser;
    dataUser.open("Database\\user\\UserAccount.txt",ios::in);
    string buffer;

    system("cls"); decor::textcolor(8);
    while(!dataUser.eof()){
            getline(dataUser, buffer);
                cout <<"Username : "<< buffer <<endl;
            getline(dataUser, buffer);
                cout <<"Email    : "<< buffer <<endl;
            getline(dataUser, buffer);
                cout <<"Password : "<< buffer <<endl<<endl;
    }
    system("pause");
      decor::textcolor(9);
}



 void appClose(){

     decor::sound(2); system("cls");decor::textcolor(15);
         decor::randC("5.2.4",33, 10, 300, 21);
         decor::gotoxy(25,19);cout <<endl;
            decor::textcolor(12);
        system("pause");
        decor::textcolor(0);

 }




}// end namaspace
