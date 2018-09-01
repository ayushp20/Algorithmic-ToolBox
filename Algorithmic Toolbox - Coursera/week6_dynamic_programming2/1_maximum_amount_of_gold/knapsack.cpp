#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(const int &W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  int *T = (int*)new int[301 * 10001];

  for (int i = 0; i < n + 1; ++i) {
    for(int j = 0; j < W + 1; j++){

        if(i == 0 || j == 0)
            T[j*(n+1) + i] = 0;

        else if(w[i-1] <= j)
            T[j*(n+1) + i] = std::max(T[(j-w[i-1])*(n+1)+ i-1] + w[i-1], T[j*(n+1) + i-1] );

        else
            T[j*(n+1) + i] = T[j*(n+1) + i-1];
        }
  }
  int ans = T[W * (n+1) + n];
  delete[] T;
  return ans;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
