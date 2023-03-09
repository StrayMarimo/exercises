#include <iostream>

using namespace std;

int pow(int a,int b)
{
    if(b == 0) return 1;
    else if(b % 2 == 0) return pow(a,b/2) * pow(a,b/2);
    else return a * pow(a,b-1);
}
int main() {
   
   cout << pow(2, 8);

    return 0;
}

