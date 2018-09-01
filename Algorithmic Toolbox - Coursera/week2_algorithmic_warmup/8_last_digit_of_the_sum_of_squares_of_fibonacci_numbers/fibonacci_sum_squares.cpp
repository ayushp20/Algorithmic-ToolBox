#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    int remainder=n%60;

    int fib[remainder+2];
    fib[0]=0,fib[1]=1;
    long long a=0,b=1;

    for(int i=2;i<remainder+2;i++)
    {
        long long tmp=a;
        a=b;
        b=(a+tmp)%10;
        fib[i]=b;

    }

    //for(int i=0;i<remainder+2;i++)
    //    std::cout<<fib[i]<<" ";

    return (fib[remainder+1]*fib[remainder])%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
