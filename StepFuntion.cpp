#include "StepFuntion.h"

StepFunction::StepFunction(Function & f_) : f(f_)
{
}

void StepFunction::SetStartVec(const Vec & v0, const Matrix & m_)
{
  xK = v0;
  mA = m_;
}
