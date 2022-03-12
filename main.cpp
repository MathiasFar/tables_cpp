#include <iostream>
#include "table.h"

using std::cout; using std::string; using std::vector; using std::endl;

int main()
{
	Table tb;
	tb.includeId = true;
	tb.setColNames({ "First Name", "Age" });

	tb.addRow({"Erik", "12"});
	tb.addRow({"John", "24"});
	tb.addRow({"Clarice", "54"});

	tb.showTable();


	return 0;
}
