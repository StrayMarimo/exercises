#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;

double func (double x) { return log(x) + x; }
double toInt(double x) { return x * pow(10, 10);}
string truncate(double x) { return to_string(toInt(x)).substr(0, 10);}

int main() {
    double low;
    double up;
    double midpoint;
    string prev = "", current = "";
    int itr = 1;
    
    do {
        cout << "Input A: ";
        cin >> low;
        cout << "Input B: ";
        cin >> up;
        if (func(low) * func(up) > 0)
            cout << "Invalid input. Try again." << endl;
    } while (func(low) * func(up) > 0);
    
    midpoint = ((toInt(low) + toInt(up)) / 2) / pow(10, 10);
    
    current = truncate(midpoint);
    cout << "Iteration " << itr << ": " << midpoint << setprecision(15) << endl;
    do {
        prev = current;
        if ((func(low) * func(midpoint)) < 0) {
            up = midpoint;
        } else if ((func(low) * func(midpoint)) > 0) {
            low = midpoint;
        } else {
            break;
        }
        midpoint = ((toInt(low) + toInt(up)) / 2) / pow(10, 10);
        current = truncate(midpoint);
        itr++;
        cout << "Iteration " << itr << ": "<< midpoint << setprecision(15) << endl;
        
    } while (prev != current);
}
