/**************************************
 * 剑指offer第十题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/23
 * 最后修改日期：2018/6/23
 * 编译：javac offer10.java
 * 运行：java offer10 n
 *************************************/

/**************************************
 * API:
 * 输入一个整数n，输出该整数二进制形式
 * 1的位数。例如：
 * n = 5 = 101b 输出2
 * public static int monutOfOneInBinary(int n)
 *************************************/

public class offer10 {
    public static int monutOfOneInBinary(int n) {
        int count = 0;
        int afterMinusOne = n;
        while (n != 0) {
            afterMinusOne = n - 1;
            n = afterMinusOne & n;
            count++;
        }
        return count;
    }
    public static void main(String [] args) {
        int n = Integer.parseInt(args[0]);
        StdOut.printf("0 to %d: \n", n);
        for (int i = 0; i <= n; i++) {
            System.out.printf("Dec: %4d Bin: %10s\n", i, Integer.toBinaryString(i));
            StdOut.printf("%d\n", offer10.monutOfOneInBinary(i));
        }
    }
}
