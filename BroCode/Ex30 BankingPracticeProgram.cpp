#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main() {
    
    double balance = 123;
    int choice = 0;

    do{
    cout << "*******************" << endl;
    cout << "1. Show Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
    cout << "*******************" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    //Limpa o cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch(choice){
            case 1: 
                showBalance(balance);
                break;
            case 2: 
                balance += deposit();
                showBalance(balance);
                break;
            case 3: 
                balance -= withdraw(balance);    
                showBalance(balance);
                break;
            case 4: 
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }while(choice != 4);
    
    
    return 0;
}
void showBalance(double balance){
    cout << "Your balance is: $" << setprecision(2) << fixed << balance << endl;
}

double deposit(){
    
    double amount = 0;

    cout << "Enter amount to be deposited: ";
    cin >> amount;

    if(amount > 0){
        return amount;
    }
    else{
        cout << "Not a valid amount!" << endl;
        return 0;
    }

}

double withdraw(double balance){

    double amount = 0;

    cout << "Enter amount to be withdrawn: ";
    cin >> amount;

        if(amount > 0 && amount <= balance){
        return amount;
    }
    else{
        cout << "Not a valid amount!" << endl;
        return 0;
    }
}