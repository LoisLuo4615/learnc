//c++ 面向对象程序设计第七版p515,12-7
//author leaf

#include <iostream>
#include <string>
#include <algorithm>
#include "sset.h"
using namespace std;

StringSet operator +(const StringSet& stl1,const StringSet& stl2)
{
  StringSet stl3;
  int k=stl1.max_len;
  for(int j=0;j<stl1.max_len;j++)
    stl3.str[j]=stl1.str[j];
  for(int i=0;i<stl2.max_len;i++)
    {
      if(count(stl1.str,stl1.str+stl1.max_len,stl2.str[i])==0)
        {
          stl3.str[k]=stl2.str[i];
          k++;
        }
    }
  stl3.max_len=k;
  return stl3;
}

StringSet operator *(const StringSet& stl1,const StringSet& stl2)
{
  StringSet stl3;
  int k=0;
  for(int i=0;i<stl2.max_len;i++)
      if(count(stl1.str,stl1.str+stl1.max_len,stl2.str[i])>0)
        {
          stl3.str[k]=stl2.str[i];
          k++;
        }
  stl3.max_len=k;
  return stl3;
}

StringSet::StringSet(const StringSet& other)
{
  for(int i=0;i<other.max_len;i++)
    str[i]=other.str[i];
  max_len=other.max_len;
}

StringSet::StringSet()
{
  max_len=30;
  str[0]='\0';
}

void StringSet::input()
{
  cout << "Please input a STL's length.\n";
  cin >> max_len;
  cout <<"Please input a STL.\n";
  getline(cin,str[0]);
  for(int i=0;i<max_len;i++)
    getline(cin,str[i]);
}

void StringSet::output()
{
  if(max_len==0)
    cout << "{ }\n";
  else{
    cout << "{ ";
    for(int i=0;i<max_len-1;i++)
      cout << str[i] <<" , ";
    cout << str[max_len-1] <<" }\n";
  }
}

void StringSet::add_str()
{
  string str1;
  cout << "Please input a string.\n";
  cin>>str1;
  if(count(str,str+max_len,str1)==0)
    {
      str[max_len]=str1;
      max_len++;
    }
  else cout << "The STL belonged to the string.\n";
}

void StringSet::delete_str()
{
  string str1;
  int result=max_len;
  cout << "Please input a string.\n";
  cin>>str1;
  //result=find(str,str+max_len,str1);
  for(int j=0;j<max_len;j++)
  if(str[j]==str1)
    {
      for(int i=j;i<max_len-1;i++)
          str[i]=str[i+1];
      max_len--;
      str[max_len]='\0';
    }
  if(result==max_len)
    cout << "The STL did not belong to the string.\n";
}

void StringSet::delete_all()
{
  str[0]='\0';
  max_len=0;
}

void StringSet::num_long()
{
  cout << max_len << endl;
}
