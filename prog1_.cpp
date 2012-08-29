//---------------------------------------------------------------------------

//#pragma hdrstop
#include <iostream>
#include <list>
#include <vector>
#include "algorytmy.cpp"

using namespace std;



const char cyfry[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//---------------------------------------------------------------------------

//#pragma argsused
int main(int argc, char* argv[]){

        list <int> q,q1,q2,wynik,qa,qb;
		vector <int> p,p1,p2;
	q.clear();
	p.clear();

	string x, o=argv[2];
        int i, suma=0, dl, liczba, l, j, k, ujemna=0;
		char znak;
//****** Wczytywanie skladnikow do wektora **************************
if(o=="*"){	
        for (k=1;k<=2;k++){
	//cout << "Podaj skladnik sumy: ";
	//cin >> x;
		if(k==2) x=argv[k+1];
			else x=argv[k];
        dl=x.length();

                l=0,j=0;
		for(i=dl-1;i>=0;i--){
		liczba=int(x[i]);
		if(liczba>47 && liczba<58) l+=(liczba-48)*potega(16,j);
		if(liczba>64 && liczba<71) l+=(liczba-55)*potega(16,j);
		if(liczba>96 && liczba<103) l+=(liczba-87)*potega(16,j);


                j++;
		}
                j=0;
                while(l>255){
                        p.push_back(l%256);
                        l=l/256;
                        j++;
                           }

                        p.push_back(l);
						cout << " " << p.back() << " ";
			if(k==1) {
				p1=p;
				p.clear();
			}
				else p2=p;
//******** Mnozenie:   **********************************************				
			p=mnozenie(p1,p2);
        }                
}


	
//****** Wczytywanie skladnikow do listy ****************************
	if(o=="+" || o=="?" || o=="-"){	
        for (k=1;k<=2;k++){
	//cout << "Podaj skladnik sumy: ";
	//cin >> x;
		if(k==2) x=argv[k+1];
			else x=argv[k];
        dl=x.length();

                l=0,j=0;
		for(i=dl-1;i>=0;i--){
		liczba=int(x[i]);
		if(liczba>47 && liczba<58) l+=(liczba-48)*potega(16,j);
		if(liczba>64 && liczba<71) l+=(liczba-55)*potega(16,j);
		if(liczba>96 && liczba<103) l+=(liczba-87)*potega(16,j);


                j++;
		}
                j=0;
                while(l>255){
                        q.push_back(l%256);
                        l=l/256;
                        j++;
                           }

                        q.push_back(l);
                        
	
//******** Sumowanie:   *************************************************
               if(o=="+") suma+=sumuj(q);
			   
//******** Porownywanie:   **********************************************			   
			   if(o=="?" || o=="-"){
				if(k==1) {
					q1=q;
					q.clear();
					}
						else q2=q;
				 }
				
               //cout << "suma= " << suma << endl;
              }
	}
/*********************** Obszar testow ***********************************************/
		if(o=="-"){
					
			   }
			
        /*while (q.size()>0) {
        cout << " " << q.front() << " ";
        q.pop_front();
	}
        cout << "Suma wynosi: " << suma << endl; */
		
/**************************************************************************************/
//******** Porownywanie c.d.:   ********************************************** 
		if(o=="?"){
			cout << porownaj(q1,q2) << endl ;
			
		}	
		
//****** Wypisywanie sumy na ekran:  ***********************************
      if(o=="+"){  
		q.clear();
        i=0;
        while (suma >= 16){
        q.push_back(suma%16);
        suma=suma/16;
        i++;
        }

        q.push_back(suma);
        q.reverse();

        //cout << "Suma wynosi: ";
        for (int j=i; j>=0; j--) {
        cout << cyfry[q.front()];
		q.pop_front();
		}
        cout << endl;
	  }

		;
	 /* */


//****** Wypisywanie iloczynu/roznicy na ekran:  ***********************************
      if(o=="*" || o=="-"){
		if(o=="-"){
			qa=q1;
			qb=q2;
			znak=porownaj(qa,qb);
			if(znak=='<'){
				wynik=odejmij(q2,q1);
				ujemna=1;
			} else wynik=odejmij(q1,q2);
		}	
		/*while (wynik.size()>0) {
        cout << " " << wynik.front() << " ";
        wynik.pop_front();
	}
cout << endl << "--------------------" << endl;*/
		q.clear();
        i=0;
		wynik.reverse();
		while(!wynik.empty()){
			suma=wynik.back();
			
			//if (suma<10) q.push_back(0);
			while (suma >= 16){
			 q.push_back(suma%16);
			 suma=suma/16;
			//i++;
			}

			q.push_back(suma);
			wynik.pop_back();
			
		}
			q.reverse();
		if(ujemna>0) cout << "-";	
        while (!q.empty()) {
        cout << cyfry[q.front()];
		q.pop_front();
		}
        cout << endl;
	  }	
//---------------------------------------------------------------------------
        //system("pause");
        return 0;
}
//---------------------------------------------------------------------------
