#include <iostream>

using namespace std;
int factorial(int);
int call = 0;
int main() {
    int number = 5;
    int result;
    cout << "Enter an integer value and I will display its factorial: ";
    cin >> number;
    result = factorial(number);
    cout << "The factorial of " << number << " is " << result << endl;

    return 0;
}

int factorial (int num){
    call++;
    int res;
    int prev;
    cout << "Value of num in function call " << call << ": " << num << endl;
    if (num == 0)
        return 1;
    else{
        prev = factorial(num - 1);
        res = num * prev;
        cout <<num<<" * "<< prev <<  " = " << res  << endl;
        return res;
    }
  
}
