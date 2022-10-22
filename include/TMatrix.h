#pragma once

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include "TVector.h"

using namespace std;

template<class T>
class TDynamicMatrix : protected TDynamicVector<TDynamicVector<T>>
{
public:
  TDynamicMatrix();
  TDynamicMatrix(int _size);
  ~TDynamicMatrix();

  const int GetSize();

  using TDynamicVector<TDynamicVector<T>>::operator[];
  bool operator==(const TDynamicMatrix& _mat);
  bool operator!=(const TDynamicMatrix& _mat);
  TDynamicMatrix operator+(const TDynamicMatrix& _mat);
  TDynamicMatrix operator-(const TDynamicMatrix& _mat);
  TDynamicMatrix operator*(const TDynamicMatrix& _mat);
  TDynamicVector<T> operator*(TDynamicVector<T>& _vec);
  TDynamicMatrix operator*(const T inp);

  friend istream& operator>>(istream& istr, TDynamicMatrix& _mat);
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& _mat);
};

#endif