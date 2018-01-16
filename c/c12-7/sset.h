//c++ 面向对象程序设计第七版p515,12-7
//author leaf

#include <iostream>
#include <string>
using namespace std;

class StringSet
{
public:
  friend StringSet operator +(const StringSet& stl1,const StringSet& stl2);

  friend StringSet operator *(const StringSet& stl1,const StringSet& stl2);

  StringSet(const StringSet& other);

  StringSet();

  void input();

  void output();

  void add_str();

  void delete_str();

  void delete_all();

  void num_long();

private:
  string str[100];
  int max_len;
};
