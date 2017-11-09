#include <assert.h>
#include <iostream>
#include <iomanip> //setw
#include <math.h> //pow


bool PowerStatus = false;


bool equal(double a, double b, double toleration=0.00001)
{
    if(a-b>-toleration && a-b<toleration)
        return true;
    else
        return false;
}


double Power_Iteratively_Abs_Exp(double base, int exponent)
{
    assert(exponent>=0);
    double result = 1.0;
    for(int i=1; i<=exponent; ++i)
        result *= base;
    return result;
}


double Power_Iteratively(double base, int exponent)
{
    if(equal(base, 0))
    {
        if(exponent<=0)
            PowerStatus = true;
        return 0.0;
    }
    
    if(exponent==0)
        return 1.0;
    else if(exponent==1)
        return base;
    else if(exponent>1)
        return Power_Iteratively_Abs_Exp(base, exponent);
    else 
        return 1.0 / (Power_Iteratively_Abs_Exp(base, -exponent));
}


double Power_Recursively(double base, int exponent)
{
    if(equal(base, 0))
    {
        if(exponent<=0)
            PowerStatus = true;
        return 0.0;
    }
    double result = 1.0;

    if(exponent==0)
        return 1.0;
    else if(exponent==1)
        return base;

    else if(exponent>1)
    {
        result = Power_Recursively(base, exponent>>1);
        if((exponent & 1) == 1)
            result *= result * base;
        else
            result *= result;
        exponent = exponent >> 1;
    }
    else
        result = 1.0 / (Power_Recursively(base, -exponent));
    
    return result;
}


int main()
{
    double base = -5;
    int exponent = -10;
    while(exponent<=10)
    {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << std::setw(12) 
                  << "base: " << base
                  << "    "
                  << std::setw(12) 
                  << "exponent: " << exponent
                  << std::endl;
        std::cout << std::setw(12) 
                  << Power_Iteratively(base, exponent)
                  << "    "
                  << std::setw(12) 
                  << Power_Recursively(base, exponent)
                  << "    "
                  << std::setw(12) 
                  << pow(base, exponent)
                  << std::endl;
        base += 0.5;
        ++exponent;
    }


    // std::cout << Power_Iteratively(base, exponent)
              // << "  "
              // << pow(base, exponent)
              // << std::endl;
    return 0;
}
