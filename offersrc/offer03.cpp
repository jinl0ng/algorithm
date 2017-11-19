#include "stdio.h"
#include "iostream"
bool solution(int* matrix, int rows, int columns, int number) 
{
    if(matrix==NULL || (rows<=0&&columns<=0)) 
        return false;
    else 
    { 
        int currentRow = 0; 
        int currentCol = columns - 1;
        while(currentRow<rows &&currentCol>=0) 
        { 
            if(matrix[currentRow*columns + currentCol]== number) 
                return true; 
            else if(matrix[currentRow*columns + currentCol] < number) 
                ++currentRow; 
            else --currentCol; 
        } 
        return false;
    }
}


int main(){
    int* m = nullptr;
    int rows = 0;
    int columns = 0;
    int number = 0;

    std::cout<<"rows:"<<std::endl;
    std::cin>>rows;
    std::cout<<"columns:"<<std::endl;
    std::cin>>columns;
    std::cout<<"ok"<<std::endl;
    m = new int[rows*columns];
    for(int i = 0; i < rows*columns; ++i)
    {
        std::cin >> m[i];
    }
    std::cout<<"number:"<<std::endl;
    std::cin>>number;
    std::cout<<solution(m, rows, columns, number);
    return 0;
}
