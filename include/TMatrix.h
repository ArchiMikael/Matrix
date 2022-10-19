#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include "TVector.h"

using namespace std;

template<class T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::size;
public:
  TDynamicMatrix(size_t s = 1);

  using TDynamicVector<TDynamicVector<T>>::operator[];
  bool operator==(const TDynamicMatrix& m) const noexcept;
  TDynamicVector<T> operator*(const T& val);
  TDynamicVector<T> operator*(const TDynamicVector<T>& v);
  TDynamicMatrix operator+(const TDynamicMatrix& m);
  TDynamicMatrix operator-(const TDynamicMatrix& m);
  TDynamicMatrix operator*(const TDynamicMatrix& m);

  friend istream& operator>>(istream& istr, TDynamicMatrix& v);
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v);
};

#endif