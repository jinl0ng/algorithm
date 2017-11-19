#include <iostream>
#include <assert.h>


struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};


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
      for (ListNode** pCur=pHead; pCur;) {
        ListNode* tmp = *pCur;
        if (tmp->m_nKey==value) {
          *pCur = tmp->m_pNext;
          delete tmp;
        } else {
          pCur =  &tmp->m_pNext;
        }
      }
    }
}


void PrintList(ListNode** &pHead) {
  if (*pHead==nullptr) return;

  for (ListNode* pCur=*pHead; pCur!=nullptr; pCur=pCur->m_pNext) {
    std::cout << pCur->m_nKey << std::endl;
  }
}
