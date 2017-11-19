#include <assert.h>
#include <iostream>

long long Fibonacci(unsigned n)
{
    assert(n>=0);
    if(n<2)
        return n;
    
    long long ans = 0;
    long long f0 = 0;
    long long f1 = 1;
    for(unsigned i=2; i<=n; ++i)
    {
        ans = f0 + f1;
        f0 = f1;
        f1 = ans;
    }
    return ans;
}


int main()
{
    for(unsigned i=0; i<=20; ++i)
        std::cout << Fibonacci(i) << ' ';
    std::cout << std::endl;
    return 0;
}
