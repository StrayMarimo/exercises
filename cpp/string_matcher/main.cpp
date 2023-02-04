//
//  main.cpp
//  string_matcher
//
//  Created by Angeline Basbas on 3/27/22.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void displayValues(vector<char>);
void displayValues(vector<unsigned long>);

int main(){
    
    string text = "", pattern = "";
    unsigned long pattern_size = 0, text_size = 0, pattern_pos = 0;
    vector<unsigned long> shifts = {}, headers = {};
    vector<char> row1 = {}, row2 {};

    //open and validate file
    ifstream infile;
    infile.open("string_matcher_input.in");
    if (!infile.is_open()) {
        cout<<"The file does not exist.";
        return 0;
    }
    // iterate until end of file and save every line to text
    while(infile >> text) {
        infile >> pattern;
        pattern_size = pattern.length(); // assign size of pattern to pattern_size
        text_size = text.length(); //assign size of current text to text_size
        // iterate from 0 to size of text minus size of pattern
        for (int text_pos = 0; text_pos <= (text_size-pattern_size); text_pos++) {
            pattern_pos = 0;
            // save current characters to be compared to vectors
            row1.push_back(text[text_pos+pattern_pos]);
            row2.push_back(pattern[pattern_pos]);
            headers.push_back(text_pos);
            //iterate through every letter in pattern if current character of text and pattern is equal
            while(pattern_pos < pattern_size && text[text_pos+pattern_pos] == pattern[pattern_pos]) {
                //store current characters to vectors
                if (pattern_pos != 0){
                    row1.push_back(text[text_pos+pattern_pos]);
                    row2.push_back(pattern[pattern_pos]);
                    headers.push_back(text_pos + pattern_pos);
                }
                pattern_pos++;
            }
            // if shift found, save current position and jump to uncompared characters in text
            if (pattern_pos > pattern_size-1)
            {
                shifts.push_back(text_pos);
                text_pos += pattern_size - 1;
            }
        }
        //display if match is found and their position/s
        if (shifts.size() == 0)
            cout<< "The text '"<< text << "' does not contain '" << pattern << "'."<< endl;
        else if (shifts.size() == 1)
            cout<< "The text '"<< text << "' contains '" << pattern << "' at position " << shifts[0] <<"."<< endl;
        else {
            cout<< "The text '"<< text << "' contains '" << pattern << "' at positions: ";
            for (int text_pos = 0; text_pos < shifts.size()-1; text_pos++)
                cout<<shifts[text_pos]<<", ";
            cout<<shifts[shifts.size() - 1]<<"."<< endl;
        }
        //display table to show comparisons
        displayValues(headers);
        displayValues(row1);
        displayValues(row2);
        cout << endl;
        // clear values stored in vectors for the next text
        row1.clear();
        row2.clear();
        headers.clear();
        shifts.clear();
    }
    return 0;
}

void displayValues(vector<char> values) {
    unsigned long n = values.size();
    cout<<"| ";
    for (char t : values)
         cout<<t<<"\t| ";
    cout<<endl;
    while (n--)
        cout<<"--------";
    cout<<"-"<<endl;
}

void displayValues(vector<unsigned long> values) {
    unsigned long n = values.size();
    while (n--)
         cout<<"--------";
    cout<<"-"<<endl;
    n = values.size();
    cout<<"| ";
    for (auto t : values)
        cout<<t<<"\t| ";
    cout<<endl;
    while (n--)
        cout<<"--------";
    cout<<"-"<<endl;
}
