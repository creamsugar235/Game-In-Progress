#include "main.hpp"

namespace geo
{

	template <typename T>
	List<T>::List()
	{
		_arr = new T[0];
	}
	
	template <typename T>
	List<T>::List(Pointer<T> ptr)
	{
		_length = ptr.Size();
		_arr = new T[_length];
		for (num i = 0; i < this->_length; i++)
			_arr[i] = ptr[i];
	}

	template <typename T>
	List<T>::List(num length)
	{
		_length = length;
		_arr = new T[_length];
	}

	template <typename T>
	List<T>::~List()
	{
		delete[] _arr;
	}

	template <typename T>
	unsigned long long List<T>::length() const
	{
		return this->_length;
	}

	template <typename T>
	void List<T>::Add(const T& val)
	{
		T* newPtr = new T[_length + 1];
		for(num i = 0ULL; i < this->_length; i++)
		{
			newPtr[i] = this->_arr[i];
		}
		newPtr[_length] = val;
		delete[] this->_arr;
		_arr = nullptr;
		_arr = newPtr;
		_length++;
	}

	template <typename T>
	T* List<T>::begin()
	{
		return &this->_arr[0];
	}

	template <typename T>
	bool List<T>::Contains(const T& val)
	{
		for (num i = 0; i < this->_length; i++)
		{
			if (this->_arr[i] == val)
			{
				return true;
			}
		}
		return false;
	}

	template <typename T>
	T* List<T>::end()
	{
		return &_arr[_length - 1ULL];
	}

	template <typename T>
	unsigned long long List<T>::Index(const T& val) const
	{
		num index = 0ULL;
		for (num i = 0ULL; i < this->_length; i++)
		{
			if (_arr[index] == val)
			{
				return index;
			}
			index++;
		}
		throw Exception("Value not found");
	}

	template <typename T>
	void List<T>::Insert(const T& val, num index)
	{
		if (index >= this->_length)
		{
			throw Exception("Index out of range");
		}
		T * newarr = new T[_length + 1];
		for (num i = 0ULL; i < index; i++)
		{
			newarr[i] = this->_arr[i];
		}
		newarr[index] = val;
		for (num i = index + 1; i < this->_length; i++)
		{
			newarr[i] = this->_arr[i - 1];
		}
		delete[] this->_arr;
		this->_arr = nullptr;
		_arr = &newarr[0];
		_length++;
	}

	template <typename T>
	T& List<T>::Get(num index) const
	{
		if (index >= this->_length)
		{
			throw Exception("Index out of range");
		}
		return this->_arr[index];
	}

	template <typename T>
	List<T> List<T>::GetRange(num index, num count) const
	{
		if (index >= this->_length)
		{
			throw Exception("Index out of range");
		}
		T * array = new T[count];
		for (num i = index; i < index + count; i++)
		{
			array[i - index] = this->_arr[(i) % this->_length];
		}
		return List<T>(Pointer<T>(array, array + count));
	}

	template <typename T>
	T List<T>::Max(num count) const
	{
		T largest = T();
		count = count == 0 ? this->_length : count;
		for (num i = 1; i < count; ++i)
		{
			if(largest < this->_arr[i])
			{
				largest = this->_arr[i];
			}
		}
		return largest;
	}

	template <typename T>
	T List<T>::Min(num count) const
	{
		T smallest = T();
		count = count == 0 ? this->_length : count;
		for (num i = 1; i < count; ++i)
		{
			if(smallest > this->_arr[i])
			{
				smallest = this->_arr[i];
			}
		}
		return smallest;
	}

	template <typename T>
	void List<T>::Remove(num index)
	{
		T * newarr = new T[_length - 1];
		for (num i = 0ULL; i < index; i++)
		{
			newarr[i] = this->_arr[i];
		}
		for (num i = index; i < this->_length - 1; i++)
		{
			newarr[i] = this->_arr[i + 1];
		}
		delete[] this->_arr;
		this->_arr = nullptr;
		_arr = newarr;
	}

	template <typename T>
	void List<T>::RemoveItem(const T& val)
	{
		bool foundItem = false;
		num itemIndex = 0ULL;
		for (num i = 0ULL; i < this->_length; i++)
		{
			if (_arr[i] == val)
			{
				foundItem = true;
				itemIndex = i;
				break;
			}
		}
		if (!foundItem)
		{
			return;
		}
		T * newarr = new T[_length - 1];
		for (num i = 0ULL; i < itemIndex; i++)
		{
			newarr[i] = this->_arr[i];
		}
		for (num i = itemIndex; i < this->_length; i++)
		{
			newarr[i] = this->_arr[i + 1];
		}
		delete[] this->_arr;
		this->_arr = nullptr;
		_arr = newarr;
		this->_length--;
	}

	template <typename T>
	void List<T>::Set(const T& val, num index)
	{
		if (index >= this->_length)
		{
			throw Exception("Index out of range");
		}
		_arr[index] = val;
	}

	template <typename T>
	void List<T>::swap(T* a, T* b)
	{
		T t = *a;
		*a = *b;
		*b = t;
	}

	template <typename T>
	int List<T>::partition(T arr[], int low, int high)
	{
		T pivot = arr[high];
		int i = low - 1;
		int j = 0;
		for (j = low; j <= high - 1; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i + 1], &arr[j]);
		return i + 1;
	}

	template <typename T>
	void List<T>::quickSort(T arr[], int low, int high)
	{
		if (low < high)
		{
			int pi = partition(arr, low, high);
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	template <typename T>
	void List<T>::Sort()
	{
		std::sort(this->_arr, this->_arr+(_length - 1));
	}
}