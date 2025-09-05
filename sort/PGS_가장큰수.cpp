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

// PGS 가장 큰 수 (sort) (L2)

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> str_num;

    for (int n : numbers) {
        str_num.push_back(to_string(n));
    }

    sort(str_num.begin(), str_num.end(), compare);

    if (str_num[0] == "0") return "0";

    for (string s : str_num) {
        answer += s;
    }

    return answer;
}