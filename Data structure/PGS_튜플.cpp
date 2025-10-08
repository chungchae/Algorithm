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
#include <limits.h>

using namespace std;

// PGS 튜플 (Data Structure) (L2)

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> M;

    string temp = "";

    for (int i = 2; i < s.length() - 1; i++) {
        if (isdigit(s[i])) {
            temp += s[i];
        }
        else {
            if (temp != "") {
                M[stoi(temp)]++;
                temp = "";
            }
        }
    }

    vector<pair<int, int>> M_vector(M.begin(), M.end());
    sort(M_vector.begin(), M_vector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });

    for (pair<int, int> p : M_vector) {
        answer.push_back(p.first);
    }
    return answer;
}