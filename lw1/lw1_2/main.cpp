#include <iostream>
#include <vector>
#include <boost/timer.hpp>

void PrintArr(std::vector<int>& inputArr)
{
	for (int i = 0; i < inputArr.size(); ++i)
		std::cout << inputArr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	std::cout << "Please, enter the number of elements: ";
	int amountOfEl;
	std::cin >> amountOfEl;
	std::cout << "\n";

	boost::timer t;
	t.restart();

	int amountOfElWithBorders = amountOfEl + 2;

	std::vector<int> currentPermutation(amountOfElWithBorders);
	std::vector<int> reversePermutation(amountOfElWithBorders);
	std::vector<int> direction(amountOfElWithBorders);

	for (int i = 1; i <= amountOfEl; ++i)
	{
		currentPermutation[i] = i;
		reversePermutation[i] = i;
		direction[i] = -1;
	}

	direction[0] = 0;
	currentPermutation[0] = amountOfEl + 1;
	currentPermutation.back() = amountOfEl + 1;

	int border = 0;

	while (border != 1)
	{
		border = amountOfEl;

		while (currentPermutation[reversePermutation[border] + direction[border]] >
				border && border > 1)
		{
			direction[border] = -direction[border];
			border = border - 1;
		}

		std::swap(currentPermutation[reversePermutation[border]],
			currentPermutation[reversePermutation[border] + direction[border]]);
		std::swap(reversePermutation[currentPermutation[reversePermutation[border]]],
			reversePermutation[border]);
	}

	double duration = t.elapsed();
	std::cout << duration << std::endl;
}