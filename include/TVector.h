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
  TDynamicVector(unsigned int _size = 1);
  TDynamicVector(T* arr, unsigned int s);
  TDynamicVector(const TDynamicVector& v);
  TDynamicVector(TDynamicVector&& v) noexcept;
  ~TDynamicVector();
  size_t size() const noexcept { return size; };
  void Resize(int nsize);

  T& operator[](size_t ind);
  const T& operator[](size_t ind) const;
  bool operator==(const TDynamicVector& v) const noexcept;
  bool operator!=(const TDynamicVector& v) const noexcept;
  TDynamicVector operator+(T val);
  TDynamicVector operator-(double val);
  TDynamicVector operator*(double val);
  TDynamicVector operator+(const TDynamicVector& v);
  TDynamicVector operator-(const TDynamicVector& v);
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()));
  TDynamicVector& operator=(const TDynamicVector& v);
  TDynamicVector& operator=(TDynamicVector&& v) noexcept;

  friend istream& operator>>(istream& istr, TDynamicVector& v);
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v);
};

#endif