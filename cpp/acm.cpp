#include <bits/stdc++.h>
using namespace std;

struct Problem {
    bool solved = false;
    int tries = -1;
    int minutes = 0;
};
int main(){
    map<char, Problem> problems = {};
    vector<char> solved = {};
    int total = 0;
    
    char p;
    string verdict;
    
    int minutes;
    
    cin >> minutes;
    
    while(minutes != -1) {
        cin >> p >> verdict;
       
        if (verdict == "right")
            solved.push_back(p);
        problems[p].tries++;
        problems[p].solved = (verdict == "right");
        problems[p].minutes = minutes;
        
        cin >> minutes;
        
    }
    
    for (auto m : solved) {
        total += problems[m].minutes + (problems[m].tries * 20);
    }
    cout << solved.size() << " " << total;
    return 0;
}


