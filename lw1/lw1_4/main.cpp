#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

void PrintVector(const vector<int>& v, const unsigned int offset = 0)
{
	copy(v.begin() + offset, v.end(), ostream_iterator<int>(cout, ""));
	cout << '\n';
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid count  of arguments";
		return 1;
	}

	const size_t k = stoi(argv[1]);
	const size_t n = stoi(argv[2]);
	if (k > n)
	{
		cout << "Invalid args\n";
		return 1;
	}

	vector<int> combination(k + 1);
	char m = 1;
	combination[0] = -1;
	iota(combination.begin() + 1, combination.end(), 1);

	boost::timer time;
	time.restart();
	while (m != 0)
	{
		//PrintVector(combination, 1);
		m = k;
		while (combination[m] == n - k + m)
			--m;
		++combination[m];
		for (int i = m + 1; i <= k; ++i)
			combination[i] = combination[i - 1] + 1;
	}
	printf("Time: %.3f \n", time.elapsed());
}