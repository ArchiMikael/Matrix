#include <iostream>
#include "TMatrix.h"

template<class T>
TDynamicMatrix<T>::TDynamicMatrix(size_t s = 1)
{
  pMem = TDynamicVector<TDynamicVector<T>>(s);
  for (size_t i = 0; i < sz; i++) { pMem[i] = TDynamicVector<T>(sz); }
}

template<class T>
bool TDynamicMatrix<T>::operator==(const TDynamicMatrix& m) const noexcept
{
}

template<class T>
TDynamicVector<T> TDynamicMatrix<T>::operator*(const T& val)
{
}

template<class T>
TDynamicVector<T> TDynamicMatrix<T>::operator*(const TDynamicVector<T>& v)
{
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicMatrix& m)
{
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicMatrix& m)
{
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const TDynamicMatrix& m)
{
}

template<class T>
istream& operator>>(istream& istr, TDynamicMatrix<T>& v)
{
}

template<class T>
ostream& operator<<(ostream& ostr, const TDynamicMatrix<T>& v)
{
}