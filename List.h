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


