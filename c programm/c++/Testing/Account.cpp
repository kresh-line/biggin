/*#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
private:
    string onoma;
    double ypolipo;

public:
    Account(string kat, double ypol)
    {
        onoma = kat;
        try
        {
            if (ypol < 0)
                throw ypol;
            ypolipo = ypol;
        }
        catch (double d)
        {
            cout << "edhoses ypolipo: " << d << endl;
            cout << " to ypolipo tou logariasmo prepi na einai thetiko " << endl;
            ypolipo = 0.0;
        }
    }

    void print()
    {
        cout << "logariasmo: Katochos=  " << onoma << " Ypolipo: " << ypolipo << endl;
    }

    double getYpolipo()
    {
        return ypolipo;
    }

    void katathesi(double poso)
    {
        ypolipo += poso;
    }

    virtual void analipsi(double poso)
    {
        try
        {
            if (poso < 0)
                throw poso;
            if (poso <= ypolipo)
                ypolipo -= poso;
            else
                cout << " den uparxoun arketa xrimata " << endl;
        }
        catch (double d)
        {
            cout << "edhoses arnhtiko poso: " << d << endl;
        }
    }
};

class Pistotikos : public Account
{
private:
    float orio;

public:
    Pistotikos(string kat, double ypol, int limit) : Account(kat, ypol)
    {
        orio = limit;
    }

    void analipsi(double poso) override
    {
        if (poso > orio)
            cout << "perasate to orio tou analipsis: " << orio << endl;
        else if (poso > ypolipo)
            cout << "den yparxei eparkes ypolipo gia analipsi " << poso << endl;
        else
            ypolipo -= poso;
    }

    void print()
    {
        Account::print();
        cout << "Orio analipseon: " << orio << endl;
    }
};

void printAccounts(vector<Account> &accounts)
{
    cout << "\n \t stixeiologio logariasmwn: " << endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        accounts[i].print();
    }
}

int main()
{
    vector<Pistotikos> accounts;
    double ypolipo;
    string onoma;
    float orio;

    cout << "Enter ypolipo (-1 gia telos): ";
    cin >> ypolipo;

    while (ypolipo != -1)
    {
        cout << "Enter onoma katochou: ";
        cin >> onoma;
        cout << "Enter orio analipseon: ";
        cin >> orio;
        accounts.push_back(Pistotikos(onoma, ypolipo, orio));
        cout << "\nEnter ypolipo (-1 gia telos): ";
        cin >> ypolipo;
    }

    for (int i = 0; i < accounts.size(); i++)
        accounts[i].analipsi(100.0);

    double athroisma = 0.0;
    for (int i = 0; i < accounts.size(); i++)
        athroisma += accounts[i].getYpolipo();

    cout << "\nAthroisma ypoloipwn olwn twn logariasmwn: " << athroisma << endl;

    return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account{
    protected:
        string katochos;
        double ypoloipo;

    public:
    
        Account(string kat, double ypol){
            katochos = kat;
            try {
                if (ypol < 0)
                    throw ypol;
                ypoloipo = ypol;    
            }
            catch(double d) {
                cout << "Edwses Ypoloipo: " << d << endl;
                cout << "To ypoloipo tou logarismou prepei na einai thetiko \n";
                ypoloipo = 0.0;    
            }
            
        }

        double getYpoloipo(){
            return ypoloipo;
        }

        void print(){
            cout << "Katochos: "<< katochos << " \t Ypoloipo: "<<ypoloipo << endl;
        }

        void katathesi(double poso){
            ypoloipo += poso;
        }

        void analipsi(double poso){
            try{
                if (poso < 0)
                    throw poso;
                if (poso <= ypoloipo)
                    ypoloipo -= poso;
                else 
                    cout << "Den yparxei eparkes ypoloipo\n";

            }
            catch (double d){
                cout << "Edwses arnhtiko poso analipsis\n";
            }
            
        }

};

class Pistotikos : public Account
{
	double orio;

public:
	Pistotikos(string o, double p, double limit) : Account(o, p), orio(limit) { }

	void analipsi(double p)
	{
       if (p > orio)
            cout << "To poso ths analipsisi xepernaei to orio analipsewn\n";      
       else
			Account::analipsi(p);
	}
};

int main(){
    vector<Pistotikos> accounts;
    double ypoloipo, orio;
    string onoma;
    cout << "Dwse ypoloipo (-9999 gia telos): ";
    cin >> ypoloipo;

    while (ypoloipo != -9999){
        cout << "Dwse onoma katochou: ";
        cin >> onoma;
        cout << "Dwse orio analipsewn: ";
        cin >> orio;
        accounts.push_back(Pistotikos(onoma, ypoloipo, orio));
        cout << "\nDwse ypoloipo (-9999 gia telos): ";
        cin >> ypoloipo;
    }

  

     cout << "\nStoixeia Logariasmwn" << endl;
     for (int i = 0; i < accounts.size(); i++)
     {
         accounts[i].print();
     }

    
     cout << "\nAnalipsi 100 Euro apo olous tous Logariasmous" << endl;
     for (int i = 0; i < accounts.size(); i++)
     {
         accounts[i].analipsi(100);
     }

     double sum = 0.0;
     for (int i = 0; i < accounts.size(); i++)
     {
        sum += accounts[i].getYpoloipo();
     }

     cout << "To synolo twn katathesewn einai " << sum << endl;



    return 0;
}