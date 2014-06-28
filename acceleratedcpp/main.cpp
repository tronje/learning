#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "input pls: " << endl;

    string name;
    cin >> name;

    const string greeting = "Hello, "+name+"!";

    const int pad = 1;
    const int rows = pad * 2 + 3;

    cout << endl;

    int r = 0;

    while (r != rows) {
        cout << endl;
        r++;
    }

    const string::size_type cols = greeting.size() + pad * 2 + 2;

    string::size_type c = 0;

    while (c != cols) {
        
    }
    return 0;
}