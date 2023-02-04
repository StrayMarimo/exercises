#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string input_list;
    vector<int> v = {};
    string number;
    
    ifstream infile;
    infile.open("selection.txt");

    getline (infile, input_list);
    stringstream ss(input_list);
   
    while (getline(ss, number, ' '))
        v.push_back(stoi(number));

    infile.close();

    int smallestSoFar = v[0];
    int address_min = 0;
    int temp = 0;

    for (int i = 0; i < v.size(); i++)
    {
        smallestSoFar = v[i];
        for (int j = i; j < v.size(); j++)
        {
            if (v[j] < smallestSoFar)
            {
                smallestSoFar = v[j];
                address_min = j;
            }
        }
        
        if (smallestSoFar != v[i])
        {
            temp = v[address_min];
            v[address_min] = v[i];
            v[i] = temp;
        }
    
    }
    cout << "arranged list: ";
     for (int x : v)
            cout<<x<<" ";
    return 0;

}
