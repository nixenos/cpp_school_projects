#include <bits/stdc++.h>
using namespace std;
int main(){
        string ciag_1;
        string klucz;
        cin >> ciag_1;
        cin >> klucz;
        vector <char> klucz_final;
        vector <char> szyfr;
        //cout << klucz.size();
        int ile=ciag_1.size()/klucz.size();
        ile++;
        //cout << ile;
        int counter=0;
        for (int i=0; i<ile*klucz.size(); i++){
                if (counter>klucz.size())
                        counter=0;
                klucz_final.push_back(klucz[counter]-65);
        }
        for (int i=0; i<ciag_1.size(); i++){
                char pom=ciag_1[i];
                szyfr.push_back(pom-65);
                szyfr[i]+=klucz_final[i];
                if (szyfr[i]>25)
                        szyfr[i]-=25;
        }
        for (int i=0; i<szyfr.size(); i++){
                cout << szyfr[i];
        }
        return 0;
}
