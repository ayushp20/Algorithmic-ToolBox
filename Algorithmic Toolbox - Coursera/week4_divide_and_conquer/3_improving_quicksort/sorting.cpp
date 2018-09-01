#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void print(vector<int>a)
{
    for(int i=0;i<a.size();i++)
        std::cout<<a[i]<<" ";

    std::cout<<std::endl;
}

void partition2(vector<int> &a, int l, int r, int& p1, int& p2) {
  int x = a[l];
  p1=l,p2=r;
  int i=l+1;

  while(i<=p2){
        //std::cout<<"x="<<x<<" a[i]="<<a[i]<<"   j="<<p1<<"  k="<<p2<<"  ";
   if(a[i] > x)
   {
       swap(a[i],a[p2]);
       p2--;
   }
   else if(a[i] < x)
   {
       swap(a[i],a[p1]);
       p1++;
       i++;
   }
   else
       i++;
   //print(a);
  }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {

  if (l <= r) {

  int j = l, k = l;

  partition2(a, l, r, j, k);
  randomized_quick_sort(a, l, j-1);
  randomized_quick_sort(a, k + 1, r);
  }

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
