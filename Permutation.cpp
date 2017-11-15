#include <string>
#include <iostream>
#include <assert.h>


void PermutationCore(std::string curStr,
                     const std::string& remainStr) {

  if(remainStr.size()==1) {
    std::cout << curStr + remainStr << std::endl;
    return;
  }

  std::string tmp = remainStr;
  for(auto c : remainStr) {
    tmp = remainStr;
    tmp.erase(tmp.find(c), 1);
    PermutationCore(curStr+c, tmp);
  }
}


void Permutation(const std::string& str) {
  assert(str.size()>0);
  if (str.size()==1) {
    std::cout << str << std::endl;
    return;
  }

  std::string tmp = str;
  for(auto c : str) {
    tmp = str;
    tmp.erase(tmp.find(c), 1);
    PermutationCore(std::string(1, c), tmp);
  }
}


int main(void)
{
  std::string testStr = "abcd";
  Permutation(testStr);
  return 0;
}
