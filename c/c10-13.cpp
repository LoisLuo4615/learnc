//c++ 面向对象程序设计第七版p426,13
//author leaf_zsy

//enter 1010010100010101100001001
//output 99504

//enter 99504
//output 1010010100010101100001001
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#define char_int(x) (x-'0')
using namespace std;

class posthet
{
public:
  void input();
  void set_longcode();
  void set_zip();
  int get();

private:
  void check_code();
  char code_char[30];
};
int main()
{
  posthet code1;
  code1.input();
  if(code1.get())
      code1.set_longcode();
  else code1.set_zip();
  return 0;
}

void posthet::input()
{
  cout << "Enter the postnet code:\n";
  cin.getline(code_char,30);
  check_code();
}

void posthet::check_code()
{
  int code[30],i=0;
  while(code_char[i]!='\0')
    {
      code[i]=char_int(code_char[i]);
      i++;
    }

  if(code_char[27]=='\0' && code_char[5]!='\0')
    {
      for(int i=1;i<=21;i=i+5)
        if((code[i]+code[i+1]+code[i+2]+code[i+3]+code[i+4])!=2)
          {
            cout << "The code is invalid!\n";
            exit(1);
          }
    }
  else if(code_char[5]!='\0'|| code_char[1]=='\0' || code_char[2]=='\0' ||code_char[3]=='\0' || code_char[4]=='\0' )
    {
      cout  <<"The code is invalid!\n";
      exit(1);
    }
}

void posthet::set_longcode()
{
  int code[30];
  int zip=0,n=4,i=0;
  while(code_char[i]!='\0')
    {
      code[i]=char_int(code_char[i]);
      i++;
    }
  for(int i=1;i<=21;i=i+5)
    {
      if((7*code[i]+4*code[i+1]+2*code[i+2]+1*code[i+3]+0*code[i+4])!=11)
        zip=(7*code[i]+4*code[i+1]+2*code[i+2]+1*code[i+3]+0*code[i+4])*pow10(n)+zip;
      n--;
    }
  cout << zip << endl;
}

void posthet::set_zip()
{
  string str0="11000",str1="00011",str2="00101",str3="00110" ,str4="01001";
  string str="1",str5="01010",str6="01100",str7="10001",str8="10010",str9="10100";
  for(int i=0;i<5;i++)
    {
      switch (code_char[i])
        {
        case '0':
          str += str0;
          break;
        case '1':
          str += str1;
          break;
        case '2':
          str += str2;
          break;
        case '3':
          str += str3;
          break;
        case '4':
          str += str4;
          break;
        case '5':
          str += str5;
          break;
        case '6':
          str += str6;
          break;
        case '7':
          str += str7;
          break;
        case '8':
          str += str8;
          break;
        case '9':
          str += str9;
          break;
        default:
          cout << "That is not true!";
        }
    }
  str+='1';
  cout << str << endl;
}

int posthet::get()
{
  return code_char[27]=='\0' && code_char[5]!='\0';
}
