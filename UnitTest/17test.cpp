#include "../offersrc/offer17.h"
#include <gtest/gtest.h>


class ListTest : public::testing::Test {
 protected:
  virtual void SetUp(){
    for (int i=0; i!=listSize; ++i) {
      AddToTail(&b1, i);
      AddToTail(&c2, i);
    }

    for (int i=0; i!=testArr1Size; ++i)
      AddToTail(&d1, testArr1[i]);

    for (int i=0; i!=testArr2Size; ++i)
      AddToTail(&d2, testArr2[i]);
  }

  ListNode* a1 = nullptr;
  ListNode* a2 = nullptr;
  ListNode* b1 = nullptr;
  ListNode* b2 = nullptr;
  ListNode* c1 = nullptr;
  ListNode* c2 = nullptr;
  ListNode* d1 = nullptr;
  ListNode* d2 = nullptr;
  int listSize = 5;
  static const int testArr1Size = 4;
  static const int testArr2Size = 3;
  static const int testArrSize = testArr1Size+testArr2Size;
  int testArr1[testArr1Size] = {1, 4, 7, 9};
  int testArr2[testArr2Size] = {2, 5, 6};
  int testArr[testArrSize] = {1, 2, 4, 5, 6, 7, 9};
};


TEST_F(ListTest, MergeSortedListRecursivelyEmptyInput) {
  ListNode* testHead = nullptr;
  testHead = MergeSortedListRecursively(a1, a2, testHead);
  EXPECT_EQ(nullptr, testHead);
}


TEST_F(ListTest, MergeSortedListRecursivelySecEmpInput) {
  ListNode* testHead = nullptr;
  testHead = MergeSortedListRecursively(b1, b2, testHead);
  for (int i=0; i!=listSize-1; ++i) {
    EXPECT_EQ(i, testHead->m_nKey);
    testHead = testHead->m_pNext;
  }
}


TEST_F(ListTest, MergeSortedListRecursivelyFirEmpInput) {
  ListNode* testHead = nullptr;
  testHead = MergeSortedListRecursively(c1, c2, testHead);
  for (int i=0; i!=listSize; ++i) {
    EXPECT_EQ(i, testHead->m_nKey);
    testHead = testHead->m_pNext;
  }
}


TEST_F(ListTest, MergeSortedListRecursivelyNormalInput) {
  ListNode* testHead = nullptr;
  testHead = MergeSortedListRecursively(d1, d2, testHead);
  for (int i=0; i!=testArrSize; ++i) {
    EXPECT_EQ(testArr[i], testHead->m_nKey);
    testHead = testHead->m_pNext;
  }
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
