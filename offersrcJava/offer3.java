/**************************************
 * 剑指offer第三题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/15
 * 最后修改日期：2018/6/15
 * 编译：javac offer3.java
 * 运行：java offer3 [n] < data
 *************************************/

/**************************************
 * API:
 * 输入一个每一行左到右递增，每一列上到下递增的二维数组，以及一个数字
 * 判断数组是否含有该数
 * public static boolean find(int [][] data, int n)
 *************************************/


public class offer3{
  public static boolean find(int [][] data, int n){
    if(data == null)
      throw new IllegalArgumentException();
    if(data.length == 0)
      return false;

    int row = 0;
    int col = data.length - 1;
    while((row <= (data.length - 1)) && col >= 0){
      if(data[row][col] == n)
        return true;
      else if(data[row][col] < n)
        row++;
      else
        col--;
    }
    return false;
  }

  public static void main(String [] args){
    int rowLength = StdIn.readInt();
    int colLength = StdIn.readInt();
    int [][] data = new int[rowLength][colLength];
    for(int i = 0; i < rowLength; i++)
      for(int j = 0; j <colLength; j++)
        data[i][j] = StdIn.readInt();

    int n = Integer.parseInt(args[0]);
    StdOut.println(find(data, n));

  }
}
