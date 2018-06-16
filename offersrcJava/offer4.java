/**************************************
 * 剑指offer第四题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/15
 * 最后修改日期：2018/6/15
 * 编译：javac offer4.java
 * 运行：java offer4 arrSize string
 *************************************/

/**************************************
 * API:
 * 输入一个字符串数组，在将此数组的空格替换
 * %20。要求在原数组上操作
 * public static void replace(char []) 
 *************************************/

public class offer4{
  public static void replace(char [] string, int size){
    // 统计空格数量
    int count = 0;
    for(char c : string)
      if(c == ' ')
        count++;

    for(int i = size + count * 2; i > 0;){
      if(string[size-1] == ' '){
        string[--i] = '0';
        string[--i] = '2';
        string[--i] = '%';
        size--;
      }else{
        string[--i] = string[size-1];
        size--;
      }
    }
  }

  public static void main(String [] args){
    char [] string = new char[Integer.parseInt(args[0])];
    char [] inputString = args[1].toCharArray();
    for(int i = 0; i < inputString.length; i++)
      string[i] = inputString[i];
    StdOut.println("inputSring length: " + inputString.length);
    StdOut.println("char array length: " + string.length);
    for(char c : string)
      StdOut.print(c);

    offer4.replace(string, inputString.length);
    StdOut.println();
    for(char c : string)
      StdOut.print(c);
  }
}
