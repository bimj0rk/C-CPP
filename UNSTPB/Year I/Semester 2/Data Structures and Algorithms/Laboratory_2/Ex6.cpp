//6
#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    private:
        string name;
        string address;
        string IBAN;
        double sum;
    
    public:
        BankAccount(){}
        BankAccount(string n, string a, string i, double sum){
            this->name = n;
            this->address = a;
            this->IBAN = i;
            this->sum = sum;
        }

        void deposit(double depositSum){
            this->sum += depositSum;
        }

        void withdraw(double withdrawSum){
            this->sum -= withdrawSum;
        }

        void displayBalance(){
            cout << "Balance: " << this->sum << endl;
        }

        void displayName(){
            cout << "Name: " << this->name << endl;
        }
};

int main(){
    BankAccount account("Adrian", "Independentei 313", "5378FSAG4124GDSA", 300);
    account.displayName();
    account.deposit(500);
    account.displayBalance();
    account.withdraw(100);
    account.displayBalance();
    return 0;
}