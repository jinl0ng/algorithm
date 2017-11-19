#include <assert.h>
#include <iostream>


void ReOrder(int arr[], unsigned arrSize, bool (*func)(int)) {
  assert(arr!=nullptr&&arrSize>0);
  if (arrSize==1) return;

  int frontIndex = 0;
  int endIndex = arrSize - 1;
  while (frontIndex<endIndex) {
    while (frontIndex<endIndex&&func(arr[frontIndex]))
      ++frontIndex;
    while (frontIndex<endIndex&&!func(arr[endIndex]))
      --endIndex;

    if (frontIndex<endIndex) {
      int tmp = arr[frontIndex];
      arr[frontIndex] = arr[endIndex];
      arr[endIndex] = tmp;
      ++frontIndex;
      --endIndex;
    } else {
      break;
    }
  }
}


bool isOdd(int num) {
  return (num&0x1)==1;
}


void OddsFrontEvenEnd(int arr[], unsigned arrSize) {
  assert(arr!=nullptr && arrSize>0);
  if (arrSize==1) return;

  int frontIndex = 0;
  int endIndex = arrSize - 1;
  while (frontIndex<endIndex&&endIndex>=0&&frontIndex<arrSize) {
    while ((arr[frontIndex]&0x1)==1)
      ++frontIndex;
    while ((arr[endIndex]&0x1)==0)
      --endIndex;
    if (frontIndex<endIndex) {
      int tmp = arr[frontIndex];
      arr[frontIndex] = arr[endIndex];
      arr[endIndex] = tmp;
      ++frontIndex;
      --endIndex;
    } else {
      break;
    }
  }
}


int main() {
  const int arrSize = 6;
  int testArr[] = {1, 2, 3, 4, 5, 6};
  int anotherTestArr[arrSize] = {2, 4, 5, 3, 1, 5};
  OddsFrontEvenEnd(testArr, 6);
  for (int i=0; i<arrSize; ++i)
    std::cout << testArr[i] << std::endl;

  ReOrder(anotherTestArr, arrSize, isOdd);
  for (int i=0; i<arrSize; ++i)
    std::cout << anotherTestArr[i] << std::endl;

  return 0;
}
