#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[3];
    map<char, int> m = {};
    string order;
    
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    
    cin >> order;
    sort(arr, arr + 3);
    m['A'] = arr[0];
    m['B'] = arr[1];
    m['C'] = arr[2];
    
    cout << m[order[0]] << " "
         << m[order[1]] << " "
         << m[order[2]];
    
    return 0;
}
