
#include <iostream>

using namespace std;

int memoizedCutRodAux(int p[], int n, int r[]) {
    int q;
    if (r[n - 1] >= 0)
        return r[n - 1];
    if (n == 0)
        q = 0;
    else {
        q = -1;
        for (int i = 0; i < n; i++) {
            q = max(q, p[i] + memoizedCutRodAux(p, n - i - 1, r));
        }
       
    }
     r[n - 1] = q;
    
        return q;
}

int memoizedCutRod(int p[], int n) {
    int r[n];
    for (int i = 0; i < n; i++)
       r[i] = -1;
   
   return memoizedCutRodAux(p, n, r);
}


int main()
{
    int n = 10;
    int p[] ={1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int i = 1; i <= n; i++){
        cout << memoizedCutRod(p, i) - 1 << endl;
    }
    
  
    return 0;
}

