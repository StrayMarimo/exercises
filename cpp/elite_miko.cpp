
/*
 You can't spell elite without Miko. Whether it's going up the roof and trying to control the wind where she ends up falling or driving a plane upside-down where she ends up crashing, she truly defines the epitome of being an elite.

 You'll be given T lines of phrases. You are tasked to change every elite word, if there are any, to miko.

 Input Format

 The first line of input contains an integer T denoting the number of test cases or phrases. The next T lines will contain a phrase or words separated by a space.

 Constraints

 5 <= T <= 100

 5 <= |words| <= 10

 All words are in lower cases and do not contain special characters.

 Output Format

 For each line of input, output the phrase where the elite word is changed to miko.
 */

#include <iostream>

using namespace std;

int main() {
    int t;
    string sentence, word = "";
    
    cin >> t;
    cin.ignore();
    while(t--) {
        getline(cin, sentence);
        for (unsigned long i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ' || i == sentence.length() - 1) {
                if (i == sentence.length() - 1)
                    word += sentence[i];
                if (word == "elite")
                    cout << "miko ";
                else
                    cout << word << " ";
                word = "";
            } else
                word += sentence[i];
        }
        cout << endl;
        
    }
}
