#include <assert.h>
#include <string>
#include <iostream>


bool InputError(std::string str) {
  if(str.size() <= 0)
    return true;

  if(str.size()==1 && (str[0]<'0' || str[0]>'9'))
    return true;

  bool isError = false;
  for(size_t i=1; i<str.size(); ++i) {
    if(str[i]<'0' || str[i]>'9') {
      isError = true;
      break;
    }
  }

  return isError;
}


std::string BigNumAdd(std::string str1, std::string str2) {
  if(InputError(str1) || InputError(str2)) {
    return "InputError";
  }

  std::string ans = "";
  if(str1[0]=='-' && str2[0]=='-')
    ans = '-' + BigNumAddCore(std::string(str1, 1),
                              std::string(str2, 1));
  else if()
}


int main() {
  std::cout << BigNumAdd("1234567891999",
                         "45678241345")
            << std::endl;
  std::cout << BigNumAdd("+1234567891999",
                         "45678241345")
            << std::endl;
  std::cout << BigNumAdd("+1234567891999",
                         "+45678241345")
            << std::endl;
  std::cout << BigNumAdd("-1234567891999",
                         "45678241345")
            << std::endl;
  std::cout << BigNumAdd("-1234567891999",
                         "-45678241345")
            << std::endl;
  std::cout << BigNumAdd("-12sd34567891999",
                         "45678241345")
            << std::endl;
  std::cout << BigNumAdd("-1234567891999",
                         "4-5678241345")
            << std::endl;

  return 0;
}
