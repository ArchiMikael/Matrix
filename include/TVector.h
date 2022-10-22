#pragma once

#ifndef __TDynamicVector_H__
#define __TDynamicVector_H__

#include <iostream>

using namespace std;

template<class T>
class TDynamicVector
{
protected:
  unsigned int size;
  T* pMem;
public:
  TDynamicVector();
  TDynamicVector(int _size);
  TDynamicVector(const TDynamicVector& _vec);
  TDynamicVector(TDynamicVector&& _vec);
  ~TDynamicVector();
  unsigned int GetSize();
  void Resize(int nsize);

  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;
  bool operator==(const TDynamicVector& _vec);
  bool operator!=(const TDynamicVector& _vec);
  TDynamicVector operator+(const T inp);
  TDynamicVector operator-(const T inp);
  TDynamicVector operator*(const T inp);
  TDynamicVector operator+(const TDynamicVector& _vec);
  TDynamicVector operator-(const TDynamicVector& _vec);
  T operator*(const TDynamicVector& _vec);
  TDynamicVector& operator=(const TDynamicVector& _vec);

  friend istream& operator>>(istream& istr, TDynamicVector& _vec);
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& _vec);
};

#endif