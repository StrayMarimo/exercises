//
//  main.cpp
//  greatest_pair
//
//  Created by Angeline Basbas on 1/30/23.
//

#include <iostream>

using namespace std;

int main() {
    int n, num;
    cin >> n;
        
    if (n < 2 || n > 99) {
        cout << "Not Possible";
        return 0;
    }
    int num1, num2;
    cin >> num1 >> num2;
    for (int i = 0; i < n - 2; i++) {
        cin >> num;
        if (num > num1 ||num > num2) {
            if (num1 > num2)
                num2 = num;
            else {
                num1 = num2;
                num2 = num;
            }
        }
            
    }
    cout << num1 << " " << num2 << endl;
       
    return 0;
    
}


/*
 11
 1 2 3 4 10 5 8 9 11 7 6
 
 10
 1 2 3 4 5 6 7 8 9 10
 
 1
 1
 
 99
 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 
 20
 20 18 16 15 13 14 12 11 9 10 7 8 6 5 17 19 4 3 2 1
 
 2
 1 2
 
 100
 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 
 
 
 
 
 */
