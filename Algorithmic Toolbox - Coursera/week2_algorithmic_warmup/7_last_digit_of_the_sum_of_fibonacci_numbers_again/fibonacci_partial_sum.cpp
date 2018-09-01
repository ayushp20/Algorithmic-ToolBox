#include <iostream>
#include <vector>
#include<cmath>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long m, long long n) {

    if(n<=1)
        return n;

    long long remainder_m = m%60;
    long long remainder_n = n%60;
    if(remainder_m>remainder_n)
        std::swap(remainder_n,remainder_m);

    long long a=0,b=1,fm=0;

    for(int i=1;i<remainder_n+2;i++)
    {
        long long tmp=a;
        a=b;
        b=(tmp+a)%10;

    }

    a=0,fm=1;
    for(int i=1;i<remainder_m+1;i++)
    {
            long long tmp=a;
            a=fm;
            fm=(tmp+a)%10;
    }
    if(fm==0)
        fm=9;
    else
        fm--;



    if(b==0)b=9;
    if(b==1)b=10;
    else b--;
    //std::cout<<fm<<" "<<b<<std::endl;

    if(b<fm)
        b+=10;

    return (b-fm)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
