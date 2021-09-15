#include "C:\Users\inves\Desktop\Derrick\C++ Finance\Level 9\VI.5\FdmDirector.hpp"
#include <iostream>
#include <string>
using namespace std;
#include "C:\Users\inves\Desktop\Derrick\C++ Finance\Level 9\UtilitiesDJD\ExcelDriver\ExcelDriverLite.hpp"

namespace BS // Black Scholes
{
	double sig = 0.2;
	double K = 120;
	double T = 0.25;
	double r = 0.04;
	double D = 0.0; // aka q

	double mySigma(double x, double t)
	{

		double sigmaS = sig * sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu(double x, double t)
	{

		return (r - D) * x;
	}

	double myB(double x, double t)
	{

		return -r;
	}

	double myF(double x, double t)
	{
		return 0.0;
	}

	double myBCL(double t)
	{
		// Put
		return K * exp(-r * t);
	}

	double myBCR(double t)
	{

		// Put
		return 0.0; // P
	}

	double myIC(double x)
	{ // Payoff

		// Put
		return max(K - x, 0.0);
	}

}

int main()
{

	int a;
	int u[3] = {4, 2, 1};
	int *d = &a;
	double c = 0.78;
	a = ++*u * 5 % 3;

	*(u + 1) = c;
	*d = (*u)++ % 2 + *(u + 1);

	printf("%d", *d);

	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	int J = static_cast<int>(5 * BS::K);
	int N = 1000 - 1; // k = O(h^2) !!!!!!!!!

	double Smax = 10 * BS::K; // Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();

	cout << "Finished\n";

	// Have you Excel installed (ExcelImports.cpp)
	printOneExcel(fdir.xarr, fdir.current(), string("Value"));

	return 0;
}
