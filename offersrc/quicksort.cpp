#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int swap(int * a, int * b)
{
    assert(a!=nullptr && b!=nullptr);
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

int Partition(int data[], int length, int start, int end)
{
    srand(time(NULL));
    assert(data!=nullptr && start>=0 && end<length && start<=end);

    int index = rand() % (end-start+1) + start;
    swap(&data[index], &data[end]);
    int small = start - 1;

    for(index=start; index<end; ++index)
    {
        if(data[index]<data[end])
        {
            ++small;
            swap(&data[index], &data[small]);
        }
    }
    
    ++small;
    swap(&data[small], &data[index]);
    return small;
}

int QuickSort(int data[], int length, int start, int end)
{
    assert(data!=nullptr && length>0 && start>=0 && end>=0 && end<length && start<=end);
    if(start==end)
        return 0;

    int index = Partition(data, length, start, end);
    if(index>start)
        QuickSort(data, length, start, index-1);
    if(index<end)
        QuickSort(data, length, index+1, end);
    return 0;
}

int main()
{
    int data[] = {12,32,2,35,1,2,3,4,123,123,2,3,44545,34,23235,67,45,234,23,-123,0};
    QuickSort(data, 21, 0, 20);
    for(int i=0; i<=20; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
