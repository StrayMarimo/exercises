#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1])
            continue;
        else
            cout << s[i];
    }
    cout << s[s.length() - 1];
}
