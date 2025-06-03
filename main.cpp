#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers = { 11, 7, 3, 6, 19, 76, 33 };
    vector<int> evenNumbers;

    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenNumbers.push_back(*it);  
        }
    }

    cout << "Even numbers: ";
    for (vector<int>::iterator it = evenNumbers.begin(); it != evenNumbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
