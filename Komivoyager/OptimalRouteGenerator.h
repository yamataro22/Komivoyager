#pragma once
#include "Route.h"
#include <string>
#include <random>
#include <time.h>
#include <functional>
class OptimalRouteGenerator
{
public:
	OptimalRouteGenerator(std::string file, double tp, double tk, double lambd);
	~OptimalRouteGenerator();
	int startAlgorithm();
	int startAlgorithm(int quantity);
	void showOptRoute();
private:
	int* route;
	Route* r;
	double Tp;
	double Tk;
	double lambda;
	void move(int u, int w, std::vector<int> &T);
	std::vector<int> optRoute;
};

