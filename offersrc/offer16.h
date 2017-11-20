#include <gtest/gtest.h>
#ifndef LISTH
#define LISTH
#include "List.h"
#endif


ListNode* ReverseList(ListNode* pFirstNode) {
  if (pFirstNode==nullptr) return nullptr;
  if (pFirstNode->m_pNext==nullptr) return pFirstNode;

  ListNode* preNode = pFirstNode;
  ListNode* curNode = pFirstNode->m_pNext;
  ListNode* nxtNode = curNode->m_pNext;
  preNode->m_pNext = nullptr;
  while (curNode) {
    curNode->m_pNext = preNode;
    preNode = curNode;
    curNode = nxtNode;
    if (nxtNode!=nullptr) nxtNode = nxtNode->m_pNext;
  }
  return preNode;
}
