#ifndef TENSOR_H
#define TENSOR_H

#include <iostream>
#include <typeinfo>
#include <complex>

using namespace std;

template <class Type>
class Tensor{
    
    Type ***tab; //Trojwymiarowa dynamiczna tablica przechowujaca wartosci tensora
    int x, y, z; //Wymiary tensora

public:
    
    Tensor(int=0, int=0, int=0);    //Konstruktor domyslny
    Tensor(const Tensor & t);       //Konstruktor kopiujacy
    ~Tensor();                      //Destruktor

    //Przeciazenia operatorow
    bool operator==(const Tensor & t) const;
    bool operator!=(const Tensor & t) const;

    Tensor & operator=(const Tensor & t);
    Tensor operator+(const Tensor & t);
    Tensor operator+=(const Tensor & t);
    Tensor operator-(const Tensor & t);
    Tensor operator-=(const Tensor & t);
    Tensor operator*(const Tensor & t);
    Tensor operator*=(const Tensor & t);

    //Metody klasy
    inline Type read(int xr, int yr, int zr) const;
    void change(int xc, int yc, int zc, Type wartosc);

    //Funkcje zaprzyjaznione
    friend ostream & operator<< (ostream & os, const Tensor<Type> & t);
    friend istream & operator>> (istream & is, Tensor<Type> & t);
};

//Konstruktor domyslny
template <class Type>
Tensor<Type>::Tensor(int xk, int yk, int zk){
    tab = new Type **[xk];
    for (int i=0; i<xk; i++){
        tab[i]= new Type *[yk];
        for(int j=0; j<yk; j++){
            tab[i][j]=new Type [zk];
        }
    }
    x=xk;
    y=yk;
    z=zk;
}

//Konstruktor kopiujacy
template <class Type>
Tensor<Type>::Tensor(Tensor const &t){ 
	tab = new Type **[t.x];
	for(int i = 0; i<t.x; i++){
		tab[i] = new Type *[t.y];
		for(int j=0; j< t.y; j++) {
		    tab[i][j]=new Type [t.z];
            for (int k=0; k<t.z; k++){
                tab[i][j][k]=t.tab[i][j][k];
            }
		}

	}
    x=t.x;
    y=t.y;
    z=t.z;
}

//Destruktor
template <class Type>
Tensor<Type>::~Tensor(){
for (int i=0; i<y; i++){
    for (int j=0; j<z; j++){
        delete [] tab[i][j];
    }
    delete [] tab[i];
}
delete [] tab;
}

//Funkcja przeciazajaca operator przyrównania (czy takie same)
template <class Type>
bool Tensor<Type>::operator==(const Tensor & t) const{
    if (!(x==t.x && y==t.y && z==t.z)) return false;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                if(tab[i][j][k]!=t.tab[i][j][k]) return false;
            }
        }
    }
    return true;
}

//Funkcja przeciazajaca operator przyrównania (czy rozne)
template <class Type>
bool Tensor<Type>::operator!=(const Tensor & t) const{
    if (!(x==t.x && y==t.y && z==t.z)) return true;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                if(tab[i][j][k]!=t.tab[i][j][k]) return true;
            }
        }
    }
    return false;
}

//Funkcja przeciazajaca operator przypisania
template <class Type>
Tensor<Type> & Tensor<Type>::operator=(const Tensor & t){
    x=t.x;
    y=t.y;
    z=t.z;
    tab = new Type** [x];

    for (int i=0; i<x; i++){
        tab[i]=new Type* [y];
        for(int j=0; j<y; j++){
            tab[i][j]= new Type [z];
        }
    }

    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                tab[i][j][k]=t.tab[i][j][k];
            }
        }
    }

    return *this;
}

//Funkcja przeciazajaca operator dodawania
template <class Type>
Tensor<Type> Tensor<Type>::operator+(const Tensor<Type> & t){
    if ((x==t.x) && (y==t.y) && (z==t.z)){
        Tensor<Type> wynik(x,y,z);
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                for(int k=0; k<z; k++){
                    wynik.tab[i][j][k]=tab[i][j][k]+t.tab[i][j][k];
                }
            }
        }
        return wynik;
    }
    else throw 1;
}

//Funkcja przeciazajaca operator odejmowania
template <class Type>
Tensor<Type> Tensor<Type>::operator-(const Tensor<Type> & t){
if ((x==t.x) && (y==t.y) && (z==t.z)){
        Tensor<Type> wynik(x,y,z);
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                for(int k=0; k<z; k++){
                    wynik.tab[i][j][k]=tab[i][j][k]-t.tab[i][j][k];
                }
            }
        }
        return wynik;
    }
    else throw 1;
}

//Funkcja przeciazajaca operator mnozenia
template <class Type>
Tensor<Type> Tensor<Type>::operator*(const Tensor<Type> & t){
if ((x==t.x) && (y==t.y) && (z==t.z)){
        Tensor<Type> wynik(x,y,z);
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                for(int k=0; k<z; k++){
                    wynik.tab[i][j][k]=tab[i][j][k]*t.tab[i][j][k];
                }
            }
        }
        return wynik;
    }
    else throw 1;
}

template <class Type>
Tensor<Type> Tensor<Type>::operator+=(const Tensor<Type> & t){
    if (!(x==t.x && y==t.y && z==t.z))
        throw 1;
    else{
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                for(int k=0; k<z; k++){
                    tab[i][j][k]=tab[i][j][k]+t.tab[i][j][k];
                }
            }
        }
    return *this;
    }
}

template <class Type>
Tensor<Type> Tensor<Type>::operator-=(const Tensor &t){
    if (!(x==t.x && y==t.y && z==t.z))
        throw 1;
    else{
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                for(int k=0; k<z; k++){
                    tab[i][j][k]=tab[i][j][k]-t.tab[i][j][k];
                }
            }
        }
    return *this;
    }
}

template <class Type>
Tensor<Type> Tensor<Type>::operator*=(const Tensor &t){
    if (!(x==t.x && y==t.y && z==t.z))
        throw 1;
    else{
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                for(int k=0; k<z; k++){
                    tab[i][j][k]=tab[i][j][k]*t.tab[i][j][k];
                }
            }
        }
    return *this;
    }
}

//Funkcja odczytujaca element o danych wspolrzednych
template <class Type>
Type Tensor<Type>::read(int xr, int yr, int zr) const{
     return tab[xr-1][yr-1][zr-1];
}

//Funkcja zmieniajaca wskazana wartosc
template <class Type>
void Tensor<Type>::change(int xc, int yc, int zc, Type wartosc){
    tab[xc-1][yc-1][zc-1]=wartosc;
}
    
//Funkcja przeciazajaca operator wczytywania
template <class Type>
istream & operator>>(istream & is, Tensor<Type> & t){
    Type wartosc;
    for(int i=0;i<t.x;i++){
        for (int j=0; j<t.y;j++){
            for (int k=0;k<t.z;k++){
                is>>wartosc;
                t.tab[i][j][k]=wartosc;
            }
        }
    };
    return is;
}

//Funkcja przeciazajaca operator wypisywania
template <class Type>
ostream & operator<<(ostream & os, const Tensor<Type> & t){
    for (int i=0; i<t.x; i++){
        os<<"x ["<<i+1<<"]";
        for (int j=0; j<t.y; j++){
            os<<"y ["<<j+1<<"]";
            for (int k=0; k<t.z; k++){
                os<<"z ("<<k+1<<") = "<<t.tab[i][j][k]<<" ";
            }
            os<<endl;
        }
        os<<endl;
    }
    return os;
}


#endif