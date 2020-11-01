#include<iostream>
#include<cstdlib>
using namespace std;

int horner(double wsp[],int st, int x)
{
	if(st==0)
		return wsp[0];
	
	return x*horner(wsp,st-1,x)+wsp[st];
}

int main()
{
	double *wspolczynniki;
	int stopien, argument;
	bool blad;
	
	cout<<"Podaj stopien wielomianu: (do 999999) ";
	cin>>stopien;
	while( cin.fail() || (stopien<=0) || (stopien >1000000))
        {
            blad = false;
            cout << "blad" << endl;
            cin.clear();
            cin.sync();
            cout<<"Podaj stopien wielomianu: (do 999999)";
			cin>>stopien;
        }
	
	wspolczynniki = new double [stopien+1];
	
	for(int i=0;i<=stopien;i++)
	{
		cout<<"Podaj wspo³czynnik stojacy przy potedze (do 999999) "<<stopien-i<<": ";
		cin>>wspolczynniki[i];
		if( cin.fail() || (wspolczynniki[i]>1000000) )
        {
            blad = false;
            cout << "blad" << endl;
            cin.clear();
            cin.sync();
            i--;
        }
		
	}
	
	cout<<"Podaj argument: (do 999999)";
	cin>>argument;
	while( cin.fail() || (argument>1000000))
        {
            blad = false;
            cout << "blad" << endl;
            cin.clear();
            cin.sync();
            cout<<"Podaj argument: (do 999999)";
			cin>>argument;
        }
	
	cout<<"W( "<<argument<<" ) = "<<horner(wspolczynniki,stopien,argument)<<endl;
	
	delete [] wspolczynniki;
	system("pause");
	return 0;
}
