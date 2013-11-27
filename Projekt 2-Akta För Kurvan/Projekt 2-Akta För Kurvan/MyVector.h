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
		T * Arr;
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
		void Resize();
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
};
template<class T> MyVector<T>::~MyVector()
{
	delete[] Arr;
}
template<class T> MyVector<T>::MyVector(int Size)
{
	increase = 1.5f;
	Alloc(Size);
}
template<class T> MyVector<T>::MyVector()
{
	increase =1.5f;
	maxSize =0;
	size = 0;
	Alloc();
}
template<class T> void MyVector<T>::NewAlloc()
{
	if (maxSize == 0)
	{
		maxSize = 3;
		delete[] Arr;
		Arr = new T[maxSize];
	}
	else
	{
		oldSize = maxSize;
		maxSize *= increase;
		T *tempArr = new T[maxSize];
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
		T *tempArr = new T[maxSize];
		for (int i=0; i < oldSize; i++)
		{
			tempArr[i] = Arr[i];
		}
		delete[] Arr;
		Arr = tempArr;
	}
	else
	{
		delete[] Arr;
		maxSize = Size;
		size = 0;
		Arr = new T[maxSize];
	}
}
template<class T> void MyVector<T>::Alloc(int Size)
{
	maxSize = Size;
	size = 0;
	Arr = new T[maxSize];
}
template<class T> void MyVector<T>::Alloc()
{
	maxSize = 3;
	size = 0;
	Arr = new T[3];
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
		return Arr[pos];
	}
	throw "Out Of bounds!!";
}
template<class T> void MyVector<T>::operator=(MyVector &vec)
{
	if (&vec != &Arr)
	{
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
		delete[] Arr;
		Arr = vec;
	}
	else
	{
		Arr = vec;
	}
}
#endif // !VECTOR
