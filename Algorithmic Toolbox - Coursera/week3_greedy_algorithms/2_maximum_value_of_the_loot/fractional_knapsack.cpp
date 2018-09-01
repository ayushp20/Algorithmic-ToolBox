#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_desc(pair<double,double> a,pair<double,double> b)
{
    double r1 = a.first/a.second;
    double r2 = b.first/b.second;

    return r1>r2;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int curr_weight = 0;

  vector<pair<double,double>> ratio;
  for(int i=0;i<weights.size();i++)
        ratio.push_back(make_pair((double)values[i],(double)weights[i]));

  sort(ratio.begin(),ratio.end(),cmp_desc);

  for(vector<pair<double,double>>::iterator it=ratio.begin();it!=ratio.end()&&capacity!=0;it++)
  {
      if(it->second<=capacity)
      {
          value+=it->first;
          capacity-=it->second;
      }
      else
      {
          value+=(it->first)*capacity/(it->second);
          capacity=0;
      }
  }
  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
