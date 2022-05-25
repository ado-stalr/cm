#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <cstdio>
#include <vector>
#include <string>
#include <boost/timer.hpp>

void Print(const std::vector<int>& v, const unsigned int offset = 0)
{
	copy(v.begin() + offset, v.end(), std::ostream_iterator<int>(std::cout, ""));
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid count  of arguments";
		return 1;
	}

	const size_t k = std::stoi(argv[1]);
	const size_t n = std::stoi(argv[2]);
	if (k > n)
	{
		std::cout << "Invalid args" << std::endl;
		return 1;
	}

	std::vector<int> combination(k + 1);
	char m = 1;
	combination[0] = -1;
	iota(combination.begin() + 1, combination.end(), 1);

	boost::timer time;
	time.restart();
	while (m != 0)
	{
		std::vector<int> permutation = combination;
		do
		{
			//Print(permutation, 1);
		} while (next_permutation(permutation.begin() + 1, permutation.end()));

		m = k;
		while (combination[m] == n - k + m)
		{
			--m;
		}

		++combination[m];
		for (size_t i = m + 1; i <= k; ++i)
		{
			combination[i] = combination[i - 1] + 1;
		}
	}
	printf("Time: %.3f \n", time.elapsed());
}