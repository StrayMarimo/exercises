/*
 Your task is simple, given a list of numbers, display the sum of all odd and even numbers.

 Input Format

 The first line of input contains the number of items N to process. Next line contains N integers separated by spaces.

 Constraints

 0 < N < 100

 Output Format

 Display the sum of all odd and even numbers separated by a space. Otherwise, display Not Possible
 */
#include <iostream>

using namespace std;

int main() {
    
    int N, x, sum_odd = 0, sum_even = 0;
    
    cin >> N;
    
    if (N <= 0 || N >= 100) {
        cout << "Not Possible";
        return 0;
    }
    
    while (N--) {
        cin >> x;
        if (x % 2 == 0)
            sum_even += x;
        else
            sum_odd += x;
    }
    
    cout << sum_odd << " " << sum_even;
    return 0;
}

