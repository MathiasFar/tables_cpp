#include "table.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::cout; using std::string; using std::vector; using std::endl;

// Public Methods

void Table::addRow(vector<string> row)
{
	if (colNames.size() == row.size())
	{
		table.push_back(row);
	}
	else
	{
		cout << "Fuck you! add row" << endl;
	}
}

void Table::removeRow(int id)
{
	table.erase(table.begin()+id);
}

void Table::setColNames(vector<string> row)
{
	colNames = row;
}

int Table::getWidth(vector<vector<string>> table)
{
	int lenWords = 0;
	int endSpacers = 4;
	int middleSpacer = 3;
	for (int i = 0; i < table[0].size(); ++i) {
		lenWords += table[0][i].length();
	}

	return (lenWords+endSpacers+(middleSpacer*table[0].size()-3));
}

void Table::showTable()
{
	table.insert(table.begin(), colNames);

	if (includeId)
	{
		for (int i = 0; i < table.size(); ++i)
		{
			if (i == 0)
			{
				table[i].push_back("Id");
			}
			else
			{
				string shit = std::to_string(i - 1);
				table[i].push_back(shit);
			}
		}
	}

	alignTable();

	int tableWidth = getWidth(table);
	
	for (int i = 0; i < table.size(); ++i)
	{
		if (i == 0)
		{
			printSeparator();
			for (int j = 0; j < table[i].size(); ++j)
			{
				cout << "|" << " ";
				cout << table[i][j] << " ";
			}
			cout << "|" << endl;
			printSeparator();
		}
		else
		{
			for (int j = 0; j < table[i].size(); ++j)
			{
				cout << "|" << " ";
				cout << table[i][j] << " ";
			}
			cout << "|" << endl;
		}
	}
	printSeparator();
}

// Private methods

vector<string> Table::getCol(int index)
{
	vector<string> col;
	for (int i = 0; i < table.size(); ++i) {
		col.push_back(table[i][index]);
	}
	return col;
}

string Table::bigboyelement(vector<string> arr)
{
	string longestElement = "d";
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i].length() >= longestElement.length())
		{
			longestElement = arr[i];
		}
	}
	return longestElement;
}


vector<string> Table::alignCol(vector<string> col)
{
	string longestElement = bigboyelement(col);

	for (int i = 0; i < col.size(); ++i)
	{
		if (col[i].length() < longestElement.length())
		{
			int retardDif = col[i].length() - longestElement.length();
			int dif = std::abs(retardDif);

			for (int j = 0; j < dif; ++j)
			{
				col[i] += " ";
			}
		}
	}
	return col;
}

void Table::alignTable()
{
	for (int i = 0; i < table[0].size(); ++i)
	{
		vector<string> col = alignCol(getCol(i));
		for (int j = 0; j < table.size(); ++j)
		{
			for (int k = 0; k < table[j].size(); ++k)
			{
				table[j][i] = col[j];
			}
		}
	}
}

void Table::printSeparator()
{
	int tableWidth = getWidth(table);
	string separator = "";
	separator += "+";
	for (int i = 0; i < table[0].size(); ++i)
	{
		int elementLength = table[0][i].size() + 2;
		for (int i = 0; i < elementLength; ++i)
		{
			separator += "-";
		}
		separator += "+";
	}

	cout << separator << endl;
}
