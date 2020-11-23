#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

class Matrix
{
private:
    int X, Y;
    double** tab;

public:
Matrix(int n, int m)
{
    X = n;
    Y = m;
    tab = new double* [n];
    for(int i=0; i<n; i++)
    tab[i] = new double[m];
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<m; j++) 
        {
            tab[i][j] = 0;
        }
    }
    
}
Matrix(int n)
{
    X = n;
    Y = n;
    tab = new double* [n];
    for (int i = 0; i < n; i++)
        tab[i] = new double[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
             tab[i][j] = 0;
        }
    }
}
   
~Matrix() { };
    
void set(int n, int m, double val)
{
    tab[n - 1][m - 1] = val;
}

double get(int n, int m)
{
    return tab[n-1][m-1];     
}

Matrix add(Matrix& m2)
{
    Matrix suma(X, Y);
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            suma.tab[i][j] = tab[i][j] + m2.tab[i][j];
        }
    }
    return suma;
}
Matrix subtract(Matrix& m2)
{
    Matrix wynik(X, Y);
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            wynik.tab[i][j] = tab[i][j] - m2.tab[i][j];
        }
     }
    return wynik;
}
Matrix mutliply(Matrix& m2)
{
    Matrix wynik(X,Y);
    for (int i = 0; i < X; i++) 
    {
        for (int j = 0; j < Y; j++) 
        {
            wynik.tab[i][j] = tab[i][j] * m2.tab[i][j];
        }
    }
    return wynik;
}  

int cols()
{
    return Y;
}
int rows()
{
    return X;
}

void print()
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

void store(std::string filename, std::string path) {
    std::fstream plik;
    plik.open(path + filename, std::ios::out);
    plik << "liczba wierszy: " << X << " Liczba kolumn: " << Y << "\n\n";
        for (int i = 0; i < X; i++) 
        {
            for (int j = 0; j < Y; j++) 
            {
                plik << tab[i][j] << " ";
            }
            plik << "\n";
        }
        plik.close();
   
}
};
int main()
{
    int n=1,m=2,x=5,y=4;
    double val1 = 7, val2 = 11;

    Matrix m1(x,y); 
    Matrix m2(x,y);
    Matrix m3(x);

    cout << endl;
//test metody get()
    cout << "wartosc drugiej komorki pierwszego rzedu macierzy m1 przed wykonaniem metody set: " << m1.get(n,m) << endl; 
    cout << "wartosc drugiej komorki pierwszego rzedu macierzy m2 przed wykonaniem metody set: " << m2.get(n,m) << endl << endl;
//test metody set()
    m1.set(n,m,val1);  
    m2.set(n,m,val2); 
//test metody get()
    cout << "wartosc drugiej komorki pierwszego rzedu macierzy m1 po wykonaniu metody set: " << m1.get(n,m) << endl; 
    cout << "wartosc drugiej komorki pierwszego rzedu macierzy m2 po wykonaniu metody set: " << m2.get(n,m) << endl;
//test metody add()
    cout << endl << "macierz po dodaniu: " << endl;
    m1.add(m2).print(); 
//test metody subtract()
    cout << endl<< "macierz po odejmowaniu: " << endl;
    m1.subtract(m2).print();
//test metody multiply()
    cout << endl << "macierz po pomnozeniu: " << endl;
    m1.mutliply(m2).print(); 
//test metody cols()
    cout << endl << "liczba kolumn macierzy m1: " << m1.cols() << endl; 
//test metody rows()
    cout << endl << "liczba rzedow macierzy m1: " << m1.rows() << endl; 
//test metody print()
    cout << endl << "macierz m1: " << endl;
    m1.print(); 
    cout << endl << "macierz m2: " << endl;
    m2.print(); 
//test metody store()
    m1.store("m1.txt","./"); 
    system("pause");
    return 0;
}
