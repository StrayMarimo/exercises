#include <iostream>
using namespace std;
string encrypt(string message, int shift) {
    string encrypted;
    int index;
    for (int i = 0; i < message.size(); i++){
        if (message[i] >= 35 && message[i] <= 60){
            index = (((message[i]-35) + shift) % 26);
            encrypted += (index+35);
            cout << index;
            if (i == message.size() - 1)
                cout << "]" << endl;
            else
                cout << ", ";
        }
        else
            encrypted += message[i];
    }
    return encrypted;
}

string decrypt(string message, int shift) {
    string decrypted;
    int index;
    for (int i = 0; i < message.size(); i++){
        if (message[i] >= 35 && message[i] <= 60){
            index = ((message[i]-35 - shift) % 26 + 26) % 26;  // (a%b+b)%b
            decrypted += (index+35);
            cout << index;
            if (i == message.size() - 1)
                cout << "]" << endl;
            else
                cout << ", ";
        }
        else
            decrypted += message[i];
    }
    return decrypted;
}
int main(int argc, char **argv) {
    string encrypted;
    if (argc != 3) {
        cout << "Invalid arguments" << endl;
        return 1;
    }
    else {
        cout << "Encrypted:\n[";
        cout << decrypt(argv[1], atoi (argv[2]));
    }
    return 0;
}
