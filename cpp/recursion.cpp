#include <iostream>

using namespace std;
int call = 0;
void message(int times) {
    call++;
    cout << "The value of times in call " << call << ": " << times << endl;
    if (times > 0) {
        cout << "This is a recursive function. \n";
        message(times - 1);
    }
    cout << "Returning function with the value of times: " << times << endl;
    return;
}

int main() {
    message(5);
}
