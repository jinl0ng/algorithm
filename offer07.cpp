#include "stack"
#include "iostream"


template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template <typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}


template <typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
       while(stack1.size()>0)
       {
           T tmp = stack1.top();
           stack2.push(tmp);
           stack1.pop();
       }
    }

    if(stack2.size()==0)
        std::cout<<"queue is empty!"<<std::endl;
    T head = stack2.top();
    stack2.pop();
    return head;
}
