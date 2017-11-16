#include <assert.h>
#include <iostream>


void OddsFrontEvenEnd(int arr[], int arrSize) {
  assert(arr!=nullptr && arrSize>0);
  if (arrSize==1) return;

  int frontIndex = 0;
  int endIndex = arrSize - 1;
  while (frontIndex<endIndex&&endIndex>=0&&frontIndex<arrSize) {
    while (arr[frontIndex]%2==1)
      ++frontIndex;
    while (arr[endIndex]%2==0)
      --endIndex;
    if (frontIndex<endIndex) {
      int tmp = arr[frontIndex];
      arr[frontIndex] = arr[endIndex];
      arr[endIndex] = tmp;
      ++frontIndex;
      ++endIndex;
    } else {
      break;
    }
  }
}


int main() {
  const int arrSize = 6;
  int testArr[] = {1, 2, 3, 4, 5, 6};
  OddsFrontEvenEnd(testArr, 6);
  for (int i=0; i<arrSize; ++i)
    std::cout << testArr[i] << std::endl;
  return 0;
}
