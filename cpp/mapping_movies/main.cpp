//
//  main.cpp
//  mapping_movies
//
//  Created by Angeline Basbas on 3/2/22.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int main() {
    // Initialize variables
    unsigned long target = 0, high = 0, mid = 0, low  = 0, year = 0;
    
    map<unsigned long, string> Movies;
    vector<int> years;
    bool found = false;
    string title = "", line = "";
    ifstream infile;

    infile.open("movies.in"); //open file

    // catch error if file failed to open
    if (!infile.is_open()) {
        cout<<"The file does not exist.";
        return 0;
    }

    // parse every line into year and title and store it in a map
    while (getline(infile, line)){
        Movies.insert(make_pair(
            stoi(line.substr(0, 4)), // key is the substring from index 0 until the 4th character converted to integer
            line.substr(5, string::npos))); // value is the substring from index 5 until the end of string
        years.push_back(stoi(line.substr(0, 4))); // store every year in a vector
    }

    infile.close(); // close the file

    // display choices
    cout<<"Choose year: "<<endl;
    for (int year: years)
        cout<<year<<"\t";
    cout<<endl;

    // input valid year to search
    do {
       cout << "Enter year: ";
       cin>>target;
    } while (target < 0);
    
    high = Movies.size() - 1; // set upper limit to last index
  
    // repeat block until lower limit is greater than upper limit
    while (low <= high) {
        mid = low + (high - low)/2; // formula to find index of median
        // set found to true and end loop if target is found in the list
        if (years[mid] == target) {
            found = true;
            break;
        }
        // search the lower half of the list if median is greater than target
        if (years[mid] > target)
            high = mid - 1;
         // search the upper half of the list if median is greater than target
        else
            low = mid + 1;
    }
     // if the target exists in the list, display the title, year, and index of the movie
     if (found) {
        cout << "Movie title   - " << Movies[target] <<endl;
        cout << "Year released - " << target << endl;
        cout << "Index         - " << mid << endl;
     }
    // display this message if not found.
     else
         cout << "There is no MCU movie released on "
         << target << "." << endl;

    return 0;
}

