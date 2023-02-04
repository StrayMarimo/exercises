#include  <iostream>
using namespace std;
int fib(int);

int main(void){
    cout << "The first 9 Fibonacci numbers are: \n";
    for (int x = 0; x < 9; x++)
    {
       // cout << "Calling fib(" << x << ")" << endl;
        cout << fib(x) << endl;
    }
        
    cout << endl;
}

int fib(int n) {
    int result;
    int num1, num2;
    if (n <= 0) {
        //cout << "0" << endl;
        return 0; }
    else if (n == 1) {
        //cout << "1" << endl;
        return 1;
    }
    else{
        num1 = fib(n-1);
        num2 = fib(n-2);
        result = num1 + num2;
        //cout << num1 << " + " << num2 << " = " << result << endl;
        return result;
    }
        
}


