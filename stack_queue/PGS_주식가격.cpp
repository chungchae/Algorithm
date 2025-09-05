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

// PGS 주식가격 (queue) (L2)

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int now = 0;

    for (int i = 0; i < prices.size(); i++) {
        now = 0;
        for (int k = i + 1; k < prices.size(); k++) {
            now++;
            if (prices[i] > prices[k])
                break;
        }
        answer.push_back(now);
    }
    return answer;
}