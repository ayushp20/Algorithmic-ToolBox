#include <iostream>
using namespace std;

int get_change(int m) {
    int a[m+1];
    int coins[3]= {1, 3, 4};
    a[0]=0;



    for(int i=1; i <= m+1; i++){
            int min_coins = 2147483647;
            for(int j = 0; j < 3 && i >= coins[j]; j++){
                a[i] = min(a[i-coins[j]], min_coins );
                min_coins = a[i];
            }

            a[i] = min_coins + 1;
        }
  //write your code here
  return a[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
