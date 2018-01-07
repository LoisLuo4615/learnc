//c++ 面向对象程序设计第七版p368,9-5

//author leaf

//学校机房的登录情况
#include <iostream>
using namespace std;
typedef int* intptr;
const int m[4]={5,6,4,3};//每个机房电脑数
const int n=4;//几个机房

void export_lab(intptr *a);//输出动态数组

void search(intptr *a);//查找登录用户

int main( )
{
  int mem[3],i,j,k;
  char decide;
  intptr member[3],*a=new intptr[n];
  for(k=0;k<n;k++)//动态数组
    a[k]=new int[m[k]];
  for(i=0;i<n;i++)
    for(j=0;j<m[i];j++)
      a[i][j]=1;
  *member = mem;
  export_lab(a);
  do{
    cout << "Please export member land news" << "\n";
    for (i = 0; i < 3; i++)//输入用户ID 和 位置,例:19193 2 3
      cin >> mem[i];
    a[mem[1]-1][mem[2]-1]=mem[0];
    export_lab(a);
    cout << "Do you continue(y/n)" << "\n";
    cin >> decide;
  }while(decide=='y');
  search(a);
  return 0;
}
void export_lab(intptr *a)
{
  int i,j;
  cout << "Lab Number Computer Station\n";
  for (i = 0; i < 4; i++) {
    cout << i+1 << "         ";
    for (j = 0; j < m[i]; j++) {
      if(a[i][j]==1)
        cout << j+1 << ": empty  ";
      else cout << j+1 << ": " << a[i][j] <<"  ";
    }
    cout << "\n";
  }
}

void search(intptr *a)
{
  int member_id,i,j,c;
  char decide;
  cout << "Do you search ID(y/n)" << "\n";
  cin >> decide;
  do{
    c=0;
    cout << "Please export member ID\n";
    cin >> member_id;
    for(i=0;i<n;i++)
      for(j=0;j<m[i];j++)
        if(a[i][j]==member_id){
          c=1;
          cout << i+1 <<" laboratorys "<< j+1 << "computers"<<endl;
          break;
        }
    if(c==0)
      cout << "None" << "\n";
    cout << "Do you continue(y/n)" << "\n";
    cin >> decide;
  }while(decide=='y');
}
