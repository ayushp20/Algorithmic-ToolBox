#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cmp(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);

    return ab.compare(ba) > 0? 1 : 0;
}


string largest_number(vector<string> a) {

    //std::cout<<a.size();

  sort(a.begin(),a.end(),cmp);
  std::stringstream ss;
  for(int i=0;i<a.size();i++)
    ss<<a[i];
  string result;
  ss>>result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
