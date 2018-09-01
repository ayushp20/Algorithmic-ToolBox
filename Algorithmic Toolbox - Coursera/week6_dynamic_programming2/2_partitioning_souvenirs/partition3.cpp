#include <iostream>
#include <vector>

using std::vector;

bool partition3(vector<int> &a) {
  //write your code here
    int n = a.size();
    int sum = 0;
    for(int i = 0;i < n; i++)
        sum += a[i];

    if(sum % 3 != 0)
        return 0;

    bool T[sum/3 + 1][n + 1];

    for (int i = 0; i <= n; i++)
        T[0][i] = true;

    for (int i = 1; i <= sum/3; i++)
        T[i][0] = false;

    for(int i = 1; i <= sum/3; i++)
        for(int j = 1; j <= n; j++){
             T[i][j] = T[i][j-1];

             if(i >= a[j-1])
               T[i][j] = T[i][j] || T[i - a[j-1]][j-1];

        }


    return T[sum/3][n];
    }

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
