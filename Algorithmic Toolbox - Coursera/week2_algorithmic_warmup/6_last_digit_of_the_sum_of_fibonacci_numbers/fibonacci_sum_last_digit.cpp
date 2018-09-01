#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    int remainder=n%60; //pisano period of mod 10

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < remainder+1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }
    if(current==0)current=10;
    return (current-1) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
