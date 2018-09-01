#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void optimal_sequence(int n) {
  std::vector<int> sequence(n+1);
  std::vector<int> ans(n+1);
  sequence[0] = 0, sequence[1] = 0;
  ans[0] = 0, ans[1] = 0;

  for(int i = 2; i < n+1; i++){
      /*if(i%2==0 && i%3==0){
        sequence[i] = min(sequence[i/3], min(sequence[i/2],sequence[i-1])) + 1;
        if(sequence[i/3] <=sequence[i/2] && sequence[i/3] <=sequence[i-1])
            ans[i] = 3;
        else if(sequence[i/2] <= sequence[i/3] && sequence[i/2] <= sequence[i-1])
            ans[i] = 2;
        else
            ans[i] = 1;
      }*/

       if(i%3==0){
        sequence[i] = min(sequence[i/3],sequence[i-1]) + 1;

        if(sequence[i/3] <= sequence[i-1])
            ans[i] = 3;
        else
            ans[i] = 1;
      }

      else if(i%2==0){
        sequence[i] = min(sequence[i/2],sequence[i-1]) + 1;
        if(sequence[i/2] <= sequence[i-1])
            ans[i] = 2;
        else
            ans[i] = 1;
      }

      else{
        sequence[i] = sequence[i-1] + 1;
        ans[i] = 1;
      }
  }
  cout<<sequence[n]<<endl;
  /*for(int i=0;i<n+1;i++)
    cout<<sequence[i]<<' ';
  cout<<endl;
  for(int i=0;i<n+1;i++)
    cout<<ans[i]<<' ';
  cout<<endl;*/
  vector<int> res;
  res.push_back(n);

  int i = n;
  while(i >= 2){
    if(ans[i] == 2){
        //cout<<i/2<<' ';
        res.push_back(i/2);
        i/=2;
    }
    else if(ans[i] == 3){
        //cout<<i/3<<' ';
        res.push_back(i/3);
        i/=3;
    }

    else if(ans[i] == 1){
        //cout<<i-1<<' ';
        res.push_back(i-1);
        i-=1;
    }

    else{
        //cout<<ans[i]<<' ';
        res.push_back(i-1);
        i--;

    }

  }

  for(int i = res.size()-1; i >= 0; i--)
    cout<<res[i]<<' ';
}

int main() {
  int n;
  std::cin >> n;
  optimal_sequence(n);

}
