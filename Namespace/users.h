#include <stdlib.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <chrono>

namespace users{
    using namespace std;


void userData(){


    ofstream dataUsers; dataUsers.open("Database\\user\\AccountInformation.txt", ios::app | ios::out);
    ofstream dataUsersBinary; dataUsersBinary.open("Database\\user\\AccountInformation.bin", ios::app | ios::out);
    string Nis, Kelas, Jrusan;
    string inputNis="",inputKelas="",inputJrsan=""; string errKelas =" "; string errJrusan = " ";


    editData:
    errJrusan = " "; errKelas = " "; // mereset value
    system("cls");

    decor::colorPosition(24,3,15);
    cout <<"<<<<<<Informasi Dasar>>>>>>"<<endl<<endl<<endl;decor::textcolor(12);
    cout <<"ISI Data berikut dengan benar!!!"<<endl<<endl;decor::textcolor(15);

    decor::textcolor(10);
    cout <<"Masukan Nama Anda = ";decor::textcolor(15);  cout << getName() <<endl;
    decor::sound(3);

    decor::textcolor(10);
    cout <<"Masukan Nis       = ";  decor::textcolor(15);
        cin >> inputNis;
            values::setNis(inputNis);
            funct::sound(3);


gKelas:
    decor::textcolor(10);cout <<"\nMasukan Kelas     : "; decor::textcolor(12); cout<<"   "<< errKelas <<endl; decor::textcolor(15);
        cout <<"\n  1. X (sepuluh)"<<endl;
        cout <<"  2. XI (sebelas)"<<endl;
        cout <<"  3. XII (duabelas) \n"<<endl; decor::textcolor(14);
        cout <<"Kelas [1-3] = "; decor::textcolor(15);
            cin >> inputKelas;  decor::sound(3);
gJurusan:

    decor::textcolor(10);cout <<"\nPilih Jurusan: "; decor::textcolor(12); cout <<"    "<< errJrusan <<endl<<endl; decor::textcolor(15);
        cout <<"  1. Teknik Pemesinan \n";
        cout <<"  2. Teknik Instalasi Tenaga Listrik \n";
        cout <<"  3. Otomasi Industri \n";
        cout <<"  4. Tata Boga \n";
        cout <<"  5. Tata Busana \n";
        cout <<"  6. Rekayasa Perangkat Lunak "<<endl << endl;decor::textcolor(14);
        cout <<"Pilih[1-6] = ";decor::textcolor(15);
            cin >> inputJrsan;


        // mengecek apakah jurusan yang di masukan user tersedia atau tidak
        string namaJurusan;
        if (inputJrsan == "1" || inputJrsan == "2" || inputJrsan == "3" || inputJrsan == "4" || inputJrsan == "5" || inputJrsan == "6"){

            // mendapatkan nama jurusan
            if (inputJrsan == "1"){
                namaJurusan = "Teknik Pemesinan";
            }else if (inputJrsan == "2"){
                namaJurusan = "Teknik Instalasi Tenaga Listrik";
            }else if (inputJrsan == "3"){
                namaJurusan =  "Otomasi Industri";
            }else if (inputJrsan == "4"){
                 namaJurusan = "Tata Boga";
            }else if (inputJrsan == "5"){
                 namaJurusan = "Tata Busana";
            }else if (inputJrsan == "6"){
                 namaJurusan = "Rekayasa Perangkat Lunak";
            }
            values::setJurusan(namaJurusan);
            decor::sound(3);
       }else {
            decor::sound(8);
            errJrusan = "Jurusan tidak terdatar? Masukan lagi!!!";
            system("cls");
            goto gJurusan;
       }


       // mengecek apakah jurusan yang di masukan user tersedia atau tidak
        if (inputKelas == "x" || inputKelas == "X" || inputKelas == "10" || inputKelas == "1"){
            Kelas = "X (sepuluh)";

        }else if (inputKelas == "xi" || inputKelas == "XI" || inputKelas == "11" || inputKelas == "2"){
           Kelas = "XI (sebelas)";

        }else if (inputKelas == "xii" || inputKelas == "XII" || inputKelas == "12" || inputKelas == "3"){
            Kelas = "XII (duabelas)";

        }else{
                decor::sound(8);
                errKelas = "Kelas tidak terdaftar? Cek lagi!!";
                system("cls");
            goto gKelas;
        }
        values::setKelas(Kelas);


    decor::textcolor(9);

    cout <<"\n\nSaving Data";decor::textcolor(15);
        for(int r = 0;r <= 2;r++){
            cout<<". ";
            Sleep(1200);
        }cout <<" "<<endl<<endl<<endl;;
        decor::loading(0,79,11,8);

        cout <<" "<<endl<<endl;decor::textcolor(12);


    cout <<"                          Silahkan cek data anda"<<endl<<endl;decor::textcolor(15);
    cout <<"Nama    : "<< values::getName() <<endl;
    cout <<"Nis     : "<< values::getNis() <<endl;
    cout <<"Kelas   : "<< values::getKelas() <<endl;
    cout <<"Jurusan : "<< values::getJurusan() <<endl;


          decor::textcolor(6);  cout <<"\nEdit data y/n : ";
          decor::textcolor(7); char pill; cin >> pill;

                if (pill == 'N' || pill == 'n'){
                    decor::sound(3);

                }else if(pill != 'N' || pill != 'n'){
                    decor::sound(4);
                    goto editData;
                }

     decor::textcolor(15);
     cout <<endl;
     decor::loading(0,79,11,8);


     // meinginputkan data dari user ke DataAccount.txt

     dataUsers <<"Nama       : "; dataUsers << values::getName().append("\n");
     dataUsers <<"Email      : "; dataUsers << values::getEmail().append("\n");
     dataUsers <<"Password   : "; dataUsers << values::getPassword().append("\n");
     dataUsers <<"Nis        : "; dataUsers << values::getNis().append("\n");
     dataUsers <<"Kelas      : "; dataUsers << values::getKelas().append("\n");
     dataUsers <<"Jurusan    : "; dataUsers << values::getJurusan().append("\n");
     dataUsers <<"Dibuat     : "; dataUsers << funct::getTimeNow().append("\n\n");
}



void addAccount(){

    bool Login = true, isPassword = false;
    string Nama ="", Email="", Password="", KonPassword="";
    string errName="null", errEmail="null", errPassword="null", findEmail="";

    array <string, 3> rulesName {"Nama harus >= 4 character\n",  "Anda bisa menggunakan nama pendek ataupun nama panjang\n", "Dilarang mengunakan nama yang mengundang kebencian"};
    array <string, 3> rulesEmail {"Masukan email anda contoh : Project@mycode.com\n","Panjang email anda harus antara 6 dan 30 karakter\n","                        "};
    array <string, 3> rulesPassword {"Password harus >= 6 character\n", "Gunakan gabungan angka, huruf kecil dan besar\n", "Jangan gunakan identitas atau informasi terkait anda sebagai password"};

    fstream addAcc;
    addAcc.open("Database\\user\\UserAccount.txt", ios:: app | ios::in | ios::out);


    changeName:
        system("cls"); decor::textcolor(15);
        decor::showRules(0, 6, rulesName, errName); //menampilkan aturan penulisan nama di posisi 0, 8
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

    decor::gotoxy(0,1); decor::textcolor(15);
    cout <<"Masukan nama anda  : "; decor::textcolor(8);
        getline(cin ,Nama);
            values::setName(Nama); // untuk mendapatkan nilai dari variabel nama

            // jika nama kurang <= 4 character maka nama tidak valid
            if (Nama.length() <= 2){
                errName = "Nama terlalu pendek!!";
                goto changeName;
            }


    // opsi untuk mengubah nama atau lanjut
    decor::textcolor(11);
    cout <<" "<< endl <<Nama ;
    decor::textcolor(12);
    cout <<" akan selalu di gunakan dalam program!"<<endl;

    decor::textcolor(14);
    char pil;
    cout <<"ingin mengantinya(y/n) ";
    decor::textcolor(15);
         cin >> pil;


    if (pil == 'y' || pil == 'Y'){
        errName = "";
        goto changeName;
    }else if (pil == 'n' || pil == 'N'){

    }else{
        goto changeName;
    }


    while (Login == true){

        notEmail:
        Terdaftar:
        system("cls");
        decor::showRules(0, 3, rulesEmail, errEmail);

        decor::textcolor(15);
        decor::gotoxy(0,1);
        cout << "Masukan Email anda : "; decor::textcolor(8);
            cin >> Email;
            funct::toLower(Email);
                setEmail(Email); // mendapatkan value dari variabel Email


        bool contain = funct::containEmail(Email, errEmail);
            if (contain == true){
                isPassword = true;
                break;
            }else{
                goto notEmail;
            }

    }

    string path = "Database\\user\\UserAccount.txt";
    bool search = funct::searchKata_file(Email, path);

        if (search == true){
            errEmail = "nama pengguna sudah terdaftar, coba yang lain";
            goto Terdaftar;
        }else if (search == false){
            //pass
        }

    while(isPassword == true){

       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       invalidPassword:
       system("cls");
       decor::showRules(0, 5, rulesPassword, errPassword);

       // menampilkan
       decor::gotoxy(0,1);
       decor::textcolor(15);
       cout <<"Masukan email anda : "; decor::textcolor(8); cout << Email <<endl;

       decor::textcolor(15);
       cout <<"Masukan password   : "; decor::textcolor(8);
            getline(cin, Password);
            values::setPassword(Password);

        decor::textcolor(15);
        cout <<"Kofirmasi password : "; decor::textcolor(8);
            getline(cin, KonPassword);

       bool isPass = funct::isPassword(Password, KonPassword, errPassword);
            if (isPass == true){
                break;
            }else{
                goto invalidPassword;
            }

    }

        // meginputkan nama, email & password ke UserAccount.txt
        addAcc << values::getName().append("\n");
        addAcc << values::getEmail().append("\n");
        addAcc << values::getPassword().append("\n");

        // menjalankan method pengisian data diri user
        users::userData();

}

void loginUserAccount(){

    returnBack:
    ifstream file; file.open("Database\\user\\UserAccount.txt", ios::in);
    string inputEmail="", inputPassword="", errMessage="";
    string findName="", findEmail="", findPassword="";
    bool isFind = true, wrongPassword = false, failPassword = false;
    int chance = 4;



    notFoundAccount:
    // menampilkan action di posisi 0, 8 (bagian input email)
    //===================================================================================================================
    notFoundCode:
    system("cls");
    decor::loadingGotoxy(0, 8, 9, 0, '+');
    decor::loadingGotoxy(0, 19, 9, 0, '+');

    // action jika account tidak ditemukakan
    decor::colorPosition(0,10);

        char codeError;
        if (isFind == false){

            cout << inputEmail; decor::textcolor(12); cout << errMessage <<endl; // menampilkan error message jika akun tidak ditemukan
            // user diberikan pilihan untuk daftar akun atau coba lagi
            decor::textcolor(10);
                cout <<"\nBelum memiliki akun?" <<endl <<endl;
            decor::textcolor(13);
                cout <<"  1. daftar sekarang!\n";
                cout <<"  2. coba lagi?\n\n";
            decor::textcolor(15);
                cout <<"input code[1/2]? "; decor::textcolor(8);
                    cin >> codeError;

                    if (codeError == '1'){ // jika input user bernilai 1 maka akan daftar account
                        addAccount();
                    }else if (codeError == '2'){ // jika 2 maka akan coba lagi
                        goto returnBack;
                    }else {
                        errMessage + (" (pilih 1/2)"); // jika input tidak bernilai 1 atau 2 maka akan loop ke atas
                        goto notFoundCode;
                    }
        }



    //===================================================================================================================


    isFind = NULL; //  mereset nilai isFind
    decor::colorPosition(0, 1, 15);
    cout <<"Masukan email anda    : "; decor::textcolor(8);
        cin >> inputEmail;
        funct::toLower(inputEmail);
// mengecek emaisl yang di inputkan user ada atau tidak di dalam database
       while(!file.eof()){
            getline(file, findName);
            getline(file, findEmail);
            getline(file, findPassword);

                if (inputEmail == findEmail){// jika email yang di inputkan user ditemukan maka akan mengahasilkan nilai dari variabael isFind bernilai true dan jika tidak ditemukan maka hasilnya false
                    isFind = true;
                    values::setName(findName);
                    values::setEmail(findEmail);
                    break;
                }else{
                    isFind = false;
                }

       }

// menampilkan action di posisi 0, 8 (bagian input password)
//========================================================================================================================
       invalidPassword: notInput:
       system("cls");
       decor::loadingGotoxy(0, 8, 9, 0, '+');
       decor::loadingGotoxy(0, 19, 9, 0, '+');

    if (wrongPassword == true){

        decor::teksJalan_kanan(errMessage, 79, 2, 10, 12, 20);
    }else{

        decor::teksJalan_kanan("Ketikan Password!", 79, 2, 10, 12, 20);
    }


    chance_null:
    char pils;
    if (chance <= 0){

        decor::colorPosition(1, 8, 11);
            cout << "\n\nMenemui kesulitan dalam memasukan password?" <<endl <<endl;
        decor::textcolor(13);
            cout <<"  1. Forgot password:" <<endl;
            cout <<"  2. Coba lagi" <<endl;
            cout <<"  3. Gunakan akun yang lain" <<endl;
        decor::textcolor(15);
            cout <<"\ninput code[1/3]? "; decor::textcolor(8);
                cin >> pils;

                if (pils == '1'){
                    funct::forgotPassword(inputEmail);
                }else if(pils == '2'){
                    chance = 5;
                }else if (pils == '3'){
                    system("cls");
                    goto returnBack; //  akan loop keatas dibagian input email
                }else{
                    wrongPassword = false; //  agar program melewati if wrongpassword
                    goto notInput;
                }


    }



//=======================================================================================================================
    // action jika variabel isFind bernilai true disini user akan menginputkan password
    if (isFind == true){
        // user mempunyai kesampatan 5 kali dalam memasukan password jika tetap salah memasukan password maka akan dikenakan maintenace selama 5 min
        while(chance <= 5){

            decor::colorPosition(0, 1, 15);
                cout <<"Masukan email anda    : "; decor::textcolor(8); cout << inputEmail <<endl;
            decor::textcolor(15);
                cout <<"Masukan password anda : "; decor::textcolor(8);
                    getline(cin, inputPassword);
                    //cin.ignore(numeric_limits<streamsize>::max(),'\n');

                    chance -= 1;
                    if (inputPassword == findPassword){
                        break;

                    }else if (inputPassword != findPassword){
                        errMessage = "Password yang anda masukan tidak cocok! ";
                        wrongPassword = true;
                        goto invalidPassword;

                    }else if (chance <= 0){
                        failPassword = true;
                        goto chance_null;

                    }

        }// end while

    // action jika variabel isFind bernilai false
    }else if(isFind == false){

        errMessage = " tidak ditemukan coba yang lain";
        goto notFoundAccount;
    }

        funct::getAccountInformation(inputEmail);
        values::setKelas("X (sepuluh)");


}


void getLoginType(){

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    ifstream kata;
    char choose; string ucapan;
    int Jam = timePtr->tm_hour; // <-- mendapatkan waktu di komputer
    int sec;
    string Motivasi="", spasi = "-             ";

    notFound: // goto : jika input dari user tidak ditemukan
    kata.open("Database\\teks\\motivasi\\motivasi.txt");

    sec = timePtr->tm_sec + 1;
    for (int q = 0; q <= sec; q++){
        getline(kata, Motivasi);
    }
    kata.close();

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


    decor::loadingGotoxy(0, 2, 9, 1, '+'); // menampilkan efek garis di gotoxy(0,3); (bagian atas console)
    decor::loadingGotoxy(79, 22, 9, 1, '-'); // menampilkan efek garis di gotoxy(0,22); (bagian bawah console)

    // menambahkan spasi di tengah" kata (agar tampilan lebih cantik saat di tampilkan di console)
    if (Motivasi.length() >= 66){
        Motivasi.insert(66, spasi);
    }
    if (Motivasi.length() >= 147){
        Motivasi.insert(147, spasi);
    }
    if (Motivasi.length() >= 224){
        Motivasi.insert(224, spasi);
    }
    if (Motivasi.length() >= 303){
        Motivasi.insert(303, spasi);
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
            //sfunct::UserData():
        }else if (choose == '2'){
            loginUserAccount(); // Log in dengan akun yang sudah ada
        }else {
            system("cls");
            sec = 0; // mereset detik
            goto notFound; // jika pilihan tidak ditemukan maka akan dilempar ke atas lagi
        }



 }


void deleteAccount(string isDelete){


    fstream account; account.open("Database\\user\\UserAccount.txt", ios::in);
    fstream buffer; buffer.open("Database\\user\\buffer account.txt",ios::out | ios::app);
    string nama, email, password;

    while(!account.eof()){

        getline(account, nama);
        getline(account, email);
        getline(account, password);

            if(email == isDelete){

                continue;

            }else{
                buffer << nama.append("\n");
                buffer << email.append("\n");
                buffer << password.append("\n");

            }



    }



 }

} // end namespace users










