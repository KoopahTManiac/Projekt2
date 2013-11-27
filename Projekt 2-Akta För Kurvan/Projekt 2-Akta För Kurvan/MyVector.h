#ifndef VECTOR
#define VECTOR

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

using namespace std;
template<class T> class MyVector
{
	private:
		T ** Arr;
		void NewAlloc();
		void NewAlloc(int);
		void Alloc(int Size);
		void Alloc();
		int size;
		int maxSize;
		int oldSize;
		float increase;
	public:
		MyVector(int Size);
		MyVector();
		MyVector(const MyVector&);
		~MyVector();
		void erase(int);
		void Resize(int size);
		void operator = (MyVector&);
		void Copy(MyVector &vec);
		void push_back(T);
		void pop_back();
		int Size();
		int Capacity();
		T& At(int);
		T& operator[](int);
		T& Front();
		T& Back();
		void ResetVector();
};

template<class T>
void MyVector<T>::Resize(int size)
{
	delete[] Arr;
	Alloc(size);
}

template<class T> void MyVector<T>::ResetVector()
{
	for (int i =0; i < size; i++)
	{
		delete Arr[i];
	}
	delete[] Arr;
	Alloc();
}

template<class T> MyVector<T>::~MyVector()
{
	for (int i =0; i < size; i++)
	{
		delete Arr[i];
	}
	delete[] Arr;
}
template<class T> MyVector<T>::MyVector(int Size)
{
	increase = 2.5f;
	Alloc(Size);
}
template<class T> MyVector<T>::MyVector()
{
	increase =2.5f;
	maxSize =0;
	size = 0;
	Alloc();
}
template<class T> void MyVector<T>::NewAlloc()
{
	if (maxSize == 0)
	{
		for (int i =0; i < size; i++)
		{
			delete Arr[i];
		}
		maxSize = 3;
		delete[] Arr;
		Arr = new T*[maxSize];
	}
	else
	{
		oldSize = maxSize;
		maxSize *= increase;
		T **tempArr = new T*[maxSize];
		for (int i=0; i < oldSize; i++)
		{
			tempArr[i] = Arr[i];
		}
		delete[] Arr;
		Arr = tempArr;
	}
}
template<class T> void MyVector<T>::NewAlloc(int Size)
{
	maxSize = Size;
	if (Size >= maxSize && size >0)
	{
		oldSize = maxSize;
		maxSize = Size;
		T **tempArr = new T*[maxSize];
		for (int i=0; i < oldSize; i++)
		{
			tempArr[i] = Arr[i];
		}
		delete[] Arr;
		Arr = tempArr;
	}
	else
	{
		for (int i =0; i < size; i++)
		{
			delete Arr[i];
		}
		delete[] Arr;
		maxSize = Size;
		size = 0;
		Arr = new T*[maxSize];
	}
}
template<class T> void MyVector<T>::Alloc(int Size)
{
	maxSize = Size;
	size = 0;
	Arr = new T*[maxSize];
}
template<class T> void MyVector<T>::Alloc()
{
	maxSize = 3;
	size = 0;
	Arr = new T*[3];
}
template<class T> int MyVector<T>::Capacity()
{
	return maxSize;
}
template<class T> T& MyVector<T>::operator[](int pos)
{
	if (pos < size && pos >=0)
	{
		return Arr[pos];
	}
	throw "Out Of bounds!!";
}
template<class T> T& MyVector<T>::At(int pos)
{
	if (pos < size && pos >=0)
	{
		return *Arr[pos];
	}
	throw "Out Of bounds!!";
}
template<class T> void MyVector<T>::operator=(MyVector &vec)
{
	if (&vec != &Arr)
	{
		for (int i =0; i < size; i++)
		{
			delete Arr[i];
		}
		delete[] Arr;
		Arr = vec;
	}
	else
	{
		Arr = vec;
	}
}
template<class T> void MyVector<T>::Copy(MyVector &vec)
{
	if (&vec != &Arr)
	{
		for (int i =0; i < size; i++)
		{
			delete Arr[i];
		}
		delete[] Arr;
		Arr = vec;
	}
	else
	{
		Arr = vec;
	}
}

template<class T> void MyVector<T>::erase( int pos )
{
	delete Arr[pos];
	Arr[pos] = nullptr;
	for (int i=pos; i < size; i++)
	{
		if (i >0 && i+1 < size)
		{
			Arr[i] = Arr[i+1];
			Arr[i+1] = nullptr;
		}
	}
	size--;
}

template<class T> T& MyVector<T>::Back()
{
	return Arr[0];
}

template<class T> T& MyVector<T>::Front()
{
	return Arr[size];
}

template<class T> int MyVector<T>::Size()
{
	return size;
}

template<class T> void MyVector<T>::pop_back()
{
	Arr[size] = new T();
	size--;
}

template<class T> void MyVector<T>::push_back( T Obj )
{
	if (size >= maxSize)
	{
		NewAlloc();
		Arr[size] = new T(Obj);
		size++;
	}
	else
	{
		Arr[size] = new T(Obj);
		size++;
	}
}

#endif // !VECTOR
