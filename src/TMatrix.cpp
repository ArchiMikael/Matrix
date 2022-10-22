#include <iostream>
#include "TMatrix.h"

template<class T>
TDynamicMatrix<T>::TDynamicMatrix()
{
  size = NULL;
  pMem = nullptr;
}

template<class T>
TDynamicMatrix<T>::TDynamicMatrix(int _size)
{
  if (_size > 0) {
    size = _size;
    pMem = new TDynamicVector<T>[size];
    for (unsigned int i = 0; i < size; i++) { pMem[i] = TDynamicVector<T>(i + 1); }
  }
  else { throw "TDynamicMatrix init error"; }
}

template<class T>
TDynamicMatrix<T>::~TDynamicMatrix()
{
  if (pMem != nullptr) { delete[] pMem; }
  size = NULL;
  pMem = nullptr;
}

template<class T>
const unsigned int TDynamicMatrix<T>::GetSize()
{
  return size;
}

template<class T>
bool TDynamicMatrix<T>::operator==(const TDynamicMatrix& _mat)
{
  if (size != _mat.size) { return false; }
  if (pMem == nullptr || _mat.pMem == nullptr) { throw "TDynamicMatrix operation== error"; }
  else {
    for (unsigned int i = 0; i < size; i++) { if (pMem[i] != _mat.pMem[i]) { return false; } }
    return true;
  }
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicMatrix& _mat)
{
  if (size != _mat.size || size == 0 || pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(size);
  for (unsigned int i = 0; i < size; i++) { Result.pMem[i] = pMem[i] + _mat.pMem[i]; }
  return Result;
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicMatrix& _mat)
{
  if (size != _mat.size || size == 0 || pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(size);
  for (unsigned int i = 0; i < size; i++) { Result.pMem[i] = pMem[i] - _mat.pMem[i]; }
  return Result;
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const TDynamicMatrix& _mat)
{
  if (size != _mat.size || size == 0 || pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(size);
  for (unsigned int i = 0; i < size; i++)
  {
    for (unsigned int j = 0; j < i + 1; j++)
    {
      Result[i][j] = 0;
      for (unsigned int k = 0; k < size - j; k++)
      {
        Result[i][j] += pMem[i][k] * _mat.pMem[k][j]
      }
    }
  }
  return Result;
}

template<class T>
TDynamicVector<T> TDynamicMatrix<T>::operator*(const TDynamicVector<T>& _vec)
{
  if (size != _mat.size || size == 0 || pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicVector<T> Result = TDynamicVector<T>(size);
  for (unsigned int i = 0; i < size; i++)
  {
    Result[i] = 0;
    for (unsigned int j = 0; j < i + 1; j++)
    {
      Result[i] += pMem[j][i] * _vec.pMem[i];
    }
  }
  return Result;
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const T inp)
{
  if (size == 0 || pMem == nullptr) { throw "TDynamicMatrix operator* error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(size);
  for (unsigned int i = 0; i < size; i++) { Result.pMem[i] = pMem[i] * inp; }
  return Result;
}

template<class T>
istream& operator>>(istream& istr, TDynamicMatrix<T>& _mat)
{
  for (unsigned int i = 0; i < _mat.size; i++)
  {
    for (unsigned int j = 0; j < i + 1; j++)
    {
      istr >> _mat.pMem[i][j];
    }
  }
  return istr;
}

template<class T>
ostream& operator<<(ostream& ostr, const TDynamicMatrix<T>& _mat)
{
  for (unsigned int i = 0; i < _mat.size; i++)
  {
    for (unsigned int j = 0; j < i + 1; j++)
    {
      ostr << _mat.pMem[i][j] << ' ';
    }
    ostr << '\n';
  }
  return ostr;
}