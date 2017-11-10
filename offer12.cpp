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
    while(str[index]=='0' && str.size()>1)
        ++index;
    std::cout << std::string(str, index) << std::endl;
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


int main()
{
    PrintNumber_Iteratively(7);
    return 0;
}
