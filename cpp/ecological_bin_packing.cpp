//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=38



#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int getSum(vector<int> bottles, string permutation, int bottleCount) {
    
    int bin[3];
    int sum = 0;
    string BGC = "ABC";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (permutation[i] == BGC[j]) {
                bin[i] = bottles[i * 3 + j];
                break;
            }
               
        }
        sum+= bin[i];
    }
    
    return bottleCount - sum;
    
}

string revertBGC(string ABC) {
    string res = "";
    
    for (char c : ABC) {
        if (c == 'A')
            res += 'B';
        else if (c == 'B')
            res+=  'G';
        else
            res+= 'C';
    }
    
    return res;
    
}



int main() {
    string list;
    
    while (getline(cin, list)) {
        string BGC = "ABC", token;
        int bottleCount = 0;
        vector<int> bottles = {};
        istringstream ss(list);
       
        string order = "ABC", sorted_order;
        while (getline(ss, token, ' ')) {
            bottles.push_back(stoi(token));
            bottleCount+= stoi(token);
        }
        int minSum = bottleCount;
        do {
           
            int sum = getSum(bottles, BGC, bottleCount);
           
            if (sum < minSum) {
                order = BGC;
                minSum = sum;
            } else if (sum == minSum) {
                order = (revertBGC(order).compare(revertBGC(BGC)) < 0) ? order: BGC;
            }
               
            
        } while(next_permutation(BGC.begin(), BGC.end()));
        
        
        cout << revertBGC(order) << " " << minSum << endl;
    }
    
}

