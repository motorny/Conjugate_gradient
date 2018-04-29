#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>

#include "NonLinFunction.h"
#include "FletcherReeves.h"
#include "ModFletcherReeves.h"
using namespace std;


/*
 * INFO:
 * Current task dimension: 3
 * MODIFY gloabal defines!!!
 */


int main(void)
{
  Vec trueRes(DIM);
  trueRes[0] = 4.0555555555555555555555555555556;
  trueRes[1] = -4.2777777777777777777777777777778;
  trueRes[2] = 2.6666666666666666666666666666667;

  Vec trueResMod(DIM);
  trueResMod[0] = 3.455378947232729206607080458;
  trueResMod[1] = -3.746192781834703011566271263;
  trueResMod[2] = 2.255116992388157170244855171;


  Function f;
  NonLinFunction nlf;
  Vec x0(DIM);
  double gradEps = 1e-4;
  double innerEps = 1e-4;


  cout << "Fletcher Reeves method:" << endl;
  FletcherReeves fr(x0, gradEps, f);
  Vec res = fr.Solve();
  Vec err = res - trueRes;
  cout << "--------------------------------------------" << endl;
  cout << "x: " << fixed << setprecision(10) << res[0] << endl;
  cout << "y: " << fixed << setprecision(10) << res[1] << endl;
  cout << "z: " << fixed << setprecision(10) << res[2] << endl;
  cout << "Steps count: " << fr.GetIterCnt() << endl;
  cout << "Error: "<< scientific << err.Norm() << fixed << endl;
  cout << endl << endl;

  cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

  cout << "Modified Fletcher Reeves method:" << endl;
  ModFletcherReeves mfr(x0, gradEps, innerEps, nlf);
  res = mfr.Solve();
  err = res - trueResMod;
  cout << "--------------------------------------------" << endl;
  cout << "x: " << fixed << setprecision(10) << res[0] << endl;
  cout << "y: " << fixed << setprecision(10) << res[1] << endl;
  cout << "z: " << fixed << setprecision(10) << res[2] << endl;
  cout << "Steps count: " << mfr.GetIterCnt() << endl;
  cout << "Error: " << scientific << err.Norm() << fixed << endl;
  cout << endl << endl;
  return 0;
}