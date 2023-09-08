
#include <iostream>

using namespace std;

int BottomUpCutRod(int p[], int n) {
    int r[n];
    r[0] = 0;
    
    for (int j = 1; j <= n; j++){
        int q = -1;
        for (int i = 0; i < j; i++) {
            q = max(q, p[i] + r[j - i - 1]);
        }
        r[j] = q;
    }
    return r[n];
}


int main()
{
    int n = 10;
    int p[] ={1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int i = 1; i <= n; i++){
        cout << BottomUpCutRod(p, i) << endl;
    }
    
  
    return 0;
}


