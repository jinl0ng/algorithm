#include <assert.h>
#include "List.h"


void DeleteNode(ListNode** pHead, ListNode*pToBeDeleted) {
  assert(pHead!=nullptr&&pToBeDeleted!=nullptr);

  if (pToBeDeleted->m_pNext!=nullptr) {
    ListNode* pTmp = pToBeDeleted->m_pNext;
    pToBeDeleted->m_nKey = pTmp->m_nKey;
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


int main() {
  ListNode* pTmp = nullptr;
  ListNode** pHead = &pTmp;
  AddToTail(pHead, 1);
  AddToTail(pHead, 4);
  AddToTail(pHead, 3);
  AddToTail(pHead, 4);
  AddToTail(pHead, 1);
  PrintList(pHead);
  DeleteNode(pHead, (*pHead)->m_pNext);
  std::cout << "test" << std::endl;
  PrintList(pHead);
  return 0;
}
