/**************************************
 * 剑指offer第七题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/21
 * 最后修改日期：2018/6/21
 * 编译：javac offer7.java
 * 运行：java offer7.java
 *************************************/

/**************************************
 * API:
 * 使用两个栈实现一个队列
 * public void push(Item item)
 * public Item pop()
 *************************************/
public class offer7<Item> {
    private Stack<Item> stack1;
    private Stack<Item> stack2;
    
    public offer7() {
        stack1 = new Stack<Item>();
        stack2 = new Stack<Item>();
    }

    private class Stack<Item> {
        private Node<Item> head;
        private class Node<Item> {
            Item data;
            Node<Item> next;
        }
        public Stack() {
            head = null;
        }
        public void push(Item item) {
            if (head == null) {
                head = new Node<Item>();
                head.data = item;
                head.next = null;
            } else {
                Node<Item> newNode = new Node<Item>();
                newNode.data = item;
                newNode.next = head;
                head = newNode;
            }
        }
        public Item pop() {
            if (head == null)
                return null;
            Node<Item> popNode = head;
            head = head.next;
            return popNode.data;
        }
        public boolean isEmpty() {return head == null;}
    }
    public void push(Item item){
        if (stack2.isEmpty()) {
            stack1.push(item);
        } else {
            stack2.push(item);
        }
    }
    public Item pop() {
        if (stack1.isEmpty() && stack2.isEmpty())
            return null;

        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    public static void main(String [] args) {
        offer7<Integer> test = new offer7<Integer>();
        int n = 5;
        for (int i = 0; i < n; i++)
            test.push(i);

        for (int i = 0; i < n; i++)
            System.out.println(test.pop());
        assert false;
    }
}
