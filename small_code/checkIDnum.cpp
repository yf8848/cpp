#include <iostream>
#include <string>
using namespace std;

/*返回true表示身份证号码有效*/  
bool CheckIsSnNumber(const std::string &number)
{
      size_t numberLength = number.length();
      if (numberLength != 18) //身份证18位
      { 
          return false;
      }

      std::string number_ = number;
      //计算身份证最后一份校验码
      int iS = 0;
      int iW[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
      static char szVerCode[] = "10X98765432";
      int i;
      for (i = 0; i < 17; i++)
      {
          iS += (int)(number_[i] - '0') * iW[i];
      }
      int iY = iS % 11;
      char verifyEndCode =  szVerCode[iY];

      char endCode = number[numberLength - 1];

      if (verifyEndCode == endCode)
      {
          return true;
      }

      return false;
};

  int
  main()
  {
      std::string sid="612522199106122531";
      cout<<CheckIsSnNumber(sid)<<endl;
      return 0;
  }

