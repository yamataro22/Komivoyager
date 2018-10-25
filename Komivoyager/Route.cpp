#include "Route.h"



Route::Route(std::string file)
{
	std::ifstream in(file);
	in >> cities;
	createDistTab(cities);
	for (int i = 0; i < cities; i++)
	{
		for (int j = 0; j < cities; j++)
		{
			in >> distTab[i][j];
		}
	}
	route.reserve((size_t)20);
	 
	for (int i = 0; i < cities + 1; i++)
	{
		int temp;
		in >> temp;
		route.push_back(temp);
	}

}


Route::~Route()
{
	for (int i = 0; i < cities; i++)
	{
			delete distTab[i];
		
	}
	delete distTab;
}

void Route::createDistTab(int n)
{
	distTab = new int*[n];
	for (int i = 0; i < n; i++)
	{
		distTab[i] = new int[n];
	}
}

void Route::showDistTab()
{
	if (distTab != nullptr)
	{
		for (int i = 0; i < cities; i++)
		{
			for (int j = 0; j < cities; j++)
			{
				std::cout << distTab[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}

int Route::calculateDist()
{

	int dist = 0;
	for (int i = 0; i < route.size() - 1; i++)
	{
		int L = route[i];
		int K = route[i + 1];
		//std::cout << L << " >> " << K << ": ";
		dist += distTab[L][K];
		//std::cout << distTab[L][K] << std::endl;
	}
	return dist;
}

int Route::calculateDist(const std::vector<int> r)
{
	int dist = 0;
	for (int i = 0; i < r.size() - 1; i++)
	{
		int L = r[i];
		int K = r[i + 1];
		dist += distTab[L][K];
	}
	return dist;
}

void Route::showRoute()
{
	for (int i = 0; i < route.size(); i++)
	{
		std::cout << route[i] << " ";
	}
	std::cout << std::endl;
}

void Route::showRoute(std::vector<int> r)
{
	for (int i = 0; i < r.size(); i++)
	{
		std::cout << r[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int> Route::getRoute()
{
	return route;
}

int ** Route::getDistTab()
{
	return distTab;
}

