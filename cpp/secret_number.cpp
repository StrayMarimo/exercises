/*
 Clark and Leah got their happy ending last night. It was a blast! As part of the tradition, the next bride and groom must be chosen. To do this, they gave the eligible bachelors and bachelorettes pieces of paper with texts. Their task is simply to decode a secret number given the following instructions:

 The first number in the text is always the base number.
 If the succeeding number in the text is
 preceded and succeeded by a vowel, subtract the number to the base number;
 preceded by a consonant and succeeded by a vowel and vice-versa, add the number from the base; or
 preceded and succeeded by a consonant, multiply the base by 2.
 For other numbers not defined by the rules above, ignore and proceed to the next.
 The last bachelor and bachelorette to guess the number gets to be the next bride and groom.

 Input Format

 Input has several lines of text.

 Constraints

 base number >= 0

 Output Format

 Display the secret number.

 Sample Input 0

 Just 100 smile for me and le20t the day begin
 You are the sunshine that Lights
 my he10art with in30
 I'm sure t10hat you're an angel in disguise
 Come take my ha10nd and together we will rise
 On the wings of lov10e
 Up and above the clo50uds
 The only way to fly is
 On the wings of love 1000
 Sample Output 0

 190
 vv: -x
 cc: *= 2
 vc or cv: + x
 
 100
 120
 110
 220
 230
 240
 190
 
 */


#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    
    return false;
}


int transformCode(char a, char b, int num, int base) {
    
    bool isVowelA = isVowel(a);
    bool isVowelB = isVowel(b);
    cout << a << b << isVowelA << " " << isVowelB << " " << num;
    if (isVowelA && isVowelB) {
        cout << " case 1" << endl;
        return base - num;
    }
        
    if (!isVowelA && !isVowelB) {
        cout << " case 1" << endl;
        return base *= 2;
    }
       
    cout << " case 3" << endl;
    return base += num;
}

int main() {
    
    string line;
    int number = 0;
    
    
    while (getline(cin, line)) {
        cout << line << endl;
        string num = "";
        int i = 0;
        if (number == 0) {
            // get base
            for (; i < line.length(); i++){
//                cout << line[i] << isdigit(line[i]) << endl;
                if (isdigit(line[i])) {
                    while (isdigit(line[i])) {
                        num+= line[i];
                        i++;
                    }
                    cout << num << endl;
                    number = stoi(num);
                    num = "";
                    break;
                    
                }
            }
        }
        
        for (; i < line.length() - 1; i++) {
//            cout << line[i] << isdigit(line[i]) << endl;
            if(isdigit(line[i])) {
                int j = i;
                while (isdigit(line[j]) && j < line.length() - 1){
                    num+= line[j];
                    j++;
                }
                if (j == line.length() - 1 && !isalpha(line[j])) break;
                if (isalpha(line[i - 1]) && isalpha(line[j]))
                    number = transformCode(line[i - 1], line[j], stoi(num), number);
                cout << number << endl;
                i = j;
            }
        }
        
        
    }
    
    
}
