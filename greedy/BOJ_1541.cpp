#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

// BOJ 1541 잃어버린 괄호 (greedy) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin >> str;

    vector<string> tokens;
    string temp = "";
    for (char c : str) {
        if (c == '+' || c == '-') {
            tokens.push_back(temp);
            tokens.push_back(string(1, c));
            temp = "";
        }
        else {
            temp += c;
        }
    }
    tokens.push_back(temp);

    int result = stoi(tokens[0]);
    bool minus_mode = false;

    for (int i = 1; i < tokens.size(); i += 2) {
        string op = tokens[i];
        int num = stoi(tokens[i + 1]);

        if (op == "-") minus_mode = true;

        if (minus_mode) result -= num;
        else result += num;
    }

    cout << result;
}


