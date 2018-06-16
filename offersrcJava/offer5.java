/**************************************
 * 剑指offer第五题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/16
 * 最后修改日期：2018/6/16
 * 编译：javac offer5.java
 * 运行：java offer5 
 *************************************/

/**************************************
 * API:
 * 输入一个链表，从尾到头打印链表。分别用栈与递归实现(由于javaLinkedList的特别，递归没有实现)
 * public void printListReversingly_Iteratively(LinkedList list)
 * public void printListReversingly_Recursively(LinkedList list)
 *************************************/

import java.util.*;

public class offer5<Item>{
  public void printListReversingly_Iteratively(LinkedList<Item> list){
    Stack<Item> stack = new Stack<Item>();
    for(Item item : list)
      stack.push(item);
    while(!stack.isEmpty())
      System.out.println(stack.pop());
  }


  public static void main(String [] args){
    LinkedList<String> list = new LinkedList<String>();
    offer5<String> test = new offer5<String>();
    list.add("a");
    list.add("b");
    list.add("c");
    list.add("d");
    test.printListReversingly_Iteratively(list);
  }
}
