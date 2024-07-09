
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minReversal(string str) {
    int l = str.length();
    int count = 0;
    stack<char> s;

    // Check if the length of the string is odd, then it can't be balanced.
    if (l % 2 == 1) {
        return -1;
    }

    for (int i = 0; i < l; i++) {
        if (str[i] == '{') {
            s.push('{');
        } else {
            if (s.empty()) {
                s.push('}');
            } else if (!s.empty() && s.top() == '{') {
                s.pop();
            } else if (!s.empty() && s.top() == '}') {
                s.push('}');
            }
        }
    }

    // The stack now contains only unbalanced brackets.
    while (!s.empty()) {
        char c1 = s.top();
        s.pop();
        char c2 = s.top();
        s.pop();

        // For every pair of brackets, one reversal will make them balanced.
        if (c1 == c2) {
            count++;
        } else if (c1 == '}' && c2 == '{') {
            count += 2;
        }
    }

    return count;
}

int main() {
    string str = "{{{}}}";
    int result = minReversal(str);
    cout << "Minimum number of reversals required: " << result << endl;
    return 0;
}

