/*
 Your are to create a program that will read an array A of N integers and displays its mean and mode.

 The mean (average) of a data set is found by adding all numbers in the data set and then dividing by the number of values in the set. The mode is the number that occurs most often in a data set.

 Input Format

 The first line of input is the size N of the array. The next line contains N number of integers.

 Constraints

 1 < N < 31

 Output Format

 Your program must output the computed mean, followed by a space, and the mode. Should it violate the constraints, display the word undetermined for both mean and mode. If there are scenarios that the mode cannot be determined, display the word undetermined for the mode.
 */


#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    int N, mode = 0;
    map<int, int> nums;
    int mean = 0, x;
    cin >> N;
    if (N <= 1 || N >= 31) {
        cout << "undetermined undetermined";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> x;
        mean += x;
        nums[x] += 1;
    }
    int count = 1;
    
    
    for (auto x: nums) {
        cout << x.first << ":" << x.second << endl;
        if (x.second == count)
            count = 1;
        else if (x.second > count) {
            count = x.second;
            mode = x.first;
        }

    }
    
    if ((mean % N ) == 0)
        cout << mean / N << " ";
    else
        printf("%.2f " , ((double) mean / N) * 1.0);
    if (count == 1)
        cout << "undetermined";
    else
        cout << mode;
    
    return 0;
}
