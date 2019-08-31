#include <iostream>

namespace getValues{

using namespace std;

    string setgmail, setname, setpassword;
    string setnis, setkelas, setjurusan, setstatus;
    int setnilai;
    char setval_abj;

    void getGmail(string gmail){
        setgmail = gmail;
    }
    void getName(string name){
        setname = name;
    }
    void getPassword(string pass){
        setpassword = pass;
    }
    void getNis(string nis){
        setnis = nis;
    }
    void getKelas(string kelas){
        setkelas = kelas;
    }
    void getJurusan(string jurusan){
        setjurusan = jurusan;
    }
    void getVal(int value){
        setnilai = value;
    }
    void getVal_abj(char chr){
        setval_abj = chr;
    }
    void getStatus(string status){
        setstatus = status;
    }


    string setGmail(){
        return setgmail;
    }
    string setName(){
        return setname;
    }
    string setPassword(){
        return setpassword;
    }
    string setNis(){
        return setnis;
    }
    string setKelas(){
        return setkelas;
    }
    string setJurusan(){
        return setjurusan;
    }
    int setVal(){
        return setnilai;
    }
    char setVal_abj(){
        return setval_abj;
    }
    string setStatus(){
        return setstatus;
    }

}
