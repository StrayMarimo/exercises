#include <bits/stdc++.h>

using namespace std;

bool searchAverage(int *nums, int i, int j, double target) {
    while (i <= j) {
        if (nums[i] == target)
            return true;
        i++;
    }
    
    return false;
}

int main() {
    int N, ctr = 0;
    cin >> N;
    
    int flowers[N];
    for (int i = 0; i < N; i++) {
        cin >> flowers[i];
    }
    
    for (int i = 0; i < N; i++) {
        double avg = (double) flowers[i];
        for (int j = i + 1; j < N; j++) {
            avg += (double) flowers[j];
            if (searchAverage(flowers, i, j, avg / ((j - i + 1) * 1.0))) ctr++;
        }
    }

    cout << N + ctr;
}
