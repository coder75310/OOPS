#include<iostream>
using namespace std;

class InvalidAmountError: public runtime_error{
    public:
    InvalidAmountError(const string &msg) : runtime_error(msg){};  // runtime_error message update

};

class InsufficientBalanceError: public runtime_error{
    public:
    InsufficientBalanceError(const string &msg) : runtime_error(msg){};
};

class customer{
    string name;
    int balance;
    int account_number;

    public:

    customer(string name, int balance, int account_number){
        this-> name = name;
        this-> balance = balance;
        this-> account_number = account_number;
    }

    void deposit(int amount){

        if(amount<=0)
            throw InvalidAmountError("Insufficient amount");
     
            balance+=amount;
            cout<<amount<<" Rs. is credited successfully" <<endl;  

    }

    void withdraw(int amount){
        if(amount > 0 && amount<=balance){
            balance-=amount;
            cout<<amount<<" is debited successfully "<< endl;
        }
        else if(amount<0){
            throw InvalidAmountError(" amount should be greater than 0");   // exception statement 
        }
        else{
            throw InsufficientBalanceError ("Your balance is low");
        }
    }
};

int main(){

    customer c1("Ankit", 5000, 101);

    try{
        c1.deposit(100);
        c1.withdraw(6000);
        c1.deposit(100); // this statement is not run
    }
    catch(const InvalidAmountError &e){
        cout<<"Exception occured: "<<e.what()<<endl;
    }
    catch(const InsufficientBalanceError &e){
        cout<<"Exception occured: "<<e.what()<<endl;
    }
    catch(const bad_alloc &e){  
        cout<<"Exception occured: "<<e.what()<<endl;
    }
    catch(const char *e){  
        cout<<"Exception occured"<<endl;
    }
}
// " e.what() " is used to print InvalidAmountError, InsufficientBalanceError