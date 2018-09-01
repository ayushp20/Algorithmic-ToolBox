#include <iostream>

long long pisano_period(long long m)
{
    long long a=0,b=1,c=a+b;
    for(long long len=0;len<m*m;len++)
    {
        c=(a+b)%m;
        a=b;
        b=c;

        if(a==0&&b==1)
            return len+1;
    }

}
int get_fibonacci_huge(long long n,long long m)
{
    if(n<=1)
        return n;

    long long period = pisano_period(m);
    //std::cout<<period<<std::endl;
    long long remainder = n%period;
    if (remainder==0)
        return 0;

    long long a=0,b=1,c=a+b;
    for(int i=1;i<remainder;i++)
    {
        c=(a+b)%m;a=b;b=c;
    }

    return c%m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
