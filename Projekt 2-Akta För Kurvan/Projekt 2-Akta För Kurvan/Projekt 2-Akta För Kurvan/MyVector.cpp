#include "MyVector.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

template<class T>
void MyVector<T>::erase( int pos )
{
	Arr[pos] = new T();
	for (int i=pos; i < size; i++)
	{
		if (i >0 && i+1 < size)
		{
			Arr[i] = Arr[i+1];
			Arr[i+1] = new T();
		}
	}
	size--;
}

template<class T>
T& MyVector<T>::Back()
{
	return Arr[0];
}

template<class T>
T& MyVector<T>::Front()
{
	return Arr[size];
}

template<class T>
int MyVector<T>::Size()
{
	return size;
}

template<class T>
void MyVector<T>::pop_back()
{
	Arr[size] = new T();
	size--;
}

template<class T>
void MyVector<T>::push_back( T Obj )
{
	if (size == maxSize)
	{
		NewAlloc();
		Arr[size] = Obj;
		size++;
	}
	else
	{
		Arr[size] = Obj;
		size++;
	}
}
