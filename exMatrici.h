#ifndef EXMATRICI.h
#define EXMATRICI.h
#include <fstream>




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

void rezolvareProb1(){
   int v[100][100],m,n;
   citireMatrice_fis(v,n,m);
   afisareMatrice(v,n,m);
   cout<<"Suma tuturor numerelor pare este == ";
   cout<<sumaPare(v,n,m);
}

//Se dă o matrice cu n linii și m coloane și elemente numere naturale. Să se determine suma elementelor de pe fiecare linie.
//functie ce face suma elementelor de pe o anumita linie

int sumaLinie(int a[100][100], int k,int m){
    int s=0;
    for(int j=0;j<m;j++){
        s=s+a[k][j];
    }
    return s;
}

void sumaLinii(int a[100][100],int n, int m){
    for(int i=0;i<n;i++){
        cout<<sumaLinie(a,i,m)<<endl;
    }

}

void rezolvareProb2(){
   int v[100][100],m,n,k;
   citireMatrice_fis(v,n,m);
   afisareMatrice(v,n,m);
   sumaLinii(v,n,m);
}

//Gigel a găsit o matrice cu n linii și m coloane și elemente numere naturale.
//El își propune să determine, pentru fiecare linie, cea mai mică valoare care se poate obține adunând elementele de pe linie, cu excepția unuia.

int sumaMinLinie(int a[100][100],int k,int m){
    int suma =0;
    for(int j=0;j<m;j++){
        suma=suma+a[k][j];
    }
    int maxim=a[k][0];
    for(int j=1;j<m;j++){
        if(a[k][j]>maxim){
            maxim=a[k][j];
        }
    }
    return suma-maxim;
}

void sumaMinToateLinile(int a[100][100],int n,int m){
    for(int i=0;i<n;i++){
            cout<<sumaMinLinie(a,i,m)<<endl;
    }
}

//Se dă o matrice cu n linii și m coloane și elemente numere naturale. Să se determine câte dintre elementele situate pe linii cu indici pari sunt prime.

bool estePrim(int nr){
    if(nr<2) return false;
    for(int i=2;i*i<=nr;i++){
        if(nr%i==0)return false;
    }
    return true;
}

int numaraPrimeIndiciPari(int a[100][100],int n,int m){
    int ct=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i+j)%2==0 && estePrim(a[i][j])){
                ct++;
            }
        }
    }
    return ct;
}

//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Să se determine elementul cu număr maxim de apariții în matrice.
//Dacă există mai multe elemente cu număr maxim de apariții se va afișa cel mai mare dintre ele.

int maximMatrice(int a[100][100], int n,int m){
    int maxim=a[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]>maxim){
                maxim=a[i][j];
            }
        }
    }
    return maxim;
}

void calculFrecventa(int a[100][100],int n, int m,int frecv[],int maxim){
    for(int i=0;i<=maxim;i++){
        frecv[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            frecv[a[i][j]]++;
        }
    }
}

int elementMaxApariti(int frecv[], int maxVal){
    int maxfr=0,maxim=0;
    for(int i=0;i<=maxVal;i++){
        if(frecv[i]>maxfr){
            maxfr=frecv[i];
            maxim=i;
        }
    }
    return maxim;
}

//Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Să se determine câte linii ale matricei au toate elementele egale.

bool linieEgala(int a[100][100],int k,int m){
    for(int j=1;j<m;j++){
        if(a[k][m]!=a[k][0]){
            return false;
        }
    }
    return true;
}

int numaraLiniiElemEgale(int a[100][100],int n, int m){
    int ct=0;
    for(int i=0;i<n;i++){
        if(linieEgala(a,i,m)){
            ct++;
        }
    }
    return ct;
}




#endif // EXMATRICI.h
