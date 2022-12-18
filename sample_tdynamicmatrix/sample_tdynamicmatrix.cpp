#include "TMatrix.h"
#include <iostream>
#include "..\src\TMatrix.cpp"
#include <ctime>

using namespace std;

void main() {
  TDynamicMatrix<int> mat1(10000);
  TDynamicMatrix<int> mat2(10000);
  unsigned int start_time = clock();
  TDynamicMatrix<int> res = mat1 + mat2;
  unsigned int end_time = clock();
  unsigned int op_time = end_time - start_time;
  cout << op_time;
}