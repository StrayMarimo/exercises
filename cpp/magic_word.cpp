/*
 Your program will read a word and determine if the word is a magic word. A magic word is a word that is read the same backwards and forwards. Some examples of magic words are redivider, deified, civic, radar, level, rotor, kayak, reviver, racecar, madam, and refer.

 Input Format

 Input contains 1 word and will be in small cases.

 Constraints

 The word will only consist of the letters of the alphabet.

 Output Format

 If the word is a magic word, then use the format below

 <word> is a magic word
 Otherwise, display

 <word> is NOT a magic word
 If it violates the constraint, display not possible.


 */

#include <iostream>
using namespace std;

int main() {
    string s;
    bool isMagic = true;
    cin >> s;
    
    for (char c : s) {
        if (c < 97 || c > 122) {
            cout << "not possible";
            return 0;
        }
    }
    
    int j = s.length() - 1;
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[j]) {
            isMagic = false;
            break;
        }
        j--;
    }
    
    if (isMagic) cout << s << " is a magic word";
    else cout << s << " is NOT a magic word";
    
    return 0;
}
