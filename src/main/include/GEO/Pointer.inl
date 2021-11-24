#include "main.hpp"
namespace geo
{

	template <typename T>
	Pointer<T>::Pointer()
	{

	}

	template <typename T>
	Pointer<T>::Pointer(T * ptr, T * end)
	{
		if (ptr)
		{
			_ptr = ptr;
			size = !end ? 1 : end - ptr;
		}
	}

	template <typename T>
	Pointer<T>::Pointer(T& val)
	{
		_ptr = &val;
		_shouldDelete = false;
	}

	template <typename T>
	Pointer<T>::~Pointer()
	{
		if (_shouldDelete)
		{
			delete[] _ptr;
			_ptr = nullptr;
		}
	}

	template <typename T>
	T& Pointer<T>::operator[](int index)
	{
		return _ptr[index];
	}

	template <typename T>
	T& Pointer<T>::operator*()
	{
		return *_ptr;
	}

	template <typename T>
	T* Pointer<T>::operator->()
	{
		return _ptr;	
	}

	template <typename T>
	void Pointer<T>::Set(T * ptr, T * end)
	{
		if (_shouldDelete)
		{
			throw Exception("Cannot set values from raw pointer to raw pointer, raw pointer not owned by instance");
		}
		if (ptr){
			size = !end ? 1 : end - ptr;
			delete[] _ptr;
			_ptr = nullptr;
			_ptr = ptr;
		}
	}

	template <typename T>
	unsigned long long Pointer<T>::Size()
	{
		return size;
	}

	template <typename T>
	T* Pointer<T>::Switch(T* ptr)
	{
		T* returnPtr = _ptr;
		_ptr = nullptr;
		_ptr = ptr;
		return returnPtr;
	}

	template <typename T>
	T* Pointer<T>::Switch(T& val)
	{
		T* returnPtr = _ptr;
		_ptr = &val;
		return returnPtr;
	}
}