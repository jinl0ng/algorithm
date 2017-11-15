#include <assert.h>


struct ListNode {
  int m_nValue;
  ListNode* m_pNext;
};


void DeleteNode(ListNode** pHead, ListNode*pToBeDeleted) {
  assert(pHead!=nullptr&&pToBeDeleted!=nullptr);

  if (pToBeDeleted->m_pNext!=nullptr) {
    ListNode* pTmp = pToBeDeleted->m_pNext;
    pToBeDeleted->m_nValue = pTmp->m_nValue;
    pToBeDeleted->m_pNext = pTmp->m_pNext;
    delete pTmp;
  } else if(*pHead==pToBeDeleted) {
    delete pToBeDeleted;
    pToBeDeleted = nullptr;
    *pHead = nullptr;
  } else {
    ListNode* pTmp = *pHead;
    while(pTmp->m_pNext!=pToBeDeleted)
      pTmp = pTmp->m_pNext;
    pTmp->m_pNext = nullptr;
    delete pToBeDeleted;
    pToBeDeleted = nullptr;
  }
}
