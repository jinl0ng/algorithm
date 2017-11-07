#include <iostream>
#include <assert.h>


int Min(int data[], int length)
{
    assert(data!=nullptr && length>0);
    if(length==1)
        return data[0];

    int start = 0;
    int end =length - 1;
    int mid = start;
    while(start<end)
    {
        if(end-start==1)
            return data[end];

        mid = (start+end) / 2;
        if(data[mid]>data[start])
            start = mid;
        else if(data[mid]<data[end])
            end = mid;
        else if(data[mid]==data[start] && data[mid]==data[end])
        {
            int min = data[start];
            for(int i=start+1; i<=end; ++i)
            {
                if(min>data[i]) 
                    min = data[i];
            }
            return min;
        }
    }
    return 0;
}

int main()
{
    int test[10] = {7,8,9,10,11,1,2,3,4,4};
    int test2[5] = {1,0,1,1,1};
    std::cout << Min(test, 10) << std::endl;
    std::cout << Min(test2, 5) << std::endl;
    return 0;
}
