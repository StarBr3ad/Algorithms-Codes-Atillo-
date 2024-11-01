#pragma once
#include "Libraries.h"

class databaseStyleTable
{
public:
	void createTable(vector<vector<string>> data, int rows, int columns);//MATRIX
	void createTable(vector<string> rows);
	void createTable(vector<string> header, vector<string> rows);
	void createTable(vector<string> header, vector<string> rows, vector<string> column);

	void drawTable();
	void drawTable(int rows);



private:
	int				rows = 0,				//PA RIGHT
					columns = 0,			//PA ILALOM
					spacesInBetween = 0,
					cIDX_RowData = 0;

	vector<string>	rowHeaderData,
					columnHeaderData,
					rowData;

	void insertHeaderData_Row(vector<string> header);
	void insertRowData(vector<string> rowData);

	void insertHeaderData_Column(vector<string> column);

	void printDivider();
	void printHeader();
	void printRows();
};
