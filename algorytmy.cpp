//---------------------------------------------------------------------------

//#pragma hdrstop

#include "algorytmy.h"
#include <iostream>

using namespace std;

void testuj(list<int> &q){
	while (q.size()>0) {
        cout << " " << q.front() << " ";
        q.pop_front();
	}
}
//---------------------------------------------------------------------------
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

list<int> karatsuba(list<int> &q1, list<int> &q2){
        list<int> q, qx, qy, q12, q22;
		int m, i;
		if(q1.size()!=q2.size()){
		   if(q1.size()>q2.size()){
			  m=q1.size()-q2.size();
			  for(i=1;i<=m;i++) q2.push_back(0);
			} else {
			   m=q2.size()-q1.size();
			   for(i=1;i<=m;i++) q1.push_back(0);
			   }
		}	   
		 m=q1.size()/2;
        for(i=1; i<=m; i++){ 
		 q12.push_back(q1.front());
		 q1.pop_front();
		 q22.push_back(q2.front());
		 q2.pop_front();
		 }
		 /*for(i=1;i<=m;i++){
		   if((q22.front()*q1.front())>255){
		     qx.push_back((q22.front()*q1.front())%256);
			 qx.push_back((q22.front()*q1.front())/256);
			 }
		   q22.pop_front();
		   q1.pop_front();
		   if((q12.front()*q2.front())>255){
		     qx.push_back((q12.front()*q2.front())%256);
			 qx.push_back((q12.front()*q2.front())/256);
			 }
		   q12.pop_front();
		   q2.pop_front();
		   }*/
		   qx=karatsuba(q1,q2);
		   qy=karatsuba(q12,q22);
        return q;
}

vector<int> mnozenie(vector<int> &q1, vector<int> &q2){
	int wynik=0, j, i, k, m, suma;
	vector <int> q;
	/*if(j1>j2) j=j1;
		else j=j2;*/
	if(q1.size()!=q2.size()){
		   if(q1.size()>q2.size()){
			  m=q1.size()-q2.size();
			  for(i=1;i<=m;i++) q2.push_back(0);
			} else {
			   m=q2.size()-q1.size();
			   for(i=1;i<=m;i++) q1.push_back(0);
			   }
		}
	k=q1.size();
	for(i=0;i<=k;i++){
	  for(j=0;j<=k;j++){	
		wynik=q1[i]*q2[j];
		while(wynik>255){
           q.push_back(wynik%256);
           wynik=wynik/256;
           }  
		 q.push_back(wynik);
		
	  if(i>0){
    	  suma=q[i]+q.back();
		  q.pop_back();
		  while(suma>255){
           q.push_back(suma%256);
           suma=suma/256;
           }  
		 q.push_back(suma);
	    }
	  }	
	}	
	return q;	

}

char porownaj(list<int> &q1, list<int> &q2){
	/*testuj(q1);
	cout << endl;
	testuj(q2);
	cout << endl << endl;*/
	int m,i;
	if(q1.size()!=q2.size()){
		   if(q1.size()>q2.size()){
			  m=q1.size()-q2.size();
			  for(i=1;i<=m;i++) q2.push_back(0);
			} else {
			   m=q2.size()-q1.size();
			   for(i=1;i<=m;i++) q1.push_back(0);
			   }
	}
	q1.reverse();
	q2.reverse();
	/*testuj(q1);
	cout << endl;
	testuj(q2);
	cout << endl;*/
	
	
	while(q1.size()!=0)
	if(q1.front()>q2.front()) return '>';
		else if(q2.front()>q1.front()) return '<';
			else {
					q1.pop_front();
					q2.pop_front();
				}
		return '=';
}

list<int> odejmij(list<int> &q1, list<int> &q2){
	list<int> wynik;
	wynik.clear();
	//wynik.push_back(0);
	int i, x, l1, l2, m;
	
	if(q1.size()!=q2.size()){
		   if(q1.size()>q2.size()){
			  m=q1.size()-q2.size();
			  for(i=1;i<=m;i++) q2.push_back(0);
			} else {
			   m=q2.size()-q1.size();
			   for(i=1;i<=m;i++) q1.push_back(0);
			   }
	}
	//q1.reverse();
	//q2.reverse();

	
	while(!q1.empty()){
		l1=q1.front();
		q1.pop_front();
		l2=q2.front();
		q2.pop_front();
		if(l1>=l2) wynik.push_back(l1-l2);
			else{
				wynik.push_back(256+l1-l2);
				x=q1.front();
				q1.pop_front();
				q1.push_back(x-1);
			}	
	}	
	
	
	return wynik;
	
}

int NWD(int a, int b){
int c;
	while (b != 0){
		c=a%b;
		a=b;
		b=c;
	}
return a;
}

list<int> gcd(list <int> u, list <int> v)
{
  list<int> tmp;
  // simple cases (termination)
  if (porownaj(u,v)=='=')
    return u;
  if (u.empty())
    return v;
  if (v.empty())
    return u;
 
  // look for factors of 2
  if (~(u.front()) & 1){ // u is even
    if ((v.front()) & 1){ // v is odd
	  u.pop_front();
      return gcd(u, v); }
    else { // both u and v are even
		u.push_back(0);
		v.push_back(0);
		tmp=gcd(u, v);
		tmp.pop_front();
      return tmp;}
	}
  if (~(v.front()) & 1) {// u is odd, v is even
     v.push_back(0);
    return gcd(u, v); }
 
  // reduce larger argument
  if (u.front() > v.front()){
     tmp=odejmij(u,v);
	 tmp.push_back(0);
    return gcd(tmp, v); }
	tmp=odejmij(v,u);
	tmp.push_back(0);
  return gcd(tmp, u);
}
//#pragma package(smart_init)
