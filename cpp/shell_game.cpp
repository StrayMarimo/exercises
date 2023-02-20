#include <bits/stdc++.h>

using namespace std;

int main(){
    int swaps, most_points = 0;
    int a, b, g;
    
    cin >> swaps;
    int shells[swaps][3];
    
    for (int i = 0; i < swaps; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> shells[i][j];
        }
    }
    
    for (int k = 1; k <= 3; k++) {
        int points = 0;
        int location = k;
        for (int i = 0; i < swaps; i++) {
            if (shells[i][0] == location){
                location = shells[i][1];
            } else if (shells[i][1] == location){
                location = shells[i][0];
            }
            
            if (shells[i][2] == location)
                points++;
        }
        
        if (points > most_points)
            most_points = points;
    }

    cout << most_points << endl;
    
    return 0;
    
    
}
