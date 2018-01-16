//c++ 面向对象程序设计第七版p515,12-7
//author leaf

#include <iostream>
#include "sset.h"
using namespace std;

int main()
{
  StringSet stl1,stl2,stl3;
  int num;
  char con='y';
  cout << "Please input a STL.\n";
  stl1.input();
  cout << "Please input an another STL.\n";
  stl2.input();
  cout << "What do you want?\n1.stl1 add a string.\n2.stl1 delete a string.\n3.stl1 delete all strings.\n4.How many strings?\n5.output all strings.\n6.be mixed two STLs.\n7.aggregate two STLs.\n(Please a number what you want.)\n";
  do{
    cin >> num;
    switch(num)
      {
      case 1:
        stl1.add_str();
        stl1.output();
        break;
      case 2:
        stl1.delete_str();
        stl1.output();
        break;
      case 3:
        stl1.delete_all();
        stl1.output();
        break;
      case 4:
        stl1.num_long();
        stl2.num_long();
        break;
      case 5:
        stl1.output();
        stl2.output();
        break;
      case 6:
        stl3=stl1+stl2;
        stl3.output();
        break;
      case 7:
        stl3=stl1*stl2;
        stl3.output();
        break;
      default:
        cout << "That is not true!";
      }
    cout << "Can you continue?(y/n)";
    cin >> con;
  }while(con=='y');
  return 0;
}
