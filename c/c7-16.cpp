//c++ 面向对象程序设计第七版p307,7-16

//author leaf

#include <iostream>


using namespace std;
const int game_number=4;

// void rand_number(int n);

void game_cout(char game_series[][game_number]);
//output
void turn_over(const char game_one[][game_number],char game_two[][game_number]);
//replace
int main()
{
  char game_one[4][4]={'1','8','7','5','8','6','4','7','2','2','3','4','1','3','5','6'};
  char game_two[4][4]={'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'};

  char remember;
  cout<<"game start\n";
  game_cout(game_one);
  cout << "Do you remember?if you remember,(y)\n";
  cin >> remember;
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  game_cout(game_two);
  turn_over(game_one,game_two);
  return 0;
}

void game_cout(char game_series[][game_number])
{
  int i,j;
  cout<<"    1 2 3 4\n";
  for(i=0;i<game_number;i++)
    {
      cout << i+1 <<" |";
      for(j=0;j<game_number;j++)
      {
        cout << " " << game_series[i][j];
      }
    cout<<"\n";
    }
}

void turn_over(const char game_one[][game_number],char game_two[][game_number])
{
  int n_one,m_one,n_two,m_two,k=0;
  do
  {
      cout<<"Please inport coord\n";
      cout<<"first coord is ";
      cin>>n_one>>m_one;
      cout<<"second coord is ";
      cin>>n_two>>m_two;
      cout << endl;
      game_two[n_one-1][m_one-1]=game_one[n_one-1][m_one-1];
      game_two[n_two-1][m_two-1]=game_one[n_two-1][m_two-1];
      game_cout(game_two);
      k++;
      if(k==8)
        break;
  }while(game_one[n_one-1][m_one-1]==game_one[n_two-1][m_two-1]);
  cout << "game over\nYou find "<< k-1 << " pair\n";
}
// void rand_number(int n)
// {
//   int i,j;
//   double rand_series[5][5];
//   for(i=0;i<game_number;i++)
//     for(j=0;j<game_number;j++)
//       rand_series[i][j]=rand();
//   min_number=rand_series[0][0];
//   for(i=0;i<game_number;i++)
//     for(j=0;j<game_number
// }
