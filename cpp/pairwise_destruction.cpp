//
//  main.cpp
//  pairwise_destruction
//
//  Created by Angeline Basbas on 1/30/23.
//
/*
 Problem: Willo is a string freak. If in a sequence, two same words come together then he'll delete both. Now, what he wants is for you to automate the process.

 Input Format
 The the quick brown BrOwn Fox Jumps Over the lazy dog

 Constraints
    None.

 Output Format
 quick Fox Jumps Over the lazy dog
 Display the string on screen without the pairwise duplicates. If no strings left after the process, display Nothing is left
 */

#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
int main() {
    vector<string> words;
    
    string s;
    while (cin >> s) {
        words.push_back(s);
    }
    
    unsigned int i = 0;
    while (i < words.size() - 1) {
        string a = words[i];
        string b = words[i + 1];
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        if (a == b) {
            words.erase(words.begin() + i, words.begin() + i + 2);
            if (words.size() == 0) break;
        }
        else i++;
    }
    
    if (words.size() == 0)
        cout << "Nothing is left";
    else
        for (auto s: words)
            cout << s << " ";

    return 0;
}
