//
//  main.cpp
//  scheduling_talks
//
//  Created by Angeline Basbas on 3/27/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// function prototypes
int getTime (string);
void sortShed(vector <int> &start, vector<int> &end, vector<int> &order, vector<string> &talks);
void printTalks(vector<int>, vector<string>);

int main() {
    // initialize variables
    vector<int> start = {}, end = {}, order{};
    vector<string> talks = {};
    string schedule = "";
    int talk = 1;
    // open and validate file
    ifstream infile;
    infile.open("scheduling_talks.in");
    if (!infile.is_open()) {
        cout<<"The file does not exist.";
        return 0;
    }

    // iterate through every line and save it to a string
    while (getline(infile, schedule)){
        //cout << getTime(schedule.substr(0,8)) << " - " << getTime(schedule.substr(11,8)) << endl;
        talks.push_back(schedule); // stores the whole string to list
        start.push_back(getTime(schedule.substr(0,8))); // calls function to convert start time to int and save it to list
        end.push_back(getTime(schedule.substr(11,8))); // calls function to convert start time to int and save it to list
        order.push_back(talk); // stores the talk number in a list
        talk++;   // increment while talks are being added
    }
    infile.close();
    cout<<"Original Talks: " << endl;
    printTalks(order, talks); // prints original order of talks
    sortShed(start, end, order, talks); // sorts order of talks by earliest to latest of the end time
    cout<<"Sorted Talks: " << endl;
    printTalks(order, talks); // pprints sorted order of talks
    cout<<"Optimal Schedule: " << endl;
    cout << "Talk " << order[0] << " - " << talks[0] << endl; // first talk is always chosen
    // compare each talk to the rest of the talk
    for (int i = 0; i < start.size(); i++){
        for (int j = i + 1; j < start.size(); j++) {
            if (end[i] <= start[j]) { // add the next talk if it is compatible with the current talk
                cout << "Talk " << order[j]<< " - " << talks[j] <<  endl;
                i = j - 1;
                break;
            }
        }
    }
    
}
// function to convert string time to int time
int getTime (string time) {
    int result = 0;
    // separate hours and minutes and type of day
    int hour = stoi(time.substr(0,2));
    int minutes = stoi(time.substr(3,2));
    string day = time.substr(6,2);
    // add 12 to hour if time of day is PM
    if (day == "PM")
        hour += 12;
    // multiply hour by 100
    if (hour != 12) // 12 AM = 0
        result = hour * 100;
    return (result += minutes); // return result with added minutes
}

// function to sort talks using the selection algorithm
void sortShed(vector <int> &start, vector<int> &end, vector<int> &order, vector<string> &talks) {
    int smallestSoFar = end[0];
    int address_min = 0, temp = 0, temp2 = 0, temp4 = 0;
    string temp3 = "";
    for (int i = 0; i < end.size(); i++)
    {
        smallestSoFar = end[i];
        for (int j = i; j < end.size(); j++)
            if (end[j] < smallestSoFar)
            {
                smallestSoFar = end[j];
                address_min = j;
            }
        if (smallestSoFar != end[i])
        {
            
            temp = end[address_min];
            temp2 = start[address_min];
            temp3 = talks[address_min];
            temp4 = order[address_min];
            end[address_min] = end[i];
            start[address_min] = start[i];
            talks[address_min] = talks[i];
            order[address_min] = order[i];
            end[i] = temp;
            start[i] = temp2;
            talks[i] = temp3;
            order[i] = temp4;
        }
    }
}

void printTalks(vector<int> order, vector<string> talks){
    for (int i = 0; i < talks.size(); i++)
        cout << "Talk " << order[i] << " - " << talks[i] << endl;
    cout<<endl;
}

