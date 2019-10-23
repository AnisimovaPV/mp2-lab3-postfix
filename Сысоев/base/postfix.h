#ifndef __POSTFIX_H__
#define __POSTFIX_H__


#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
  int LenInf; //длина инфиксной формы
public:
  TPostfix(string _infix)
  {
	  infix = _infix;
	  postfix = "";
	  LenInf = GetLen();
  }
  string GetInfix()             { return infix; }
  string GetPostfix()           { return postfix; }
  string ToPostfix();                  //перевод в постфикс
  double Calculate(double *_MasNumb);  // Ввод переменных, вычисление по постфиксной форме
  int Priority(char elem);             //приоритет 
  int GetLen();                        //получить длину
  int CountVal();                      // посчитать  кол-во переменных
};
#endif