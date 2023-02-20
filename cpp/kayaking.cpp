#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, weight, instability = 0;
    vector<int> weights;
    
    cin >> n;
    
    for (int i = 0; i < 2 * n; i++) {
        cin >> weight;
        weights.push_back(weight);
    }
    
    sort(weights.begin(), weights.end());
    int i = 0;
    while (weights.size() > 2) {
        int dif1 = weights[i + 1] - weights[i];
        int dif2 = weights[i + 2] - weights[i + 1];
        if ( dif1 <= dif2 ) {
            instability += dif1;
            weights.erase(weights.begin() + i, weights.begin() + i + 2);
        } else {
            instability += dif2;
            weights.erase(weights.begin() + i + 1, weights.begin() + i + 1 + 2);
        }
    }
    
    cout << instability;
}
