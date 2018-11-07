#include "OptimalRouteGenerator.h"


OptimalRouteGenerator::OptimalRouteGenerator(std::string file, double tp, double tk, double lambd):Tp(tp),Tk(tk),lambda(lambd)
{
	r = new Route(file);
	srand(time(nullptr));

}

OptimalRouteGenerator::~OptimalRouteGenerator()
{
}

int OptimalRouteGenerator::startAlgorithm()
{
	double T = Tp;
	std::vector<int> route1 = r->getRoute();
	std::vector<int> route2 = r->getRoute();

	while (T > Tk)
	{
		int u = std::rand()%8+1;
		int w = std::rand()%8+1;
		move(u, w, route2);

		int delta = r->calculateDist(route2) - r->calculateDist(route1);

		if (delta < 0)
			route1 = route2;
		else
		{
			double p = exp(-delta / T);
			double t = std::rand() % 10000;
			t = t/10000;
			if (t <= p)
			{
				route1 = route2;
			}
		}
		T = lambda * T;
	}
	optRoute = route1;
	return r->calculateDist(route1);
}

int OptimalRouteGenerator::startAlgorithm(int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		double T = Tp;
		std::vector<int> route1 = r->getRoute();
		std::vector<int> route2 = r->getRoute();

		while (T > Tk)
		{
			route2 = route1;
			int u = std::rand() % 8 + 1;
			int w = std::rand() % 8 + 1;
			move(u, w, route2);

			int delta = r->calculateDist(route2) - r->calculateDist(route1);

			if (delta < 0)
				route1 = route2;
			else
			{
				double p = exp(-delta / T);
				double t = std::rand() % 10000;
				t = t / 10000;
				if (t <= p)
				{
					route1 = route2;
				}
			}
			T = lambda * T;
		}

		int temp = r->calculateDist(route1);
		if (temp == 30438) howMany++;
		if (temp < minDistance)
		{
			optRoute = route1;
			minDistance = temp;
		}
	}
	return minDistance;
}

int OptimalRouteGenerator::startAlgorithm(int quantity, double Tpt, double Tkt, double lambdat)
{
	for (int i = 0; i < quantity; i++)
	{
		double T = Tpt;
		std::vector<int> route1 = r->getRoute();
		std::vector<int> route2 = r->getRoute();

		while (T > Tkt)
		{
			int u = std::rand() % 8 + 1;
			int w = std::rand() % 8 + 1;
			move(u, w, route2);

			int delta = r->calculateDist(route2) - r->calculateDist(route1);

			if (delta < 0)
				route1 = route2;
			else
			{
				double p = exp(-delta / T);
				double t = std::rand() % 10000;
				t = t / 10000;
				if (t <= p)
				{
					route1 = route2;
				}
			}
			T = lambdat * T;
		}
		int temp = r->calculateDist(route1);
		if (temp == 30438) howMany++;
		if (temp < minDistance)
		{
			optRoute = route1;
			minDistance = temp;
		}
	}
	return minDistance;
}

void OptimalRouteGenerator::showOptRoute()
{
	r->showRoute(optRoute);
}

void OptimalRouteGenerator::move(int u, int w, std::vector<int> &t)
{
	//route[]
	int s = t[u];
	if (u < w)
	{
		for (int i = u; i < w; i++)
		{
			t[i] = t[i + 1];
		}
	}
	if (u > w)
	{
		for (int i = u; i > w; i--)
		{
			t[i] = t[i - 1];
		}
	}
	t[w] = s;
}
