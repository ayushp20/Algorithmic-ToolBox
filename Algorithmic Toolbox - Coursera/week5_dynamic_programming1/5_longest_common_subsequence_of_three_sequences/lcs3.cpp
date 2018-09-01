#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int m = a.size(), n = b.size(), l = c.size();
  int T[m+1][n+1][l+1];

  for(int i = 0; i < m + 1; i++)
    for(int j = 0; j < n + 1; j++)
        for(int k = 0; k < l + 1; k++){
            if(i==0||j==0 || k == 0)
                T[i][j][k] = 0;

            else if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
                T[i][j][k] = T[i-1][j-1][k-1] + 1;
            }
            else
                T[i][j][k] = max(T[i-1][j][k], max(T[i][j-1][k], T[i][j][k-1]));
        }
      return T[m][n][l];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
