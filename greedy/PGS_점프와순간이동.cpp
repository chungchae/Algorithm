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

// PGS 점프와 순간 이동 (Greedy) (L2)

using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n != 1) {
        // 2로 나눠지면 순간이동,
        if (n % 2 == 0) {
            n /= 2;
        }
        // 아니라면 한 칸 이동 (건전지 사용)
        else {
            ans++;
            n -= 1;
        }
    }

    return ans + 1;
}

