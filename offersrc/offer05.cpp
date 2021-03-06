#include <iostream>
#include <stack>

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);

void printListReversingly_Iteratively(ListNode* pHead);
void printListReversingly_Recursively(ListNode* pHead);


int main(void)
{
    ListNode* pTmp= nullptr;
    ListNode** pHead = &pTmp;
    std::cout<<"pHead init"<<std::endl;
    for(int i=0; i<=5; ++i)
    {
        AddToTail(pHead, i);
        AddToTail(pHead, i+1);
    } 
    std::cout<<"headnum: "<<(*pHead)->m_nKey<<std::endl;
    printListReversingly_Iteratively(*pHead);
    std::cout<<"and"<<std::endl;
    std::cout<<"headnum: "<<(*pHead)->m_nKey<<std::endl;
    printListReversingly_Recursively(*pHead);

    return 0;
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pAdd = new ListNode();
    pAdd->m_nKey = value;
    pAdd->m_pNext = nullptr;

    if(*pHead==nullptr)
    {
        *pHead = pAdd;
    }
    else
    {
        ListNode* pTmp = *pHead;
        while(pTmp->m_pNext!=nullptr)
        {
            pTmp = pTmp->m_pNext;
        }
        pTmp->m_pNext = pAdd;
    }
}


void RemoveNode(ListNode** pHead, int value)
{
    if(*pHead==nullptr)
        return;
    else
    {
        ListNode* pTmp = *pHead;
        while(pTmp->m_pNext!=nullptr && pTmp->m_pNext->m_nKey!=value)
        {
            pTmp = pTmp->m_pNext;
        }
        if(pTmp->m_pNext==nullptr && pTmp->m_pNext->m_nKey==value)
        {
            *pHead = nullptr;
            delete pTmp;
        }
        else if(pTmp->m_pNext==nullptr && pTmp->m_pNext->m_nKey!=value)
            return;
        else
        {
            ListNode* pDel = pTmp->m_pNext;
            pTmp->m_pNext = pDel->m_pNext;
            delete pDel;
        }
    }
}


void printListReversingly_Iteratively(ListNode* pHead)
{
    if(pHead == nullptr)
        return;
    else
    {
        std::stack<ListNode* > nodeStack;
        for(ListNode* pTmp=pHead; pTmp!=nullptr; pTmp=pTmp->m_pNext)
            nodeStack.push(pTmp);
        ListNode* pTmp = nullptr;
        while(!nodeStack.empty())
        {
            pTmp = nodeStack.top();
            std::cout<<pTmp->m_nKey<<' ';
            nodeStack.pop();
        }
    }
}



void printListReversingly_Recursively(ListNode* pHead)
{
    if(pHead == nullptr);
    else
    {
        if(pHead->m_pNext!=nullptr)
            printListReversingly_Recursively(pHead->m_pNext);
        std::cout<<pHead->m_nKey<<' ';
    }
}
