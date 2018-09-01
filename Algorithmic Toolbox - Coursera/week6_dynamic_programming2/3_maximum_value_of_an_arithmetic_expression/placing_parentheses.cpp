#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
    //write your code here
    int n = exp.size();
    int numbers = (n + 1) / 2;
    long long min_a[n][n], max_a[n][n];

    for (int i = 0; i < numbers; i++){
      min_a[i][i] = (long long)exp[2*i] - '0';
      max_a[i][i] = (long long)exp[2*i] - '0';
    }

    for(int L = 0; L < numbers ; L++)
        for(int i = 0; i < numbers - L -1; i++){

          int j = i + L + 1;
          long long minVal = 2147483647;
          long long maxVal = -2147483646;

          for (int k = i; k < j; k++ )
          {
              long long a = eval(min_a[i][k],min_a[k + 1][j],exp[2 * k + 1]);
              long long b = eval(min_a[i][k],max_a[k + 1][j],exp[2 * k + 1]);
              long long c = eval(max_a[i][k],min_a[k + 1][j],exp[2 * k + 1]);
              long long d = eval(max_a[i][k],max_a[k + 1][j],exp[2 * k + 1]);
              minVal = min(minVal,min(a,min(b,min(c,d))));
              maxVal = max(maxVal,max(a,max(b,max(c,d))));
          }
          min_a[i][j] = minVal;
          max_a[i][j] = maxVal;
        }


    return max_a[0][numbers - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
