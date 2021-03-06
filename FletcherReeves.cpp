#include "FletcherReeves.h"
#include "Fibonacce.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

FletcherReeves::FletcherReeves(const Vec & x0_, double gradEps_, Function & f_) : f(f_)
{
  x0 = x0_;
  gradEps = gradEps_;
}

Vec FletcherReeves::Solve()
{
  Vec vXk(x0);
  Vec vGrad = f.getGrad(vXk);
  Vec vSk = -1.0 * vGrad;
  double alphaK;
  double betaK = 0;
  Vec lastGrad(DIM);

  bool firstStep = true;

  while (vGrad.Norm() > gradEps && iterCnt < DIM)
  {
#if defined(LOG_GRAD_NORM) ||  defined(LOG_XK_VEC) || defined(LOG_ALPHA) || defined(LOG_ORHTOG) || defined(LOG_BETA) || defined(LOG_SK)
    cout << "----------------------------" << endl;
    cout << "Step no: " << iterCnt + 1 << endl;
#endif // LOG_GRAD_NORM || 

#ifdef LOG_GRAD_NORM
    cout << "Gradient norm: " << vGrad.Norm() << endl;
#endif // LOG_GRAD_NORM

#ifdef LOG_XK_VEC
    vXk.Print("Current Xk:");
#endif // LOG_XK_VEC

    if (!firstStep)
    {
      betaK = vGrad * f.getHess(vXk) * vSk / (vSk * f.getHess(vXk) * vSk);
      vSk = betaK * vSk - vGrad;
    }
    firstStep = false;
#ifdef LOG_BETA
    cout << "Beta: " << betaK << endl;
#endif // LOG_BETA
#ifdef LOG_SK
    vSk.Print("Sk Vector:");
#endif // LOG_SK

    alphaK = -1.0 * vGrad * vSk / (vSk * f.getHess(vXk) * vSk);
#ifdef LOG_ALPHA
    cout << "Alpha: " << alphaK << endl;
#endif // LOG_ALPHA


    vXk = vXk + alphaK * vSk;
    
    lastGrad = vGrad *(1.0 / vGrad.Norm());
    vGrad = f.getGrad(vXk);
#ifdef LOG_ORTHOG
    cout << "Orthogonality: " << lastGrad * vGrad / vGrad.Norm() << endl;
#endif // LOG_ORTHOG
    iterCnt++;
  }

#ifdef LOG_UNCONVERGENCE
  if (vGrad.Norm() > gradEps)
    cout << "Error. Method does not convergence in " << DIM << " steps!" << endl;
#endif // LOG_UNCONVERGENCE


#ifdef LOG_GRAD_NORM
  cout << "Final Gradient norm: " << vGrad.Norm() << endl;
#endif // LOG_GRAD_NORM
  return vXk;
}

int FletcherReeves::GetIterCnt() const
{
  return iterCnt;
}
