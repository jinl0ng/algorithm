#include "iostream"
void repSpace(char* str, int length)
{
    if(str==nullptr || length<0)
        return;
    else 
    {
        int spaceNum = 0;
        int i = 0;
        for(i=0; str[i]!='\0'; ++i)
        {
            if(str[i]==' ')
                ++spaceNum;
        }
        int newLength = i + 2*spaceNum;
        if(newLength>=length)
            return;
        else
        {
            int indexOriginal = i;
            int indexNew = newLength;
            while(indexOriginal<=indexNew && indexOriginal>=0)
            {
                if(str[indexOriginal]==' ')
                {
                    str[indexNew--] = '0';
                    str[indexNew--] = '2';
                    str[indexNew--] = '%';
                }
                else
                {
                    str[indexNew--] = str[indexOriginal];
                }
                --indexOriginal;
            }
        }
    }

}

int main(void)
{
    char str[20] = "Hello World";
    std::cout<<"original string: ";
    for(int i=0; str[i]!='\0'; ++i)
        std::cout<<str[i];
    std::cout<<std::endl;
    repSpace(str, 20);
    std::cout<<"new string: ";
    for(int i=0; str[i]!='\0'; ++i)
        std::cout<<str[i];
    std::cout<<std::endl;
    return 0;
}
