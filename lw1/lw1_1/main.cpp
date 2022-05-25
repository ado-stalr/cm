#include <iostream>
#include <boost/timer.hpp>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<size_t> v = { 7, 1, 12, 5, 9, 20, 15, 8, 6, 3, 4, 2, 17};
	boost::timer t;
	t.restart();

	std::sort(v.begin(), v.end());

	while (std::next_permutation(v.begin(), v.end()));

	double duration = t.elapsed();
	std::cout << duration << std::endl;
}
