#include "Route.h"
#include <iostream>
#include "OptimalRouteGenerator.h"

using namespace std;

int main()
{
	Route trasa("dane.txt");
	OptimalRouteGenerator opt("dane.txt", 1000, 0.1, 0.995);
	trasa.showDistTab();
	cout << endl << "Droga pocz¹tkowa: " << endl;
	trasa.showRoute();
	cout << endl << "Caclulatego route: " << trasa.calculateDist() << endl;

	cout << endl << "Po optymalizacji: " << endl;
	string lines(30,'-');
	lines.append("\n");

	cout << lines;
	cout << "Calculated route: " << opt.startAlgorithm(100) << endl;
	opt.showOptRoute();
	cout << lines;

	system("pause");
	return 0;
}