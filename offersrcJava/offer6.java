/**************************************
 * 剑指offer第六题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/16
 * 最后修改日期：2018/6/16
 * 编译：javac offer6.java
 * 运行：java offer
 *************************************/

/**************************************
 * API:
 * 输入
 *************************************/
class TreeNode<Item>{
  TreeNode<Item> left;
  TreeNode<Item> right;
  Item item;
}
public class offer6{
  public static void main(String [] args){
    TreeNode<String> tst = new TreeNode<String>();
    tst.left = null;
    tst.right = null;
  }
}
