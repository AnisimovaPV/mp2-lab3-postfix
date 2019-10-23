#include <iostream>
#include <string>
#include "postfix.h"


using namespace std;

int main()
{
  string expression;
  double res;

  setlocale(LC_ALL, "Russian");
  cout << "Введите арифметическое выражение: ";
  cin >> expression;
  TPostfix postfix (expression);

  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  double *MasNumb;
  int CntVal = postfix.CountVal();
  MasNumb= new double[ CntVal];
  for (int i = 0; i < CntVal; i++)
  {
	  cin >> MasNumb[i];
  }
  res = postfix.Calculate(MasNumb);
  cout << res << endl;

  return 0;
}
