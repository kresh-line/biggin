#include <iostream>
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
