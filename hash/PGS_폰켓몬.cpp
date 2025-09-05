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
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

// PGS 폰켓몬 (hash) (L1)

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int max = nums.size() / 2;


    return min((int)s.size(), max);
}