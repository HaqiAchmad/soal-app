#include <iostream>
#include "namespace\\values.h"
#include "namespace\\decor.h"
#include "namespace\\funct.h"
#include "namespace\\users.h"


using namespace std;
using namespace decor;
using namespace values;
using namespace funct;
using namespace users;


class First{


    public:

    static void deleteFile(string direktori){

        cout << direktori <<endl;
    };

    void renameFile(fstream myFile, string newName){

        fstream buffer; buffer.open("database\\user\\UserAccount.txt");

    };
};


int main(){

    First first;
    first.deleteFile("hello");
    system("pause");
    string filename = "database\\user\\deleteThis.txt";
    int remove(const char* filename);

     system("cls");
     decor::writeText("Created by : ", 12 , 150, 23, 10);  decor::randC("Achmad Baihaqi", 36, 10, 10, 60);//36,10,150,15);

     loop:
     Restart_application:
     system("cls");
     decor::colorPosition(29, 11, 10);

     string choose;
     cout <<"Start Program y/n ? =  "; textcolor(9);
        cin >> choose;

     system("cls");
     if (choose == "y" || choose == "Y"){
        users::getLoginType();

     }else if (choose == "n" || choose == "N" || choose == "out"){
        funct::appClose();
        return 0;
     }else if (choose == "read.data" || choose == "##"){
        funct::readDataUser();
        system("cls");
        goto loop;

     }else if (choose == "read.acc" || choose == "#!"){
        funct::readUserAccount(); //ok
        system("cls");
        goto loop;

     }else{
      goto loop;
     }


    funct::chooseLesson();
    funct::showQuestion();

    funct::writeDataUser();
    funct::printDataSiswa();

    // goto Restart_application;



cin.get();
return 0;
}



