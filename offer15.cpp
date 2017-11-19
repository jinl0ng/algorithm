#include "List.h"
#include <iostream>
#include <assert.h>


ListNode* LastKNode(ListNode** pHead, unsigned k) {
  assert(pHead!=nullptr&&k>0);

  unsigned count = 1;
  ListNode* ahead = *pHead;
  ListNode* behind = nullptr;
  for (; count<k&&ahead!=nullptr;++count) 
    ahead = ahead->m_pNext;
  if (count==k&&ahead!=nullptr) {
    for (behind=*pHead; ahead->m_pNext!=nullptr; ahead=ahead->m_pNext)
      behind = behind->m_pNext;
    return behind;
  } else {
    return nullptr;
  }
}


int main() {
  ListNode* pTmp = nullptr;
  ListNode** test = &pTmp;
  AddToTail(test, 2);
  AddToTail(test, 3);
  AddToTail(test, 4);
  AddToTail(test, 5);
  AddToTail(test, 6);
  AddToTail(test, 7);
  AddToTail(test, 8);
  PrintList(test);
  const unsigned k = 9;
  ListNode* lastKNode = LastKNode(test, k);
  if (lastKNode) {
    std::cout << lastKNode->m_nKey << std::endl;
  } else {
    std::cout << "InputError" << std::endl;
  }

  return 0;
}
