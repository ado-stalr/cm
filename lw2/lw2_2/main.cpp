#include <iostream>
#include <optional>
#include <vector>
#include <string>
#include <fstream>

constexpr int MAX_MATRIX_SIZE = 400;

struct Args
{
    std::string inputFileName;
};

typedef std::vector<std::vector<int> > Matrix;

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid argument count\n";
        std::cout << "Usage: lw3_3.exe <matrix fileName>\n";
        return std::nullopt;
    }

    Args args;
    args.inputFileName = argv[1];

    return args;
}

int ReadMatrixFromStream(std::ifstream& input, Matrix& field, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            input >> field[i][j];
        }
    }

    return 0;
}

void PrintMatrix(Matrix& field, int size, std::ostream& output)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            output << field[i][j] << ' ';
        }
        output << std::endl;
    }
    output << std::endl;
}

Matrix TransposedMatrix(Matrix &matrix, int n)
{
	Matrix transposedMatrix(n, std::vector<int>(n, 0));

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			transposedMatrix[col][row] = matrix[row][col];
		}
	}
	return transposedMatrix;
}

void DfsAndSort(Matrix const& matrix, int vertex, std::vector<bool> &visited, std::vector<int> &topSort)
{
	visited[vertex] = true;
	for (int i = 0; i < visited.size(); ++i)
	{
		int weight = matrix[vertex][i];
		if ((weight != 0) && (!visited[i]))
		{
			DfsAndSort(matrix, i, visited, topSort);
		}

	}
	topSort.push_back(vertex);
}

void FindSCC(Matrix const& matrix, int vertex, std::vector<bool> &visited)
{
	visited[vertex] = true;
	for (int i = 0; i < matrix[vertex].size(); ++i)
	{
		int weight = matrix[vertex][i];
		if ((weight != 0) && (!visited[i]))
		{
			FindSCC(matrix, i, visited);
		}
	}
}

int main(int argc, char* argv[])
{
	std::vector<bool> visited;
	std::vector<int> topSortVertex;
	int countVertex = 0;
	int countSCC = 0;

    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    std::ifstream input(args->inputFileName);
    if (!input.is_open())
    {
        std::cout << "Failed to open input file for reading\n";
        return 1;
    }

	input >> countVertex;

	if (countVertex <= 0 || countVertex > MAX_MATRIX_SIZE)
	{
		std::cout << "Invalid matrix size\n";
		return 1;
	}

	Matrix matrix(countVertex, std::vector<int>(countVertex, 0));
	ReadMatrixFromStream(input, matrix, countVertex);
	Matrix trMatrix = TransposedMatrix(matrix, countVertex);

	visited.assign(countVertex, false);
	for (int i = 0; i < countVertex; ++i)
	{
		if (!visited[i])
		{
			DfsAndSort(matrix, i, visited, topSortVertex);
		}
	}

	visited.assign(countVertex, false);

	for (int i = 0; i < countVertex; ++i)
	{
		int vertex = topSortVertex[countVertex - 1 - i];
		if (!visited[vertex])
		{
			FindSCC(trMatrix, vertex, visited);
			countSCC++;
		}
	}
	std::cout << ((countSCC == 1) ? 1 : 0);

	return 0;
}
