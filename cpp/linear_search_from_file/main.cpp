//
//  linear_search_from_file
//
//  Created by Angeline Basbas on 2/27/22.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int target = 0;
    string input_list;
    vector<int> v = {};
    string number;
    
    ifstream infile;
    infile.open("linear_search.txt");

    getline (infile, input_list);
    stringstream ss(input_list);
   
    while (getline(ss, number, ' '))
        v.push_back(stoi(number));
    
    infile >> target;
    infile.close();

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            cout << target <<" is found at index "<< i <<"."<<endl;
            return 0;
        }
    }
    cout << target << "is not found."<<endl;

    return 0;
}
