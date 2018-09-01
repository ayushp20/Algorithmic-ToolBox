#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];

    ll max=-1, index_max=0;
    for(int i=0;i<n;i++)
        if (arr[i]>max)
            max=arr[i],index_max=i;
    ll max2=-1;
    for(int i=0;i<n;i++)
        if (arr[i]>max2 && i!=index_max)
            max2=arr[i];

    ll result = (max*max2);

    cout<<result;

}
