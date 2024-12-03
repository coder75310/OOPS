
#include <iostream>
#include <string>
using namespace std;

class Sorter {
public:
    int arr[100];
    int n;

    Sorter() {
        int a;
        cout << "enter the no. digits(max 9 numbers) you want to enter: \n";
        cin >> a;
        n = a;
        cout << "enter elements in array" << endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    virtual void sort() {
        cout << "base class sorting\n";
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; i < j; j--) {
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
            }
        }
    }

    void display() {
        for (size_t i = 0; i < n; i++) {
            cout << arr[i] << endl;
        }
    }
};

class NumberCombinerSorter : public Sorter {
public:
    void sort() override {
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; i < j; j--) {
                string a = to_string(arr[j]) + to_string(arr[j - 1]);
                string b = to_string(arr[j - 1]) + to_string(arr[j]);

                if (b > a) {
                    swap(arr[j], arr[j - 1]);
                }
            }
        }
    }

    void combine() {
        
        sort();

       
        string ans = "";
        for (int i = n-1; i >=0; i--) {
            ans += to_string(arr[i]);
        }
        cout << "Combined largest number: " << ans << endl;
    }
};

int main() {
    NumberCombinerSorter a;
   
    a.combine();
    return 0;
}