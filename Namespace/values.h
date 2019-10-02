#include <iostream>


namespace values{

using namespace std;


 struct Accounts{

    string email, password;
    string nama, nis, kelas, jurusan;
        
};

    string setemail, setname, setpassword;
    string setnis, setkelas, setjurusan, setstatus;
    string setpath, setmapel;
    int setnilai;
    char setval_abj;

    /*
    set = mendapatkan value dari variabel lain
    get = berisi value dari variabel yang diambil dari fungsi set
    */

    void setEmail(string Email){
        setemail = Email;
    }
    void setName(string name){
        setname = name;
    }
    void setPassword(string pass){
        setpassword = pass;
    }
    void setNis(string nis){
        setnis = nis;
    }
    void setKelas(string kelas){
        setkelas = kelas;
    }
    void setJurusan(string jurusan){
        setjurusan = jurusan;
    }
    void setVal(int value){
        setnilai = value;
    }
    void setVal_abj(char chr){
        setval_abj = chr;
    }
    void setStatus(string status){
        setstatus = status;
    }
    void setPath(string path){
        setpath = path;
    }
    void setMapel(string mapel){
        setmapel = mapel;
    }


    string getEmail(){
        return setemail;
    }
    string getName(){
        return setname;
    }
    string getPassword(){
        return setpassword;
    }
    string getNis(){
        return setnis;
    }
    string getKelas(){
        return setkelas;
    }
    string getJurusan(){
        return setjurusan;
    }
    int getVal(){
        return setnilai;
    }
    char getVal_abj(){
        return setval_abj;
    }
    string getStatus(){
        return setstatus;
    }
    string getPath(){
        return setpath;
    }
    string getMapel(){
        return setmapel;
    }


}

