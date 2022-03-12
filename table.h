#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::string; using std::vector; using std::endl;

class Table
{
public:
	string tbName;
	bool includeId;
	vector<string> colNames;

	void addRow(vector<string> row);
	void removeRow(int id);
	void setColNames(vector<string> row);
	int getWidth(vector<vector<string>> table);
	void showTable();


private:
	vector<vector<string>> table;

	vector<string> getCol(int index);
	string bigboyelement(vector<string> arr);
	vector<string> alignCol(vector<string> col);
	void alignTable();
	void printSeparator();
};