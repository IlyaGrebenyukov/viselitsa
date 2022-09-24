/#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
 
using namespace std;
 
void Game (string *a);
bool Pic1 (int n, int lenl, string *a);
void Pic2 (int n);
char pic_mass[30];
int mas1[5][4] = { {1, 1, 1, 1}, {1, 256, 2, 256}, {1, 4, 3, 5}, {1, 256, 6, 256}, {1, 7, 256, 8} }; 
char mas2[5][4] = { {'|', '-', 'T', '-'}, {'|', ' ', 'o', ' '}, {'|', '-', '|', '-'}, {'|', ' ', '^', ' '}, {'|', '/', ' ', '\\'} };

 
int main ()
{
    setlocale(LC_CTYPE,"");
    string sl0 = "paralelogramm"; 
    string sl2 = "kosinys";
    string sl3 = "germoshpangoyt";
    string sl4 = "syshestvitelnoe";
    string sl5 = "sinxrofazatron";
    string sl6 = "kollaider";
    string sl7 = "vosstanovlenie";
    string sl8 = "gipopotam";
    string sl9 = "torrent";
 
    string *mass[10]; 
    mass[0] = &sl0;
    mass[1] = &sl1;
    mass[2] = &sl2;
    mass[3] = &sl3;
    mass[4] = &sl4;
    mass[5] = &sl5;
    mass[6] = &sl6;
    mass[7] = &sl7;
    mass[8] = &sl8;
    mass[9] = &sl9;
 
    for (int i=0; i<30; i++)
    { pic_mass[i]='_'; }
 
    srand (time (NULL));
    int Random = rand()%9;
    Game (mass[Random]);
 
    cin.sync();
    cin.clear();
    cin.get();
 
    return 0;
}
 

 
void Game (string *a) 
{ 
    system("cls");
    int i=0, j=0, ochibka=0;
    bool verno = false;
    int lenl = a->size(); 
    char bukva;
 
    while (i<=34) 
    {
        while (j!= lenl)
        { 
            cout << "_"; j++;} 
 
        setlocale(LC_CTYPE,"");
        cout <<endl<<"Назовите букву:"<<endl;
        setlocale(LC_CTYPE,"");
        cin >> bukva;
        for(int k=0; k<lenl; k++)  
        {
            setlocale(LC_CTYPE,"");
            if ((*a)[k]==bukva) 
                verno = true;
                if (Pic1 (k, lenl, a)) 
                {
                    cout<<endl<<"Вы выиграли!";
                    return;}
            }
        }
        if (verno == false) 
        {
            ochibka++;
            Pic2 (ochibka); 
            if (ochibka == 8)
            {
                setlocale(LC_CTYPE,"");
                cout<<endl<<"Вы проиграли!"<<endl<<"Правильный ответ: "<<(*a);
                cin.sync();
                cin.clear();
                cin.get();
                return;
            }
        }
 
        i++; verno = false;
    }
 
}
 

 
bool Pic1 (int n, int lenl, string *a) 
{
    system("cls");
    setlocale(LC_CTYPE,"");
    pic_mass[n] = (*a)[n];
    for (int i=0; i<lenl; i++)
    { cout<<pic_mass[i]; }
 
    for (int j=0; j<lenl; j++)
    {
        if (pic_mass[j] == '_') return false;
    }
    return true;
};
 

 
void Pic2 (int n) 
{
    system("cls");
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 4; j++)
            if (mas1[i][j] <= n)
            {
                cout << mas2[i][j]; 
            } else
                cout << " ";  
            cout << endl; 
    }
}
 