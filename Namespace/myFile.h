void writeDataUser(string Gmail,string Name, string Nis, string Kelas, string Jurusan, int Nilai, string status){

    ofstream DataUser; DataUser.open("DataStatusUser.txt",ios::app);

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

    DataUser <<"Gmail    : "; DataUser << Gmail.append("\n");
    DataUser <<"Username : "; DataUser << Name.append("\n");
    DataUser <<"Nis      : "; DataUser << Nis.append("\n");
    DataUser <<"Kelas    : "; DataUser << Kelas.append("\n");
    DataUser <<"Jurusan  : "; DataUser << Jurusan.append("\n");
    DataUser <<"Nilai    : "; DataUser << Nilai*10;
    DataUser <<"\nStatus   : "; DataUser << status.append("\n");
    DataUser <<"Login Time : "; DataUser << jam.append(":"+menit+" ");
    DataUser << nmDay.append(harini+":"+bulan+":"+tahun+"\n\n");

    }


