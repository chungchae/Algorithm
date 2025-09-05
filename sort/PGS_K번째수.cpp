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

// PGS K번째 수 (sort) (L1)

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (int i = 0; i < commands.size(); i++) {
        temp.clear();
        for (int k = commands[i][0] - 1; k < commands[i][1]; k++) {
            temp.push_back(array[k]);
            sort(temp.begin(), temp.end());
        }
        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
}