#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        vector<pair<int, int>> schedules;
        int n, start, end, tasks = 0;
        
        cin >> n;
        
        while (n--) {
            cin >> start >> end;
            schedules.push_back(make_pair(start, end));
        }
        
        sort(schedules.begin(), schedules.end());
        int i = 0, j = 1;
        while (i < schedules.size() - 1) {
            
            if (schedules[i].second <= schedules[j].first){
                tasks++;
                i++;
            }
            else j++;
        }
        
        cout << tasks << endl;
    }
}
