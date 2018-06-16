/**************************************
 * 剑指offer第八题Java实现
 * 作者：朱金龙
 * 创建日期：2018/6/15
 * 最后修改日期：2018/6/15
 * 编译：javac offer8.java
 * 运行：java offer8 < intArr
 *************************************/

/**************************************
 * API:
 * 输入一个排序但经过旋转的整数数组,输出最小数字,例如：
 * 456123   1
 * 101111   0
 * 799457   4
 *
 * public static int minNum(int [])
 *************************************/

public class offer8{
  public static int minNum(int []arr){
    //二分查找法，但是当p1 == p2 == pMid时会失效
    //例如10111, p1 = p2 = pMid = 1, 无法判断

    if(arr == null)
      throw new IllegalArgumentException();

    int p1 = 0;
    int p2 = arr.length - 1;
    int pMid = 0;
    int min = 0;
    boolean flag = false;
    while(p1 != (p2 - 1)){
      pMid = (p1 + p2) / 2;
      if(arr[pMid] == arr[p1] && arr[pMid] == arr[p2]){
        flag = true;
        break;
      }
      if(arr[pMid] >= arr[p1]){
        p1 = pMid;
        continue;
      }
      if(arr[pMid] <= arr[p2]){
        p2 = pMid;
        continue;
      }
    }

    if(flag){
      min = arr[0];
      for(int i : arr)
        if(i < min)
          min = i;
    }else{
      min = arr[p2];
    }

    return min;
  }

  public static void main(String [] args){
    int size = StdIn.readInt();
    int []data = new int[size];
    for(int i = 0; i < size; i++)
      data[i] = StdIn.readInt();

    StdOut.println(offer8.minNum(data));
  }
}
