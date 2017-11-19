#include "iostream"


struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* ConstructCore
    (
     int* startPreorder, int*endPreorder, 
     int* startInorder, int* endInorder    
    );
int main()
{
    std::cout<<"ok"<<std::endl;
    return 0;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder==nullptr || inorder==nullptr || length<0)
        return nullptr;
    else
    {
        return ConstructCore
                   (preorder, preorder+length-1, 
                    inorder, inorder+length-1
                   );
    }
}



BinaryTreeNode* ConstructCore
    (
     int* startPreorder, int*endPreorder, 
     int* startInorder, int* endInorder    
    )
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;
    if(startPreorder==endPreorder)
    {
        if(startInorder==endInorder && *startPreorder==*startInorder)
            return root;
        else 
            std::cout<<"error!"<<std::endl;
    }

    int* inorderRoot = startInorder;
    while(*inorderRoot!=rootValue && inorderRoot!=endInorder)
        ++inorderRoot;
    if(*inorderRoot!=rootValue)
        std::cout<<"error!"<<std::endl;
    else
    {
        int leftLength = inorderRoot - startInorder;
        if(leftLength>0)
        {
            root->m_pLeft = ConstructCore
                            (
                             startPreorder+1, startPreorder+leftLength,
                             startInorder, inorderRoot-1
                            );
        }
        if(endPreorder-startPreorder-leftLength>0)
        {
            root->m_pRight = ConstructCore
                            (
                             startPreorder+leftLength+1,
                             endPreorder,
                             inorderRoot+1,
                             endInorder
                            );
        }
        return root;
    }
}


