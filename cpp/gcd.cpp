#include <iostream>

using namespace std;

int gcd(int, int);
int call = 0;
int main() {
    int ans;
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    ans = gcd(num1, num2);
    cout << "The greatest common divisor of " << num1;
    cout << " and " << num2 << " is " << ans << endl;

    return 0;
}

int gcd (int x, int y) {
    call++;
    int result = 0;
    cout << "Value of num1 and num2 in function call "
    << call << " are: " << x << " and " << y <<endl;
    if ( x % y == 0) {
        cout << "The result is "<< y << endl;
        return y;
    }
    else {
        result = gcd(y, x % y);
        cout << "The result is: " << result << endl;
        return result;
    }
        
}

