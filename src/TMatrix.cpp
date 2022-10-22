#include <iostream>
#include <typeinfo>
#include "TMatrix.h"

template<class T>
TDynamicMatrix<T>::TDynamicMatrix()
{
  this->size = NULL;
  this->pMem = nullptr;
}

template<class T>
TDynamicMatrix<T>::TDynamicMatrix(int _size)
{
  if (_size > 0) {
    this->size = _size;
    this->pMem = new TDynamicVector<T>[this->size];
    for (int i = 0; i < this->size; i++) { this->pMem[i] = TDynamicVector<T>(i + 1); }
  }
  else { throw "TDynamicMatrix init error"; }
}

template<class T>
TDynamicMatrix<T>::~TDynamicMatrix()
{
  if (this->pMem != nullptr) { delete[] this->pMem; }
  this->size = NULL;
  this->pMem = nullptr;
}

template<class T>
const int TDynamicMatrix<T>::GetSize()
{
  return this->size;
}

template<class T>
bool TDynamicMatrix<T>::operator==(const TDynamicMatrix& _mat)
{
  if (this->size != _mat.size) { return false; }
  if (this->pMem == nullptr || _mat.pMem == nullptr) { throw "TDynamicMatrix operation== error"; }
  else {
    for (int i = 0; i < size; i++) { if (this->pMem[i] != _mat.pMem[i]) { return false; } }
    return true;
  }
}

template<class T>
bool TDynamicMatrix<T>::operator!=(const TDynamicMatrix& _mat)
{
  if (this->size != _mat.size) { return true; }
  if (this->pMem == nullptr || _mat.pMem == nullptr) { throw "TDynamicMatrix operation== error"; }
  else {
    for (int i = 0; i < size; i++) { if (this->pMem[i] != _mat.pMem[i]) { return true; } }
    return false;
  }
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicMatrix& _mat)
{
  if (this->size != _mat.size || this->size == 0 || this->pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(this->size);
  for (int i = 0; i < this->size; i++) { Result.pMem[i] = this->pMem[i] + _mat.pMem[i]; }
  return Result;
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicMatrix& _mat)
{
  if (this->size != _mat.size || this->size == 0 || this->pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(this->size);
  for (int i = 0; i < this->size; i++) { Result.pMem[i] = this->pMem[i] - _mat.pMem[i]; }
  return Result;
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const TDynamicMatrix& _mat)
{
  if (this->size != _mat.size || this->size == 0 || this->pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(this->size);
  for (int i = 0; i < this->size; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      Result[i][j] = 0;
      for (int k = 0; k < this->size - j; k++)
      {
        Result[i][j] += this->pMem[i][k] * _mat.pMem[k][j];
      }
    }
  }
  return Result;
}

template<class T>
TDynamicVector<T> TDynamicMatrix<T>::operator*(TDynamicVector<T>& _vec)
{
  if (this->size != _vec.GetSize() || this->size == 0 || this->pMem == nullptr) { throw "TDynamicMatrix operator+ error"; }
  TDynamicVector<T> Result = TDynamicVector<T>(this->size);
  for (int i = 0; i < this->size; i++)
  {
    Result[i] = 0;
    for (int j = 0; j < i + 1; j++)
    {
      Result[i] += this->pMem[j][i] * _vec[i];
    }
  }
  return Result;
}

template<class T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const T inp)
{
  if (this->size == 0 || this->pMem == nullptr) { throw "TDynamicMatrix operator* error"; }
  TDynamicMatrix<T> Result = TDynamicMatrix<T>(this->size);
  for (int i = 0; i < this->size; i++) { Result.pMem[i] = this->pMem[i] * inp; }
  return Result;
}

template<class T>
istream& operator>>(istream& istr, TDynamicMatrix<T>& _mat)
{
  for (int i = 0; i < _mat.size; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      istr >> _mat.pMem[i][j];
    }
  }
  return istr;
}

template<class T>
ostream& operator<<(ostream& ostr, const TDynamicMatrix<T>& _mat)
{
  for (int i = 0; i < _mat.size; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      ostr << _mat.pMem[i][j] << ' ';
    }
    ostr << '\n';
  }
  return ostr;
}