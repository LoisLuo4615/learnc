//c++ 面向对象程序设计第七版p346,8-12

//author leaf

//解密码，已知解密方式：每个字母加上数字

#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

void find_key(char old_code[100]);

int main()
{
  char old_code[100];
  cout << "Please import words!\n";
  cin.getline(old_code,100);//输入(:mmZ\dxZmx]Zpgy)
  find_key(old_code);
  return 0;
}

void find_key(char old_code[100])
{
  int j=0,longs;
  longs=strlen(old_code);
  char new_code[longs+1];
  // longs=sizeof(old_code)/sizeof(old_code[0]);
  for(int k=1;k<96;k++)
    {
      for(int i=0;i<longs;i++)
      {
          if(old_code[i]-k<32)
            new_code[i]=126-(31-old_code[i]+k);
          else
            new_code[i]=old_code[i]-k;
          if(new_code[i]==' ')
            j++;
          else if(ispunct(new_code[i]))
            j--;
        }

      if(isupper(new_code[0]) && j>=0 && ispunct(new_code[longs-1]))
        {
          new_code[longs]='\0';
          cout << new_code <<  "   this key is "<< k << endl;
        }
      j=0;
    }
}
