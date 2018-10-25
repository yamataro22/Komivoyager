#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


class Route
{
public:
	Route(std::string file);
	~Route();

	void showDistTab();
	int calculateDist();
	int calculateDist(const std::vector<int> route);
	void showRoute();
	static void showRoute(std::vector<int> r);
	std::vector<int> getRoute();
	int** getDistTab();

private:


	int cities;
	int** distTab;
	std::vector<int> route;
	void createDistTab(int n);

};

