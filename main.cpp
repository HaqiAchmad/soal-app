#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include "namespace\\getValues.h"
#include "namespace\\decor.h"
#include "namespace\\files.h"
#include "namespace\\funct.h"



using namespace std;
using namespace decor;
using namespace getValues;
using namespace funct;
using namespace files;

int main(){

   // ofstream DataUser; UserData.open("UserData.txt",ios::app);

    string  versi = "Version : 5.2.1";
    string Soal,j1,j2,j3,j4,j5;

     array <char, 10> AnswrTrue;
     array <char, 10> JwbUser;

    TypingTxt("Created by : ",12,150,23,10);  randC("Achmad Baihaqi X Kelas Terbuka",36,10,20,15);
   // TypingTxt("XI Rpl 1 | Smk Negeri 1 Kertosono\n\n", 12, 150, 36, 11);
   // system("pause");
        system("cls");

    Restart:
    getOption();

        cout <<" \n"<<endl;textcolor(15);
    cout <<"Loading  ";
loading(0,69,13,12);


userdata:
UserData();


    system("cls");
    if (setKelas() == "X (sepuluh)" && setJurusan() == "Rekayasa Perangkat Lunak"){
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

       printUserValue(JwbUser,AnswrTrue);

       writeDataUser();
       printDataSiswa();

       goto Restart;

    }else {

    TextjlnRight("Untuk saat ini hanya tersedia kelas x jurusan rpl saja!!",79, 14, 10 , 14, 250);
   kampret(3,20); system("pause");
    goto userdata;
    }


cin.get();
return 0;
}



