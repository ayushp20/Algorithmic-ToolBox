#include <iostream>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.size(), n = str2.size();
  int T[m+1][n+1];

  for(int i = 0; i < m+1; i++)
      for(int j = 0; j < n+1; j++){
        if(i == 0)
            T[i][j] = j;
        else if( j == 0)
            T[i][j] = i;
        else{
            if( str1[i-1] == str2[j-1] )
                T[i][j] = T[i-1][j-1];
            else
                T[i][j] = min(T[i-1][j], min(T[i-1][j-1], T[i][j-1])) + 1;
        }
      }
  return T[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
