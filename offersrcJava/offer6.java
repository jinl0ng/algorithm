/**************************************
 * 剑指offer第六题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/16
 * 最后修改日期：2018/6/18
 * 编译：javac offer6.java
 * 运行：java offer
 *************************************/

/**************************************
 * API:
 * 输入前序遍历与种序遍历的两个数组，重建
 * 二叉树。输出该树的根结点
 * 例如：
 *  前序遍历：1, 2, 4, 7, 3, 5, 6, 8
 *  中序遍历：4, 7, 2, 1, 5, 3, 8, 6
 *************************************/

import java.util.*;

class TreeNode{
  TreeNode left;
  TreeNode right;
  int item;

  public TreeNode(int item){
    this.item = item;
    left = null;
    right = null;
  }

  public void print(){
    System.out.println(item);
    if(left != null)
      left.print();
    if(right != null)
      right.print();
  }
}
public class offer6{
  public static TreeNode conStruct(int []preOrder, int []midOrder){
    // 仅做一些基本检查
    if(preOrder == null || midOrder == null)
      throw new IllegalArgumentException("preOrder or midOrder is empty");
    if(preOrder.length != midOrder.length)
      throw new IllegalArgumentException("preOrder size and midOrder size should be equal");

    // 构建根结点
    TreeNode root = new TreeNode(preOrder[0]);
    int indexOfRootInMidOrderArr = 0;
    while(midOrder[indexOfRootInMidOrderArr] != preOrder[0])
      indexOfRootInMidOrderArr++;

    // 构建左子树
    if(indexOfRootInMidOrderArr > 0){
      int [] leftChildPreOrder = Arrays.copyOfRange(preOrder, 1, indexOfRootInMidOrderArr + 1);
      int [] leftChildMidOrder = Arrays.copyOfRange(midOrder, 0, indexOfRootInMidOrderArr);
      root.left = conStruct(leftChildPreOrder, leftChildMidOrder);
    }else
      root.left = null;

    // 构建右子树
    if(indexOfRootInMidOrderArr < midOrder.length - 1){
      int [] rightChildPreOrder = Arrays.copyOfRange(preOrder, indexOfRootInMidOrderArr + 1, preOrder.length);
      int [] rightChildMidOrder = Arrays.copyOfRange(midOrder, indexOfRootInMidOrderArr + 1, midOrder.length);
      root.right = conStruct(rightChildPreOrder, rightChildMidOrder);
    }else 
      root.right = null;

    return root;
  }

  public static void main(String [] args){
    int [] preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
    int [] midOrder = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode root = offer6.conStruct(preOrder, midOrder);
    root.print();
  }
}
