//---------------------------------------------------------------------------

//#pragma hdrstop

//#include "algorytmy.h"
#include <iostream>

using namespace std;

int potega(int x, int i){
        if(i==0) return 1;
        else return x*potega(x, i-1);
}
//---------------------------------------------------------------------------

int sumuj(list<int> &q){
  int suma=0, i, j=q.size();
        for(i=0;i<j;i++){
            //cout << q.front() << endl;
            suma+=q.front()*potega(256,i);
            q.pop_front();
            }
        return suma;
}
//---------------------------------------------------------------------------

int karatsuba(list<int> &q, int j){
        list<int> q1;
		int m=j/2, wynik=0;
        for(int i=1; i<=m; i++){ 
		 q1.push_back(q.front());
		 q.pop_front();
		 }
		 
        return wynik;
}
//#pragma package(smart_init)
