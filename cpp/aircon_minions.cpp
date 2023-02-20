#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<pair<int, int>> ranges;
    int rooms = 1;
    
    int n, start, end;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        ranges.push_back(make_pair(start, end));
    }
    
    sort(ranges.begin(), ranges.end());
    
    for (int i = 0; i < ranges.size(); i++) {
        cout << ranges[i].first << " " << ranges[i].second << endl;
    }
    cout << endl;
    int i = 0, j = 1;
    while (j < ranges.size()) {
        if (ranges[i].second < ranges[j].first){
            rooms++;
            i = j; j++;
        } else j++;

    }
    
    cout << rooms;
}
 
