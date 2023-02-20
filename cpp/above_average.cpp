#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int students[n];
        int mean = 0, ctr = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> students[i];
            mean += students[i];
        }
        mean /= n;
        
        for (int i = 0; i < n; i++) {
            if (students[i] > mean)
                ctr++;
        }
        
        printf("%.3f\%%n", (ctr / (n * 1.0)) * 100.0);
    }
    return 0;
}

