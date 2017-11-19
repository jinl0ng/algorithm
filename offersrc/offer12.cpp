#include <assert.h>
#include <iostream>
#include <string>


bool Increasement(std::string & str, int n)
{
    int takeOver = 0;
    bool isOverFlow = false;
    for(int i=n-1; i>=0; --i)
    {
        int nSum = str[i] - '0' + takeOver;
        if(i==n-1)
            ++nSum;

        if(nSum==10)
        {
            if(i==0)
            {
                isOverFlow = true;
                break;
            }
            else
            {
                takeOver = 1;
                str[i] = '0';
            }    
        }
        else 
        {
            str[i] = '0' + nSum;
            break;
        }
    }
    return isOverFlow;
}


void print(std::string str)
{
    int index = 0;
    bool isAllZero = true;
    for(size_t i=0; i<str.size(); ++i)
        if(str[i]!='0')
        {
            isAllZero = false;
            break;
        }
    if(isAllZero)
        std::cout << '0' << std::endl;
    else 
    {
        while(str[index]=='0' && str.size()>1)
            ++index;
        std::cout << std::string(str, index) << std::endl;
    }
}


void PrintNumber_Iteratively(int n)
{
    assert(n>=1);
    
    std::string str(n, '0');
    std::cout << '0' << std::endl;
    while(!Increasement(str, n))
        print(str);

    return;
}


void PrintNumber_Recursively_Core(std::string & str, size_t index)
{
    if(index==str.size())
    {
        print(str);
        return;
    }

    for(int i=0; i<=9; ++i)
    {
        str[index] = '0' + i;
        PrintNumber_Recursively_Core(str, index+1);
    }
}


void PrintNumber_Recursively(int n)
{
    assert(n>=1);

    std::string str(n, '0');
    for(int i=0; i<=9; ++i)
    {
        str[0] = '0' + i;
        PrintNumber_Recursively_Core(str, 1);
    }
}


int main()
{
    int n = 2;
    PrintNumber_Recursively(n);
    std::cout << "Iteratively : " << std::endl;
    PrintNumber_Iteratively(n);
    return 0;
}
