// https://codeforces.com/contest/1801/problem/A
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int T, N;
   
   cin >> T;
   while (T--) {
       cin >> N;
       int nums[N];
       for (int i = 0; i < N; i++)
           cin >> nums[i];
        
       sort(nums, nums + N, greater<int>());
       int ctr = 0;
       for (int i = 0; i < N; i++) {
           if (nums[i] > 0) {
               ctr++;
           } else if (nums[i] < 0)
                ctr--;
           cout << ctr << " ";
       }
       cout << endl;
       int j = N - 1;
       int k = 0;
       ctr = 0;
       for (int i = 0; i < N; i++) {
           if (i % 2 == 0) {
               if (nums[k] > 0) ctr++;
               else ctr--;
               k++;
           } else {
               if (nums[j] > 0) ctr++;
               else ctr--;
               j--;
           }
           cout << ctr << " ";
       }
       cout << endl;
   }

    return 0;
}



