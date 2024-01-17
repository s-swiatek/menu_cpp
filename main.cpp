#include <iostream>
#include <fstream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyswietl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int index;
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden wiekszej niz poprzednia)
                if(p != NULL) //jezeli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartoœæ poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usun poprzednia tablice
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw nowa wartosc do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaznika p
                n++; //zwieksz ilosc elementów tablicy o 1
                break;
            }
        case 2:
            {
                cout<<"Podaj index, pod ktory chcesz wstawic element: ";
                cin >> index;
                if (index > n || index < 0)
                {
                    cout << "Nieprawidlowy indeks." << endl;
                    break;
                }

                int *tmp = new int[n + 1];
                for (int i = 0; i < index; i++)
                {
                    tmp[i] = p[i];
                }
                cout << "Podaj wartosc elementu tablicy: ";
                cin >> tmp[index];
                for (int i = index + 1; i <= n; i++)
                {
                    tmp[i] = p[i - 1];
                }
                delete[] p;
                p = tmp;
                n++;
                break;
            }
        case 3:
            {
                cout<<"Podaj index elementu, ktory chcesz usunac: ";
                cin >> index;
                if (index >= n || index < 0)
                {
                    cout << "Nieprawidlowy indeks." << endl;
                    break;
                }
                int *tmp = new int[n - 1];
                for (int i = 0; i < index; i++)
                {
                    tmp[i] = p[i];
                }
                for (int i = index + 1; i <= n; i++)
                {
                    tmp[i - 1] = p[i];
                }
                delete[] p;
                p = tmp;
                n--;
                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 5:
            {
                //zapis danych do pliku
                string x;
                fstream fin;
                cout<<"Podaj sciezke dostepu pliku, do ktorego chcesz zapisac:"<<endl;
                cin>>x;
                fin.open(x,ios::out);
                if(fin.is_open())
                {
                    for(int i=0;i<n;i++)
                    {
                        fin<<p[i]<<" , ";
                    }
                    fin.close();
                }else{
                    cout << "Nieudane otwarcie pliku"<<endl;
                }
                break;
            }
        case 6:
             {
                string x;
                fstream fin;

                cout << "Podaj sciezke dostepu pliku, z ktorego chcesz wczytac:" << endl;
                cin >> x;

                fin.open(x, ios::in);
                if (!fin.is_open())
                {
                    cout << "Nieudane otwarcie pliku" << endl;
                    break;
                }

                delete[] p;
                p = NULL;
                n = 0;

                int value;
                char comma;

                while (fin >> value) {
                    int *tmp = new int[n + 1];
                    for (int i = 0; i < n; i++) {
                        tmp[i] = p[i];
                    }
                    tmp[n] = value;

                    if (fin >> comma && comma == ',') {
                        delete[] p;
                        p = tmp;
                        n++;
                    } else {

                        delete[] tmp;
                        break;
                    }
                }

                fin.close();
                break;

                        }
        case 7:
            {
                delete[] p;
                return 0;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }
        }
    }

    return 0;
}
