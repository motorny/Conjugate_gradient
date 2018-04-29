#pragma once
#include "Function.h"
class NonLinFunction : public Function {
public:

  virtual mT getVal(const Vec & v) override
  {
    funcRequestCnt++;
    return 0.5 * v * H * v + b * v + 3 + cos(v[0]);
    //return 0.5 * v * H * v + b * v + 3 + cos(v[0])*cos(v[0]);
  }

  virtual Vec getGrad(const Vec& v) override
  {
    Vec grad = H * v + b;
    grad[0] += (-sin(v[0]));
    //grad[0] += 2.0 * (-sin(v[0])) *cos(v[0]);
    return grad;
  }

  virtual Matrix getHess(const Vec& v) override
  {
    Matrix nH(H);
    nH[0][0] += (-cos(v[0]));
    //nH[0][0] += (-4.0 * cos(2.0 * v[0]));
    return nH;
  }
};

