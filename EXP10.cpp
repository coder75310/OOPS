#include<iostream>
using namespace std;

class InsufficientFundException: public runtime_error{
    public:
    InsufficientFundException(const string &msg) : runtime_error(msg){};  // iss se kya hoga mera jo runtime_error wala jo msg h vo mera update ho jaye

};

class InsufficientBalanceException: public runtime_error{
    public:
    InsufficientBalanceException(const string &msg) : runtime_error(msg){};
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
            throw InsufficientFundException("Insufficient amount");
     
            balance+=amount;
            cout<<amount<<" Rs. is credited successfully" <<endl;  

    }

    void withdraw(int amount){
        if(amount > 0 && amount<=balance){
            balance-=amount;
            cout<<amount<<" is debited successfully "<< endl;
        }
        else if(amount<0){
            throw InsufficientFundException(" amount should be greater than 0");   // exception statement 
        }
        else{
            throw InsufficientBalanceException ("Your balance is low");
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
    catch(const InsufficientFundException &e){
        cout<<"Exception occured: "<<e.what()<<endl;
    }
    catch(const InsufficientBalanceException &e){
        cout<<"Exception occured: "<<e.what()<<endl;
    }
    catch(const bad_alloc &e){  // jha par mere memory allocation bad tarike sai ho rha h  // bad allocation in memory
        cout<<"Exception occured: "<<e.what()<<endl;
    }
    catch(const char *e){  
        cout<<"Exception occured"<<endl;
    }
}
