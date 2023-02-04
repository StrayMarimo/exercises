//
//  sort_list_from_file
//  insertion sort implementation
//  Created by Angeline Basbas on 3/2/22.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    //initialize variables
    string input_list;
    double element;
    vector<double> list = {};
    string number;
    ifstream infile;

    infile.open("doubles.in"); // open file

    // catch error if file failed to open
    if (!infile.is_open())
    {
        cout<<"The file does not exist.";
        return 0;
    }
    // store every line to vector
    while (getline(infile, number))
        list.push_back(stod(number));

    infile.close(); // close file

    // display original list
    cout<<"Unsorted List: \t";
    for (double num : list)
        cout << num << fixed << setprecision(2)<<  "\t";
    cout<<endl<<endl;
    // repeat block depending on the size of the vector
    for (int i = 1; i <= list.size(); i++)
    {
        // display ith pass
        cout << i;
        switch (i)
        {
            case 1: cout << "st"; break;
            case 2: cout << "nd"; break;
            case 3: cout << "rd"; break;
            default: cout<< "th"; break;
        }
        cout<<" pass: \t";
        // display current positions of every member of vector
        for (double num : list)
            cout<<num<<"\t";
        cout<<endl;

        // store first element of unsorted side to a temp variable
        element = list[i];
        int j = i - 1;  // initialize j to the last element of sorted side

        // repeat block until temp variable is
        // less than an element in the sorted side
        // or the first element is reached
        while (element < list[j] && j >=0)
        {
            list[j+1] = list[j]; // move elements to the right
            --j; // move index to the left
        }
        list[j+1] = element; // insert the element
        
    }
  
    return 0;
}
