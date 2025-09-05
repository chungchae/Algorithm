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

// PGS N개의 최소공배수 (Math) (L2)

using namespace std;

// 최대공약수
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
// 최소공배수
int func(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer;
    int temp = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        temp = func(temp, arr[i]);
    }
    return temp;
}

