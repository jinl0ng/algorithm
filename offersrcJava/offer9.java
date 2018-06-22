/**************************************
 * 剑指offer第九题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/22
 * 最后修改日期：2018/6/22
 * 编译：javac offer9.java
 * 运行：java offer9 n
 *************************************/

/**************************************
 * API:
 * 输入一个整数n
 * 输出斐波那契数列第n项的值
 * public static int func (int n)
 *************************************/

public class offer9 {
    public static int func(int n) {
        int ans = 1;
        int fn1 = 1;
        int fn2 = 1;

        for (int i = 3; i <= n; i++) {
            ans = fn1 + fn2;
            fn1 = fn2;
            fn2 = ans;
        }
        return ans;
    }

    public static void main(String [] args) {
        StdOut.println(func(Integer.parseInt(args[0])));
    }
}
