// TSP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

bool checkUniqueness(int cities[], int size)
{
	//int size = sizeof(cities) / sizeof(cities[0]);
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (cities[i] == cities[j])
				return false;
	return true;
}

bool checkUniqueness(std::list<int> cities, int size)
{
	//int size = sizeof(cities) / sizeof(cities[0]);
	for (int n : cities)
	{
		int numberOfRepetitions = 0;
		for (int m : cities)
			if (n == m)
			{
				numberOfRepetitions++;
				if (numberOfRepetitions == 2)
					return false;
			}
	}
	return true;
}

int aDistance(int distances[], int cities[], int size) {
	int res = distances[cities[size - 1] * size + cities[0]];

	for (int i = 0; i < size - 1; i++)
		res += distances[cities[i] * size + cities[i + 1]];

	return res;
}

int aDistance(int distances[], std::list<int> cities, int size) {
	int res = distances[cities[size - 1] * size + cities[0]];

	for (int i = 0; i < size - 1; i++)
		res += distances[cities[i] * size + cities[i + 1]];

	return res;
}

void tsp_solve_4(int distances[16]) {
	int minDistance = INT_MAX;

	for (int c2 = 1; c2 <= 3; c2++)
		for (int c3 = 1; c3 <= 3; c3++)
			for (int c4 = 1; c4 <= 3; c4++)
			{
				int cities[4] = { 0,c2,c3,c4 };
				if (!checkUniqueness(cities, 4)) continue;
				int actualDistance = aDistance(distances, cities, 4);
				if (actualDistance < minDistance)
					minDistance = actualDistance;
			}
	std::cout << minDistance << std::endl;;

}
void tsp_solve_5(int distances[25]) {

	int minDistance = INT_MAX;

	for (int c2 = 1; c2 <= 4; c2++)
		for (int c3 = 1; c3 <= 4; c3++)
			for (int c4 = 1; c4 <= 4; c4++)
				for (int c5 = 1; c5 <= 4; c5++)
				{
					int cities[5] = { 0,c2,c3,c4,c5 };
					if (!checkUniqueness(cities, 5)) continue;
					int actualDistance = aDistance(distances, cities, 5);
					if (actualDistance < minDistance)
						minDistance = actualDistance;
				}
	std::cout << minDistance << std::endl;
}

void tsp_solve_6(int distances[25]) {

	int minDistance = INT_MAX;

	for (int c2 = 1; c2 <= 6; c2++)
		for (int c3 = 1; c3 <= 6; c3++)
			for (int c4 = 1; c4 <= 6; c4++)
				for (int c5 = 1; c5 <= 6; c5++)
					for (int c6 = 1; c6 <= 6; c6++)
					{
						int cities[6] = { 0,c2,c3,c4,c5,c6 };
						if (!checkUniqueness(cities, 6)) continue;
						int actualDistance = aDistance(distances, cities, 6);
						if (actualDistance < minDistance)
							minDistance = actualDistance;
					}
	std::cout << minDistance << std::endl;
}

int sumCities(std::list<int> cities) {
	int sum = 0;
	for (int n : cities)
		sum += n;
	return sum;
}

void tsp_solve_n(int distances[], int size) {

	int minDistance = INT_MAX;

	std::list<int> cities;
	for (int i = 0; i < size; i++)
		cities.push_back(0);

	while (sumCities(cities) != size * size)
	{
		if (!checkUniqueness(cities, size)) continue;
		int actualDistance = aDistance(distances, cities, 6);
		if (actualDistance < minDistance)
			minDistance = actualDistance;

		Incresecities
	}


	
	std::cout << minDistance << std::endl;
}

int main()
{
	//int distances[4][4] = {
	//    {0,10,8,6},
	//    {10,0,3,7},
	//    {8,3,0,1},
	//    {6,7,1,0}
	//        };
	//int distances[4][4] = {
	//    {0,10,8,6},
	//    {10,0,3,7,},
	//    {8,3,0,1,},
	//    {6,7,1,0,}
	//        };
	int distances4[16] = { 0,10,8,6, 10,0,3,7, 8,3,0,1, 6,7,1,0 };
	int distances5[25] = { 0,10,8,6,1, 10,0,3,7,2, 8,3,0,1,3, 6,7,1,0,4, 1,2,3,4,0 };

	tsp_solve_4(distances4);
	tsp_solve_5(distances5);

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
