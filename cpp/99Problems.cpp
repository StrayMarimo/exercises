#include <iostream>

using namespace std;

int main() {
    int num;
    int closest;
    
    cin >> num;
    
    if ((num % 100) >= 49 || num < 49)
        closest = num + (99 - (num % 100));
    else
        closest = num - (num % 100) - 1;
   
    cout << closest << endl;
    
    return 0;
}

