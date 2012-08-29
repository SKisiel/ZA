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

        list <int> q,q1,q2,q1a,q2a,suma,wynik,qa,qb;
		vector <int> p,p1,p2;
	q.clear();
	p.clear();

	string x, o=argv[2];
        int i, dl, liczba, l, j, k, ujemna=0, wym=0;
		char znak;
//****** Wczytywanie czynnikow do wektora **************************
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
						//cout << " " << p.back() << " ";
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
		//cout << "liczba: " << liczba << " k:" << k << endl;
		if(liczba==95 && k==1){
			wym=1;
			//break;
			j=0;
                while(l>255){
                        q1a.push_back(l%256);
                        l=l/256;
                        j++;
                           }

                        q1a.push_back(l);
                       
			
		 } else if (liczba==95 && k==2){
			wym=2;
			//break;
			j=0;
                while(l>255){
                        q2a.push_back(l%256);
                        l=l/256;
                        j++;
                           }

                        q2a.push_back(l);
                        
			}
		if(liczba>47 && liczba<58) l+=(liczba-48)*potega(16,j);
		if(liczba>64 && liczba<71) l+=(liczba-55)*potega(16,j);
		if(liczba>96 && liczba<103) l+=(liczba-87)*potega(16,j);
		//wym=0;
		
                j++;
		}
		//cout << "liczba: " << liczba << " k:" << k << endl;
       
				j=0;
                while(l>255){
                        q.push_back(l%256);
							//cout << ", " << q.front() << " ";
						l=l/256;
                        j++;
                           }

                        q.push_back(l);
							//cout << ", " << q.front() << " ";
                        
				
//******** Sumowanie:   *************************************************
               if(o=="+" && wym==0) suma=sumuj(q);
			 if(o=="+" && wym==1 && k==1){
				q1=q;
				q.clear();
				} else if(o=="+" && wym==2 && k==1){
					 q1a=q;
					 q.clear();
				 } else if(o=="+" && wym==1 && k==2){
					 q2=q;
					 q.clear();
				 }else if(o=="+" && wym==2 && k==2){
					 q2=q;
					 q.clear();
				}
				
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
			   
		/*cout << "p: ";	
        while (p.size()>0) {
        cout << ", " << p.front() << " ";
        //p.pop_front();
		}
		cout << endl;	   
			   
		cout << "p1: ";	
        while (p1.size()>0) {
        cout << ", " << p1.front() << " ";
        //p1.pop_front();
		}
		cout << endl;
		cout << "q1a: ";
		while (q1a.size()>0) {
        cout << ", " << q1a.front() << " ";
        q1a.pop_front();
		}
		cout << endl;
		cout << "q2: ";
		while (q2.size()>0) {
        cout << ", " << q2.front() << " ";
        q2.pop_front();
		}
		cout << endl;
		cout << "q2a: ";
		while (q2a.size()>0) {
        cout << ", " << q2a.front() << " ";
        q2a.pop_front();
		}
		cout << endl;*/
        // cout << "Suma wynosi: " << suma << endl; 
		
/**************************************************************************************/
//******** Porownywanie c.d.:   ********************************************** 
		if(o=="?"){
			cout << porownaj(q1,q2) << endl ;
			
		}	
		
//****** Wypisywanie sumy na ekran:  ***********************************
      int sum;
	  if(o=="+"){  
		//q.clear();
		while(suma.size()>0){
        q.clear();
		i=0;
		sum=suma.front();
        while (sum >= 16){
        q.push_back(sum%16);
        sum=sum/16;
        i++;
        }

        q.push_back(sum);
        q.reverse();

        //cout << "Suma wynosi: ";
        for (int j=i; j>=0; j--) {
        cout << cyfry[q.front()];
		q.pop_front();
		}
		suma.pop_front();
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
			sum=wynik.back();
			
			//if (suma<10) q.push_back(0);
			while (sum >= 16){
			 q.push_back(sum%16);
			 sum=sum/16;
			//i++;
			}

			q.push_back(sum);
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
