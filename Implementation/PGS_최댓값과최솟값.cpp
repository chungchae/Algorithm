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

// PGS 최댓값과 최솟값 (Implementation) (L2)

using namespace std;

string solution(string s) {
    string answer = "";
    string temp;
    int min_num = 1e9;
    int max_num = -1e9;

    for (char c : s) {
        if (c == ' ') {
            min_num = min(min_num, stoi(temp));
            max_num = max(max_num, stoi(temp));
            temp = "";
        }
        else {
            temp += c;
        }
    }
    if (temp != "") {
        min_num = min(min_num, stoi(temp));
        max_num = max(max_num, stoi(temp));
    }
    answer += to_string(min_num);
    answer += " ";
    answer += to_string(max_num);

    return answer;
}

