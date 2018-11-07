#include "Route.h"
#include <iostream>
#include "OptimalRouteGenerator.h"

using namespace std;

int main()
{
	OptimalRouteGenerator opt("dane.txt", 1000, 0.1, 0.995);
	opt.r->showDistTab();
	cout << endl << "Droga pocz¹tkowa: " << endl;
	opt.r->showRoute();
	cout << endl << "Caclulatego route: " << opt.r->calculateDist() << endl;

	cout << endl << "Po optymalizacji: " << endl;
	string lines(30,'-');
	lines.append("\n");

	cout << lines;
	cout << "Calculated route: " << opt.startAlgorithm(30) << endl;
	opt.showOptRoute();
	cout << lines << endl;
	cout << "Iloœæ optymalnych rozwiazan: " << opt.howMany << endl;
	system("pause");
	return 0;
}