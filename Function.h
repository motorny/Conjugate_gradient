#pragma once
#include <math.h>
#include "Vec.h"
#include "Matrix.h"
class Function {
protected:
  int funcRequestCnt = 0;
  Matrix H;
  Vec b;
public:

  Function() {
    H = Matrix(DIM, DIM);
    H[0][0] = 18;
    H[0][1] = H[1][0] = 12;
    H[0][2] = H[2][0] = -10;
    H[1][1] = 12;
    H[1][2] = H[2][1] = -2;
    H[2][2] = 12;

    b = Vec(DIM);
    b[0] = 5;
    b[1] = 8;
  }

  int GetFuncRequestCnt() const
  {
    return funcRequestCnt;
  }


  void ResetRequestCnt()
  {
    funcRequestCnt = 0;
  }

  virtual mT getVal(const Vec & v) 
  {
    funcRequestCnt++;
    return 0.5 * v * H * v + b * v + 3;
  }

  virtual Vec getGrad(const Vec& v) 
  {
    return H * v + b;
  }

  virtual Matrix getHess(const Vec& v)
  {
    v;
    return H;
  }
};

