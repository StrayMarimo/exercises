#include <iostream>

using namespace std;

int main() {
    string jon, doctor;
    
    cin >> jon >> doctor;
    if (doctor.length() <= jon.length())
        cout << "go";
    else
        cout << "no";
    return 0;
}
