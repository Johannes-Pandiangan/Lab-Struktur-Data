#include <iostream>
#include <stack>
using namespace std;

//implementasi stack pada linked list
int main() {
    stack<int> s;
    int input;

    while(cin >> input) {
        s.push(input);
    } do {
        cout << s.top() << " ";
        s.pop();
    } while (s.size() != 0);

    cout<< endl;
    return 0;
}