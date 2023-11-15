#include <iostream>

using namespace std;

class Time{
public:
    int ore;
    int minute;
    int secunde;
    //constuctor
    Time(): ore(0), minute(0), secunde(0){}
    //atribuirea parametrilor
    Time(int o, int m, int s) {
        if(verificare_timp(o, m, s)){
            ore = o;
            minute = m;
            secunde = s;
        } else{
            cout << "Timpul introdus nu este valabil" << endl;
        }
    }
    //functia de verificare 
    int verificare_timp(int o, int m, int s){
        return (o >= 0 && o <= 23) && (m >= 0 && m <= 59) && (m >=0 && m<=59);
    }
    //functiile de returnare a timpului
    int getHours() {
        return ore;
    }

    int getMinutes() {
        return minute;
    }

    int getSeconds() {
        return secunde;
    }
    //functiile de afisare
    void afisare_ora(){
        cout <<"Ora " << ore <<" si " << minute << " minute" << " si " << secunde << " secunde" << endl;
    }
    void afisare_ora2(){
    string period = (ore < 12) ? "a.m." : "p.m.";//expresie ternara
    int displayHours = (ore < 12) ? ore : ore - 12;
    cout << displayHours << " " << period << " " << minute << " minute" << " si " << secunde << " secunde" << endl;
    }
};

int main()
{
    Time timp(17, 18, 4);
    timp.afisare_ora();
    timp.afisare_ora2();
    
    
    return 0;
}
