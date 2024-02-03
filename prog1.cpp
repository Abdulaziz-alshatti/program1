#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " filename" << endl;
        return 1;
    }

    // Open the file
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Cannot open file " << argv[1] << endl;
        return 1;
    }

    // Initialize the data structures
    queue<int> q;
    stack<int> stk;
    list<int> lst;

    // Read integers from the file and fill the data structures
    int number;
    while (inputFile >> number) {
        q.push(number);
        stk.push(number);
        lst.push_back(number);
    }

    // Close the file
    inputFile.close();

    // Sort the list
    lst.sort();

    // Print the queue
    cout << "QUEUE CONTENTS:\n";
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;

    // Print the stack
    cout << "STACK CONTENTS:\n";
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << endl;

    // Print the sorted list
    cout << "LIST CONTENTS:\n";
    for (int value : lst) {
        cout << value << ' ';
    }
    cout << endl;

    return 0;
}
