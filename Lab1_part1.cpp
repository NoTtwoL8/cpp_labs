/*
Michael Dominguez
Jason Vega
Ebbin Y

Lab 1 -
*/

#include <iostream>
#include <string>

using namespace std;

const int row = 10, col = 10;

void AssignN(char[][col], const int, char, char);
void DrawN(char[][col], const int);

int main() {
	char n = 'N', space = ' ';
	
	char print[row][col];

	AssignN(print, row, n, space);
	DrawN(print, row);

	return 0;
}

void AssignN(char assign[][col], const int row, char n, char space)
{	

	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			if (x == 0 || (x == (col-1)) || (x == y))
			{
				assign[y][x] = n;
			}
			else
			{
				assign[y][x] = space;
			}
		}
	}
}

void DrawN(char assign[][col], const int row)
{
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			cout << assign[y][x];
		}
		cout << "\n";
	}
}