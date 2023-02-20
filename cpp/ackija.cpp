#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, total = 0;
    cin >> N;
    
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
        
    sort (arr, arr + N, greater <> ());
    int groups = floor(N / 3.0);
    
    for (int i = 0; i <= (groups * 3) - 1; i++)
        if ((i + 1) % 3 != 0)
            total += arr[i];
    for (int i = N - 1; i >= N - N % 3; i--)
        total += arr[i];
    cout << total;
}
