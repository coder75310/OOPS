/* Implement Stack using template in C++  */
/* #include<iostream>
using namespace std;

template <typename T>
class stack{
    T *arr;
    int size;
    int top;

public:
    stack();
    void push(T);
    T pop();
    bool isfull();
    bool isempty();
};

template<typename T>
stack<T>::stack(){
    size=5;
    arr=new T[size];
    top=-1;
}

template<typename T>
void stack<T>::push(T data){
    arr[++top]=data;
}

template<typename T>
T stack<T>::pop(){
    return arr[top--];
}

template<typename T>
bool stack<T>::isfull(){
    return top==size-1;
}

template<typename T>
bool stack<T>::isempty(){
    return top==-1;
}

int main(){

    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    stack<char*> s2;
    s2.push("first");
    s2.push("second");
    s2.push("third");
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;

    return 0;
} */
















#include<iostream>
using namespace std;

template <class T>
class stack{
    T *arr;
    int size;
    int top;

public:
    stack(int);
    void push(T val);
    T pop();
    bool isfull();
    bool isempty();
};

template<class T>
stack<T>::stack(int maxsize){
    size=maxsize;
    arr=new T[size];
    top=-1;
}

template<class T>
void stack<T>::push(T val){
    if(!isfull()){
        arr[++top]=val;
    }
    else{
        cout<< "stack is full";
    }
    
}

template<class T>
T stack<T>::pop(){
    if(!isempty()){
        return arr[top--];
    }
    else{
        cout<<"stack is empty";
    }
}

template<class T>
bool stack<T>::isfull(){
    return top==size-1;
}

template<class T>
bool stack<T>::isempty(){
    return top==-1;
}

int main(){

    stack<int> s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    
    for(int i=0;i<5;i++){
    //for(int i=0;i<6;i++){
        cout<<s1.pop()<<endl;
    }
    cout<<endl;

    return 0;
}