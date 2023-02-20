#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    int homeworks = 0;
    getline(cin, s);
    stringstream ss(s);
    vector<string> ranges;
    string token;
    
    while(getline(ss, token, ';')) {
        ranges.push_back(token);
    }
    
    for (auto x : ranges) {
        if (x.find('-') != std::string::npos) {
            for (int i = 0; i < x.length(); i++)
                if (x[i] == '-')
                    homeworks +=  stoi(x.substr(i + 1, x.length() - i - 1)) - stoi(x.substr(0, i)) + 1;
        } else homeworks++;
    }
   
    cout << homeworks;
   
}


