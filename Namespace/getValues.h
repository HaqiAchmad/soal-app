#include <iostream>

namespace getValues{

using namespace std;

    string getemail, getname, getpassword;
    string getnis, getkelas, getjurusan, getstatus;
    int getnilai;
    char getval_abj;

    /*
    set = mendapatkan value dari variabel lain
    get = berisi value dari variabel yang diambil dari fungsi set
    */

    void setEmail(string Email){
        getemail = Email;
    }
    void setName(string name){
        getname = name;
    }
    void setPassword(string pass){
        getpassword = pass;
    }
    void setNis(string nis){
        getnis = nis;
    }
    void setKelas(string kelas){
        getkelas = kelas;
    }
    void setJurusan(string jurusan){
        getjurusan = jurusan;
    }
    void setVal(int value){
        getnilai = value;
    }
    void setVal_abj(char chr){
        getval_abj = chr;
    }
    void setStatus(string status){
        getstatus = status;
    }


    string getEmail(){
        return getemail;
    }
    string getName(){
        return getname;
    }
    string getPassword(){
        return getpassword;
    }
    string getNis(){
        return getnis;
    }
    string getKelas(){
        return getkelas;
    }
    string getJurusan(){
        return getjurusan;
    }
    int getVal(){
        return getnilai;
    }
    char getVal_abj(){
        return getval_abj;
    }
    string getStatus(){
        return getstatus;
    }


}


//class Hero:

//     def __init__(self, heroName, health, attackPower, armor):
//         self.hero = heroName
//         self.health = health
//         self.attackPower = attackPower
//         self.armor = armor

//     def attack(self, Hero):
//         print(self.hero, "menyerang", Hero.hero)
//         Hero.__attacked(self, self.attackPower)

//     def __attacked(self, Hero, serangan_lwn):
//         serangan = serangan_lwn // self.armor
//         self.health -= serangan
//         print(self.hero ,"diserang", Hero.hero)
//         print("serangan", Hero.hero, ":", str(serangan))
//         print("darah", self.hero, ":", str(self.health))
//         print("=" * 50)



// zilong = Hero("zilong", 100, 35, 8)
// iritel = Hero("iritel", 75, 37, 8)
// balmond = Hero("balmond", 130, 20, 15)
// zhaks = Hero("zhaks", 100, 30, 15)
// angela = Hero("angela", 60, 10, 14)
// # power 465 attack 82 armor 26

// alucard = Hero("alucard", 110, 30, 11)
// miya = Hero("miya", 98, 33, 10)
// jonshon = Hero("jonshon", 156, 10, 15)
// joker = Hero("joker", 98, 20, 10)
// diger = Hero("diger", 90, 10, 5)
// # power 534 attack 122 armor 51

// # inpHero = str(input("Hero : "))
// # inpHealth = int(input("Health : "))
// # inpAttackPow = int(input("Attack : "))
// # inpArmor = int(input("Armor : "))
// #
// # objek = Hero(inpHero, inpHealth, inpAttackPow, inpArmor)

// while(True):
//     if zilong.health <= 0 or miya.health <= 0:
//         break
//     else:
//         jonshon.attack(balmond)
//         balmond.attack(jonshon)

//         miya.attack(iritel)
//         iritel.attack(miya)

//         zilong.attack(alucard)
//         alucard.attack(zilong)

//         joker.attack(zhaks)
//         zhaks.attack(joker)

//         angela.attack(diger)
//         diger.attack(angela)







// if (zilong.health > miya.health):
//     print(zilong.hero, "winner")
// elif(zilong.health == miya.health):
//     print("draw!")
// else:
//     print(miya.hero, "winner")
