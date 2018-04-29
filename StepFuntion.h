#pragma once
#include <math.h>
#include "Vec.h"
#include "Matrix.h"
#include "Function.h"
class StepFunction {
private:
  int requestCnt = 0;
  Function &f;
  Vec xK;
  Matrix mA;
public:

  StepFunction(Function & f_);
  void SetStartVec(const Vec & v0, const Matrix & m_);


  int GetRequestCnt()
  {
    return requestCnt;
  }

  void ResetRequestCnt()
  {
    requestCnt = 0;
  }

  double getVal(double alpha)
  {
////    return f.getVal(xK  - alfa *(mA * g.getVal(xK)));
    return alpha;
  }
};

