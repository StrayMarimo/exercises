#include <bits/stdc++.h>
#define itr istream_iterator<string>
using namespace std;

int main () {
    string s;
    
    getline(cin, s);
    stringstream ss(s);
    itr begin(ss), end;
    vector<string> words(begin, end);
    
    sort(words.begin(), words.end());
    auto it = unique(words.begin(), words.end());
    
    if (it == words.end())
        cout << "yes";
    else
        cout << "no";
   
}


