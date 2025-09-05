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

// PGS 전화번호 목록 (hash) (L2)

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        // find의 반환값이 0이면, 접두어
        if (phone_book[i + 1].find(phone_book[i]) == 0)
            return false;
    }
    return true;
}