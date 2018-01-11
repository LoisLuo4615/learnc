//c++ 面向对象程序设计第七版p484,11-9
//author leaf

//多项式计算器
#include <iostream>
#include <cstdlib>
using namespace std;

class multinomial
{
public:
  //重载=
  void operator =(const multinomial& mu_three);

  // Default constructor
  multinomial();

  //参数化构造函数
  multinomial(int max_len);

  // Copy constructor
  multinomial(const multinomial& other);

  // Destructor
  ~multinomial();

  void input();

  void output();

  void calculate(char symbol,multinomial& one,multinomial& two);

private:
  double *value;
  int max_length;
};

int main()
{
  multinomial mu_one,mu_two,mu_three;
  char symbol,carry_on='y';
  mu_one.input();
  while(carry_on=='y'){
    cout << "please enter a symbol.\n";
    cin >> symbol;
    mu_two.input();
    mu_one.output();
    cout << " " << symbol << " ";
    mu_two.output();
    cout << " = ";
    mu_three.calculate(symbol,mu_one,mu_two);
    mu_three.output();
    cout << endl;
    cout <<"Do you want to continue?(y/n)\n";
    cin >> carry_on;
    mu_one=mu_three;
  }
}

void multinomial::operator =(const multinomial& mu)
{
  delete [] value;
  max_length=mu.max_length;
  value=new double[max_length];
  for(int i=0;i<max_length;i++)
    value[i]=mu.value[i];
}

multinomial::multinomial()
{
  max_length=20;
  value = new double[max_length];
}

multinomial::multinomial(int max_len)
{
  max_length=max_len;
  value = new double[max_length+1];
}

multinomial::multinomial(const multinomial& other):max_length(other.max_length)
{
  value = new double[max_length+1];
  for(int i=0;i<max_length;i++)
    {
      value[i]=other.value[i];
    }
  value[max_length] = '\0';
}

multinomial::~multinomial()
{
  delete [] value;
}

void multinomial::input()
{
  cout << "What is max index ?";
  cin >>max_length;
  max_length++;
  value=new double[max_length];
  cout << "please enter one coefficient.The index starts at 0.\n";
  for(int j=0;j<max_length;j++)
    cin >> value[j];
}

void multinomial::output()
{
  cout <<"( " << value[0];
  for(int i=1;i<max_length;i++)
    {
      if(value[i]>0){
        cout << " + " << value[i] << "x^" <<i;
      }
      else if(value[i]<0)
        cout << " - " << -value[i] << "x^" <<i;
    }
  cout << " )";
}

void multinomial::calculate(char symbol,multinomial& mu_one,multinomial& mu_two)
{
  int min_length=0;
  if(symbol=='*'){
    max_length=mu_one.max_length+mu_two.max_length-1;
    for(int i=0;i<max_length;i++)
      value[i]=0;
    for(int j=0;j<mu_one.max_length;j++)
      for(int k=0;k<mu_two.max_length;k++)
        {
          value[j+k]=value[j+k]+mu_one.value[j]*mu_two.value[k];
        }
  }
  else if(symbol=='-'){
    max_length=mu_one.max_length>=mu_two.max_length?mu_one.max_length:mu_two.max_length;
    min_length=mu_one.max_length<mu_two.max_length?mu_one.max_length:mu_two.max_length;
    value= new double(max_length);
    for(int j=0;j<max_length;j++){
      value[j]=mu_one.value[j]-mu_two.value[j];
      if(j<min_length)
        value[j]=mu_one.value[j]-mu_two.value[j];
      else if(mu_one.max_length>mu_two.max_length)
        value[j]=mu_one.value[j];
      else value[j]=-mu_two.value[j];
    }
  }
  else if(symbol=='+'){
    max_length=mu_one.max_length>=mu_two.max_length?mu_one.max_length:mu_two.max_length;
    min_length=mu_one.max_length<mu_two.max_length?mu_one.max_length:mu_two.max_length;
    value= new double(max_length);
    for(int j=0;j<max_length;j++){
      if(j<min_length)
        value[j]=mu_one.value[j]+mu_two.value[j];
      else if(mu_one.max_length>mu_two.max_length)
        value[j]=mu_one.value[j];
      else value[j]=mu_two.value[j];
    }
  }
  else{
    cout << "The symbol is incorrect!";
    exit(1);
  }
}
