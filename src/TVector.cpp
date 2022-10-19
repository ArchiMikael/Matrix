#include <iostream>
#include "TVector.h"

template<class T>
TDynamicVector<T>::TDynamicVector(unsigned int _size = 1) :
{
  size = _size;
  if (size == 0) { throw out_of_range("Vector size should be greater than zero"); }
  pMem = new T[size];
}

template<class T>
TDynamicVector<T>::TDynamicVector(T* arr, unsigned int _size)
{
  size = _size;
  assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
  pMem = new T[sz];
  std::copy(arr, arr + sz, pMem);
}

template<class T>
TDynamicVector<T>::TDynamicVector(const TDynamicVector& v)
{
}

template<class T>
TDynamicVector<T>::TDynamicVector(TDynamicVector&& v) noexcept
{
}

template<class T>
TDynamicVector<T>::~TDynamicVector()
{
}

template<class T>
void TDynamicVector<T>::Resize(int nsize)
{
}

template<class T>
TDynamicVector<T>& TDynamicVector<T>::operator=(const TDynamicVector& v)
{
}

template<class T>
TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector&& v) noexcept
{
}

template<class T>
T& TDynamicVector<T>::operator[](size_t ind)
{
}

template<class T>
const T& TDynamicVector<T>::operator[](size_t ind) const
{
}

template<class T>
bool TDynamicVector<T>::operator==(const TDynamicVector& v) const noexcept
{
}

template<class T>
bool TDynamicVector<T>::operator!=(const TDynamicVector& v) const noexcept
{
}

template<class T>
TDynamicVector<T> TDynamicVector<T>::operator+(T val)
{
}

template<class T>
TDynamicVector<T> TDynamicVector<T>::operator-(double val)
{
}

template<class T>
TDynamicVector<T> TDynamicVector<T>::operator*(double val)
{
}

template<class T>
TDynamicVector<T> TDynamicVector<T>::operator+(const TDynamicVector& v)
{
}

template<class T>
TDynamicVector<T> TDynamicVector<T>::operator-(const TDynamicVector& v)
{
}

template<class T>
T TDynamicVector<T>::operator*(const TDynamicVector& v) noexcept(noexcept(T()))
{
}

template<class T>
istream& operator>>(istream& istr, TDynamicVector<T>& v)
{
  for (size_t i = 0; i < v.sz; i++)
    istr >> v.pMem[i];
  return istr;
}

template<class T>
ostream& operator<<(ostream& ostr, const TDynamicVector<T>& v)
{
  for (size_t i = 0; i < v.sz; i++)
    ostr << v.pMem[i] << ' ';
  return ostr;
}