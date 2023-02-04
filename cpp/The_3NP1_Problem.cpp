//
//  Solution to 3n + 1 problem
//  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
//  Created by Angeline Basbas on 2/2/23.
//

#include <iostream>
using namespace std;

int getCycleLength(int n) {
    int ctr = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n/=2;
        else
            n = n * 3 + 1;
        ctr++;
    }
    return ctr;
}

int main() {
    int i, j, temp;
    while (cin >> i) {
        cin >> j;
        cout << i << " " << j << " ";
        int max = -1, n;
        
        if (i > j) {
            temp = i;
            i = j;
            j = temp;
        }
        
        while (i <= j) {
            n = getCycleLength(i);
            if (n > max)
                max = n;
            i++;
        }
        cout << max << endl;
    }
    return 0;
}
