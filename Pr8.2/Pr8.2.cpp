#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeParentheses(const string& input) {
    stack<int> indices;
    string result;

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '(') {
            indices.push(i);
        }
        else if (input[i] == ')') {
            if (!indices.empty()) {
                int start = indices.top();
                indices.pop();
                for (int j = start + 1; j < i; ++j) {
                    result += input[j];
                }
            }
        }
        else if (indices.empty()) {
            result += input[i];
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a letter string with parentheses: ";
    getline(cin, input);

    string result = removeParentheses(input);
    cout << "The line after removing the parentheses: " << result << endl;

    return 0;
}
