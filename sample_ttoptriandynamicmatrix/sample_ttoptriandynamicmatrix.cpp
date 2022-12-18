#include "TTopTrianMatrix.h"
#include <iostream>
#include "..\src\TTopTrianMatrix.cpp"
#include <ctime>

using namespace std;

void main() {
  TDynamicTopTrianMatrix<int> mat1(1000);
  TDynamicTopTrianMatrix<int> mat2(1000);
  unsigned int start_time = clock();
  TDynamicTopTrianMatrix<int> res = mat1 + mat2;
  unsigned int end_time = clock();
  unsigned int op_time = end_time - start_time;
  cout << op_time;
}