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

// PGS 이중 우선순위 큐 (Data structure) (L3)

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset<int> ms;

    for (string op : operations) {
        istringstream ss(op);

        string cmd; int num;
        ss >> cmd >> num;

        if (cmd == "I") {
            ms.insert(num);
        }
        else {
            if (ms.empty()) continue;
            else {
                if (num == 1) {
                    ms.erase(--ms.end());
                }
                else {
                    ms.erase(ms.begin());
                }
            }
        }
    }

    if (ms.empty()) {
        return { 0,0 };
    }
    else {
        return { *(--ms.end()), *ms.begin() };
    }

    return answer;
}