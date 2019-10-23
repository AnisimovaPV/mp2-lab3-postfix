#include "postfix.h"
#include "stack.h"


string TPostfix::ToPostfix()
{
	TStack<char> StackOper(LenInf); //стэк операций
	postfix = "";
	for (int i = 0; i < LenInf; i++) //(a*b+c)   ab*c+
	{
		if (infix[i] == '(') StackOper.Push(infix[i]);
		else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/'))
		{
			while ((!StackOper.IsEmpty()) && (Priority(StackOper.GetTop()) > Priority(infix[i])))
			{
				postfix+= StackOper.Pop();
			}
			StackOper.Push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while ((!StackOper.IsEmpty()) && (StackOper.GetTop() != '('))
			{
				postfix+= StackOper.Pop();
			}
			StackOper.Pop();
		}
		else
		{
			postfix+= infix[i];
		}
	}
	while (!StackOper.IsEmpty())
	{
		postfix+= StackOper.Pop();
	}
	return postfix;
}

double TPostfix::Calculate(double *_MasValue)
{
	TStack<double> Val(CountVal());
	double val1, val2;
	int j = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isalpha(postfix[i]))
		{
			Val.Push(_MasValue[j++]);
		}
		else
		{
			val1 = Val.Pop();
			val2 = Val.Pop();

			switch (postfix[i])
			{
			case '+':
				Val.Push(val1 + val2);
				break;
			case '-':
				Val.Push(val2 - val1);
				break;
			case '/':
				Val.Push(val2 / val1);
				break;
			case '*':
				Val.Push(val1 * val2);
				break;
			}
		}
	}
	return Val.GetTop();
}

int TPostfix::Priority(char elem)
{
		if (elem == '(')
			return 0;
		else
			if (elem == ')')
				return 1;
			else
				if (elem == '+' || elem == '-')
					return 2;
				else if (elem == '*' || elem == '/')
					return 3;

	else throw ("Erorr");					   			 
}

int TPostfix::GetLen()
{
	return infix.length();
}

int TPostfix::CountVal()
{
	int count=0;
	for (int  i = 0; i < LenInf; i++)
	{
		if (isalpha(infix[i]))
			count++;
	}
	return count;
}
