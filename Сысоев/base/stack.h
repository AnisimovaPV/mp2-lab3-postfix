#ifndef __STACK_H__
#define __STACK_H__


const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
public:
	TStack(int _size)
	{
		if ((_size < 1) || (_size > MaxStackSize))
			throw "Error";
		
			size = _size;
			top = -1;
			pMem = new T[size];
				
	}
	~TStack()      { delete[] pMem;	}
  void Push(T elem);                             //добавить элемент 
  T Pop();                                       //удаление 
  bool IsEmpty()    {  return top == -1;  }      //проверка на пустоту 
  bool IsFull()     { return top == size - 1;  } // полнота 
  T GetTop()        { return pMem[top]; }        //получить элемент
  int StackLength() {return top+1;}              //количество элементов в стеке
};
template <class T>
void TStack<T>::Push(T elem)
{
	if (IsFull())
		throw "Stack is full";
	top++;
	pMem[top] = elem;
}
template <class T>
T TStack<T>::Pop()
{
	if (IsEmpty())
		throw "Stack is empty";
	return pMem[top--];
}
#endif