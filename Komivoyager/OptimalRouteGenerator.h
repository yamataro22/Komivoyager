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
	int startAlgorithm(int quantity, double Tp, double Tk, double lambda);
	void showOptRoute();
	Route *r;
	int howMany = 0;
private:
	int* route;
	int minDistance = 100000;
	double Tp;
	double Tk;
	double lambda;
	void move(int u, int w, std::vector<int> &T);
	std::vector<int> optRoute;
};

