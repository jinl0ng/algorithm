#ifndef LISH_H
#define LISH_H
#include "List.h"
#endif


ListNode* MergeSortedListRecursively(ListNode* firstList,
                                     ListNode* secondList,
                                     ListNode* &newListHead) {
  ListNode* curNode = nullptr;
  if (firstList==nullptr&&secondList!=nullptr) {
    curNode = new ListNode(secondList->m_nKey, nullptr);
    secondList = secondList->m_pNext;
  }
  else if (firstList!=nullptr&&secondList==nullptr) {
    curNode = new ListNode(firstList->m_nKey, nullptr);
    firstList = firstList->m_pNext;
  }
  else if (firstList==nullptr&&secondList==nullptr)
    curNode = nullptr;
  else {
    if (firstList->m_nKey<secondList->m_nKey) {
      curNode = new ListNode(firstList->m_nKey, nullptr);
      firstList = firstList->m_pNext;
    } else {
      curNode = new ListNode(secondList->m_nKey, nullptr);
      secondList = secondList->m_pNext;
    }
  }
  newListHead = curNode;
  if (curNode) {
    MergeSortedListRecursively 
                             (firstList,
                              secondList,
                              newListHead->m_pNext);
  }
  return newListHead;
}
