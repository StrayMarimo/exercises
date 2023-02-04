
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
// prints the table
void printData(string c1, string c2, string c3, string c4, string c5, string c6, string c7) {
    cout << "| " << setw(4) << left << c1;
    cout << "| " << setw(10) << left << c2;
    cout << "| " << setw(10) << left << c3;
    cout << "| " << setw(10) << left << c4;
    cout << "| " << setw(10) << left << c5;
    cout << "| " << setw(10) << left << c6;
    cout << "| " << setw(10) << left << c7;
    cout << "| " << endl;
}
// gets the gcd and bezout's coefficients of 2 numbers using extended euclidian algorithm
int gcd(int x, int y, int& s_coefficient, int& t_coefficient) {
    int r, j = 0;
    vector<int> s = {1, 0}, t = {0, 1}, q = {};
    printData("j", "r[j]", "r[j+1]", "q[j+1]", "r[j+2]", "s[j]", "t[j]"); // prints headers
    while (y!= 0){
        r = x%y;
        q.push_back(x/y);
        if (j > 1) {
            s.push_back(s[j-2] - (s[j-1] * q[j-2]));
            t.push_back(t[j-2] - (t[j-1] * q[j-2]));
        }
        printData(to_string(j), to_string(x), to_string(y), to_string(q[j]), to_string(r), to_string(s[j]), to_string(t[j]));
        x = y;
        y = r;
        j++;
    }
    if (j>1) {
        s_coefficient = s[j-2] - (s[j-1] * q[j-2]);
        t_coefficient = t[j-2] - (t[j-1] * q[j-2]);
    }
    printData(to_string(j), "", "", "", "", to_string(s_coefficient), to_string(t_coefficient));
    return x;
}
int main(int argc, char **argv) {
    int s_coefficient = 0, t_coefficient = 1;
    if (argc != 3) {
        cout << "Invalid arguments" << endl;
        return 1;
    }
    else
        cout << gcd(atoi(argv[1]), atoi (argv[2]), s_coefficient, t_coefficient) << " is the GCD of " << argv[1]
        << " and " << argv[2] << ".\nIt's coefficients are: " << s_coefficient << " and " << t_coefficient << "." << endl;
    return 0;
}
