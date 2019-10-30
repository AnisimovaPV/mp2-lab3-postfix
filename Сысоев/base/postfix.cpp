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
			if (StackOper.IsEmpty()) 
				StackOper.Push(infix[i]) ;
			else if ((!StackOper.IsEmpty()) && (Priority(StackOper.GetTop()) > Priority(infix[i])))
			{
				postfix+= StackOper.Pop();
			
			StackOper.Push(infix[i]);
			}
			else if (Priority(StackOper.GetTop()) == Priority(infix[i]))
			{
				postfix += StackOper.Pop();
				StackOper.Push(infix[i]);
			}
			else if (Priority(StackOper.GetTop()) < Priority(infix[i]))
			{
				StackOper.Push(infix[i]);
			}
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
	int var = GetInfixVar();
	TStack<double> Val(var);
	
	double* ValVAr= new double[var];
	if (CountVal() == GetInfixVar()) 
	{
		for (int i = 0; i < var; i++)
		{
			ValVAr[i] = _MasValue[i];
		}
	}
	else 
	{
		char *tmp = new char[var];
		int j = 0;
		for (int i = 0; i < LenInf; i++)
		{
			if (isalpha(infix[i]))
			{
				tmp[j] = infix[i];
				j++;
			}
		}
		int q = 0;
		for (int i = 0; i < var; i++)
		{
			if ((isalpha(tmp[i])))
			{
				ValVAr[i] = _MasValue[q++];
				for (int j = i + 1; j < var; j++)
				{
					if (tmp[i] == tmp[j])
					{
						ValVAr[j] = ValVAr[i];
						tmp[j] = ' ';
					}
				}
			}			
		}
	}	
		double val1, val2;
		int j = 0;
		for (int i = 0; i < postfix.length(); i++)
		{
			if (isalpha(postfix[i]))
			{
				Val.Push(ValVAr[j++]);
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
	char *str =new char[LenInf]; //массив переменных 
	int count=0;
	for (int  i = 0; i < LenInf; i++)
	{
		if (isalpha(infix[i]))
		{ 
			count++;
		    str[i] = infix[i];
		}		
		else str[i] = ' ';
	} 
	for (int i = 0; i < LenInf ; i++)
	{
		if  (str[i] != ' ')
		{
			for (int j = i + 1; j < LenInf; j++)
			{
				if (str[i] == str[j])
				{
					count--;
					str[j] = ' ';
				}
			}	
		}
	}
	delete[] str;
	return count;	
}
int TPostfix::GetInfixVar()
{
	int count = 0;
	for (int i = 0; i < LenInf; i++)
	{
		if (isalpha(infix[i]))	count++;
	}
	return count;
}