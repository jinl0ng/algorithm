#include <assert.h>
#include <string>
#include <iostream>


void SizeEqual(std::string& str1, std::string& str2) {
  if (str1.size()>str2.size()) {
    str2 = std::string(str1.size()-str2.size(), '0') + str2;
  } else if (str1.size()<str2.size()) {
    str1 = std::string(str2.size()-str1.size(), '0') + str1;
  }
  assert(str1.size()==str2.size());
  return;
}


std::string lstrip(std::string str, char c) {
  if(str.size()<=0) return str;

  if(str[0]==c)
    return std::string(str, 1);
  else
    return str;
}


bool InputError(std::string str) {
  if (str.size()<=0) return true;

  if (str.size()==1&&(str[0]<'0'||str[0]>'9'))
    return true;

  bool isError = false;
  for(size_t i=1; i<str.size(); ++i) {
    if (str[i]<'0'||str[i]>'9') {
      isError = true;
      break;
    }
  }

  return isError;
}


std::string BigNumAddCore(std::string str1, std::string str2) {
  SizeEqual(str1, str2);
  std::string ans(str1.size(), '0');
  int nSum = 0;
  int takeOver = 0;
  for(int i=str1.size()-1; i>=0; --i) {
    nSum = str1[i] - '0' + str2[i] - '0' + takeOver; 
    if (nSum>=10) {
      takeOver = 1;
      nSum -= 10;
    } else {
      takeOver = 0;
    }
    ans[i] = nSum;
  }
  if (takeOver==1) ans.insert(0, 1, '1');
  return ans;
}


std::string BigNumMinusCore(std::string str1, std::string str2) {
  SizeEqual(str1, str2);

}


std::string BigNumAdd(std::string str1, std::string str2) {
  if (InputError(str1)||InputError(str2))
    return "InputError";

  //strip +l
  str1 = lstrip(str1, '+');
  str2 = lstrip(str2, '+');

  std::string ans = "";
  if (str1[0]=='-'&&str2[0]=='-') {
    ans = '-' + BigNumAddCore(std::string(str1, 1),
                              std::string(str2, 1));
  } else if (str1[0]=='-'&&str2[0]!='-') {
    ans = BigNumMinusCore(str2, std::string(str1, 1));
  } else if (str1[0]!='-'&&str2[0]=='-') {
    ans = BigNumMinusCore(str1, std::string(str2, 1));
  } else {
    ans = BigNumAddCore(str1, str2);
  }

  return ans;
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
