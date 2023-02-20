
#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
   
    while (cin >> N) {
        int sum = 1;
        for (int i = 2; i < sqrt(N); i++)
            if (N % i == 0)
                sum+= i + N / i;
        
        if (ceil((double)sqrt(N)) == floor((double)sqrt(N)))
            sum+= sqrt(N);
            
        cout << N << " ";
        if (sum == N)
            cout << "perfect\n";
        else if (abs(N - sum) <= 2)
            cout << "almost perfect\n";
        else
            cout << "not perfect\n";
    }
 
}

