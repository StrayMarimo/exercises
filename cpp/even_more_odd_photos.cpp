#include <bits/stdc++.h>

using namespace std;

int group(int odd, int even) {
    int diff = odd - even;
    
    if (diff == 0)
        return odd + even;
    else if (diff == 1)
        return odd + even - 2;
    else if (diff == 2)
        return odd + even - 1;
    else {
        odd -= 2;
        even += 1;
    }
    
    return group(odd, even);
}


int main() {
    int N, odd = 0, even = 0, cow;
    
    cin >> N;
    
    while (N--) {
        cin >> cow;
        if (cow % 2 == 0) even++;
        else odd++;
    }
    
    if (even > odd)
        cout << 2 * odd + 1;
    else
        cout << group(odd, even);
    
    return 0;
}
