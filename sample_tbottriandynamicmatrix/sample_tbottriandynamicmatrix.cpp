#include "TBotTrianMatrix.h"
#include <iostream>
#include "..\src\TBotTrianMatrix.cpp"
#include <ctime>

using namespace std;

void main() {
  TDynamicBotTrianMatrix<int> mat1(1000);
  TDynamicBotTrianMatrix<int> mat2(1000);
  unsigned int start_time = clock();
  TDynamicBotTrianMatrix<int> res = mat1 + mat2;
  unsigned int end_time = clock();
  unsigned int op_time = end_time - start_time;
  cout << op_time;
}