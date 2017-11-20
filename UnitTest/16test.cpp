#include "../offersrc/offer16.h"


namespace{

class ListNodeTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    listEmpty = &pTmp1;
    listSizeOne = &pTmp2;
    listSizeTwo = &pTmp3;
    listSizeFive = &pTmp4;

    AddToTail(listSizeOne, 1);
    AddToTail(listSizeTwo, 1);
    AddToTail(listSizeTwo, 2);
    AddToTail(listSizeFive, 1);
    AddToTail(listSizeFive, 2);
    AddToTail(listSizeFive, 3);
    AddToTail(listSizeFive, 4);
    AddToTail(listSizeFive, 5);
  }

  ListNode* pTmp1 = nullptr;
  ListNode* pTmp2 = nullptr;
  ListNode* pTmp3 = nullptr;
  ListNode* pTmp4 = nullptr;
  ListNode** listEmpty;
  ListNode** listSizeOne;
  ListNode** listSizeTwo;
  ListNode** listSizeFive;
};

TEST_F(ListNodeTest, ReverseListEmptyInput) {
  EXPECT_EQ(nullptr, ReverseList(*listEmpty));
}

TEST_F(ListNodeTest, ReverseListSizeOneInput) {
  EXPECT_EQ(*listSizeOne, ReverseList(*listSizeOne));
}

TEST_F(ListNodeTest, ReverseListSizeTwoInput) {
  ListNode* pResult = ReverseList(*listSizeTwo);
  EXPECT_NE(pResult, nullptr);
  for (int i=2; i!=0&&pResult!=nullptr; --i) {
    EXPECT_EQ(pResult->m_nKey, i);
    pResult = pResult->m_pNext;
  }
}

TEST_F(ListNodeTest, ReverseListSizeFiveInput) {
  ListNode* pResult = ReverseList(*listSizeFive);
  EXPECT_NE(pResult, nullptr);
  for (int i=5; i!=0&&pResult!=nullptr; --i) {
    EXPECT_EQ(pResult->m_nKey, i);
    pResult = pResult->m_pNext;
  }
}
}//namespace


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
