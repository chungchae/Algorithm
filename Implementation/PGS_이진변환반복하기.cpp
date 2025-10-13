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

// PGS 이진 변환 반복하기 (Implementation) (L2)

string bin_convert(int n) {
    string result = "";

    while (n != 0) {
        if (n % 2 == 1) {
            result += "1";
        }
        else {
            result += "0";
        }
        n /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int convert_count = 0; int zero_count = 0;

    while (s != "1") {
        convert_count++;
        int z_temp = 0; int o_temp = 0;

        for (char c : s) {
            if (c == '0') z_temp++;
            else o_temp++;
        }

        s = "";
        zero_count += z_temp;
        for (int i = 0; i < o_temp; i++) {
            s += "1";
        }
        s = bin_convert(s.length());
    }

    answer = { convert_count, zero_count };

    return answer;
}