#ifndef TEMA_H_INCLUDED
#define TEMA_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;


//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Să se determine câte coloane ale matricei au elementele distincte două câte două.


void afisareMatrice(int a[100][100],int n,int m){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }


}

void citireMatrice_fis(int a[100][100],int& n, int& m){
    ifstream citire("data.txt");
    citire>>n;
    citire>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            citire>>a[i][j];
        }
    }
}

bool coloanaDistincta(int a[100][100],int n, int m,int col){
    for(int i=0;i<n-1;i++)
        for(int k=i+1;k<n;k++)
            if(a[i][col]==a[k][col])
                return false;
    return true;
}

int numaraColoaneDistincte(int a[100][100],int n, int m,int col){
    int cnt=0;
    for(int j=0;j<m;j++)
        if(coloanaDistincta(a,n, m,col))
            cnt++;
    return cnt;
}

void ex1(){
    int a[100][100],n,m,col;

    citireMatrice_fis(a,n,m);
    afisareMatrice(a,n,m);
    coloanaDistincta(a,n, m,col);
    cout<<numaraColoaneDistincte(a,n, m,col);
}


//Se dă o matrice cu n linii și m coloane și elemente numere naturale. Să se determine câte elemente din matrice sunt mai mari decât suma vecinilor lor.

bool maiMareDecatVecini(int a[100][100],int n, int m){
    int i=0;
    int j=0;
    int suma=0;
    if(i>0)suma+=a[i-1][j];
    if(i<n-1)suma+=a[i+1][j];
    if(j>0)suma+=a[i][j-1];
    if(j<m-1)suma+=a[i][j+1];
    return a[i][j]>suma;
}


int numaraElemente(int a[100][100],int n, int m){
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(maiMareDecatVecini(a,n, m))
                cnt++;
    return cnt;
}

void ex2(){
    int a[100][100],n,m,i,j;

    citireMatrice_fis(a,n,m);
    afisareMatrice(a,n,m);
    maiMareDecatVecini(a,n, m);
    cout<<numaraElemente(a,n, m);
}

//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Determinați suma valorilor pare din matrice.


int sumaPare(int a[100][100],int n,int m){
    int suma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]%2==0){
                suma=suma+a[i][j];
            }
        }
    }
    return suma;

}

void ex3(){
   int v[100][100],m,n;
   citireMatrice_fis(v,n,m);
   afisareMatrice(v,n,m);
   cout<<sumaPare(v,n,m);
}

//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Să se determine câte elemente din matrice au toți vecinii numere pare.


bool veciniPare(int a[100][100],int n, int m,int i, int j){
    if(i>0 && a[i-1][j]%2==1)return false;
    if(i<n-1 && a[i+1][j]%2==1)return false;
    if(j>0 && a[i][j-1]%2==1)return false;
    if(j<m-1 && a[i][j+1]%2==1)return false;
    return true;
}

int numaraElemente2(int a[100][100],int n, int m){
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(veciniPare(a,n, m,i,j))
                cnt++;
    return cnt;
}

void ex5(){
    int a[100][100],n,m,i,j;

    citireMatrice_fis(a,n,m);
    afisareMatrice(a,n,m);
    veciniPare(a,n, m,i ,j);
    cout<<numaraElemente2(a,n, m);
}

//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Să se determine cea mai mare valoare care apare în matrice de cel puțin două ori
int numarAparitii(int n,int m,int a[100][100],int val){
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]==val)
                cnt++;
    return cnt;
}

int ceaMaiMareRepetata(int a[100][100],int n, int m){
    int maxim=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(numarAparitii(n,m,a,a[i][j])>=2 && a[i][j]>maxim)
                maxim=a[i][j];
    return maxim;
}

void ex6(){
    int a[100][100],n,m,i,j;

    citireMatrice_fis(a,n,m);
    afisareMatrice(a,n,m);
    cout<<ceaMaiMareRepetata(a,n,m);

}


//Se dă o matrice cu m linii și n coloane și elemente numere naturale cu cel mult patru cifre. Să se modifice matricea, eliminând penultima linie și penultima coloană.

void afisare_modificata(int a[100][100], int n,int m) {
    for (int i = 0; i < m; i++) {
        if (i == m - 2);
        for (int j = 0; j < n; j++) {
            if (j == n - 2);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void ex7(){
    int a[100][100],n,m;
    citireMatrice_fis(a,n,m);
    afisare_modificata(a,n,m);
}

//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Ordonați crescător elementele de pe fiecare linie a matricei și apoi afişați matricea

void sortare_linii(int a[100][100], int n,int m,int k){
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            for(int k=j+1;k<m;k++){
                if(a[i][j]>a[i][k]){
                    swap(a[i][j],a[i][k]);
                }
            }
        }
    }
}
void afisare(int a[100][100],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}


void ex8(){
    int a[100][100];
    int n, m,k;
    citireMatrice_fis(a,n,m);
    sortare_linii(a,n,m,k);
    afisare(a,n,m);
}

//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Ordonați descrescător elementele de pe fiecare coloană a matricei și apoi afișați matricea.

void sortare_coloane(int a[100][100], int n,int m,int k){
    for(int j=0;j<m;j++){
        for(int i=0;i<n-1;i++){
            for(int k=i+1;k<n;k++){
                if(a[i][j]<a[k][j]){
                    swap(a[i][j],a[k][j]);
                }
            }
        }
    }
}

void ex9(){
    int a[100][100];
    int n, m,k;
    citireMatrice_fis(a,n,m);
    sortare_coloane(a,n,m,k);
    afisare(a,n,m);

}
//Să se determine, pentru fiecare linie a unei matrice, elementul maxim și indicele coloanei pe care se află.

void maxim_pe_linii(int a[100][100], int n,int m){
    for(int i=0;i<n;i++){
        int maxim=a[i][0],poz=0;
        for(int j=1;j<m;j++)
            if(a[i][j]>maxim){
                maxim=a[i][j];
                poz=j;
            }
        cout<<"Linia "<<i<<": max="<<maxim<<" coloana="<<poz<<"\n";
    }
}

void ex10(){
    int a[100][100],n,m;
    citireMatrice_fis(a,n,m);
    afisareMatrice(a,n,m);
    cout<<endl;
    maxim_pe_linii(a,n,m);

}



#endif // TEMA_H_INCLUDED
