#include <assert.h>
#include <iostream>


int NumberOfOne_traversal(int n)
{
    int check = 1;
    int count = 0;
    for(; check!=0; check=check<<1)
       if((n&check) != 0) 
           ++count;
    return count;
}

int NumberOfOne_simple(int n)
{
    int check = 1;
    int count = 0;
    int changedNum = n;
    while(changedNum!=0)
    {
        changedNum = (changedNum-check) & changedNum;
        ++count;
    }
    return count;
}

int main()
{
    for(int i=0; i<=16; ++i){
        std::cout << NumberOfOne_traversal(i) << ' ' << NumberOfOne_simple(i) << std::endl;
    }
    return 0;
}

