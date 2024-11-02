#pragma once
#include "Libraries.h"
#include "DatabaseStyleTable.h"


class Matrix_2S
{
public:
	vector<vector<string>> matrix;
	int rows, columns;

	//CONSTRUCTOR
	Matrix_2S() 
	{
		this->rows = 0;
		this->columns = 0;
	}
	Matrix_2S(int rows, int columns)
	{
		this->rows = rows;
		this->columns = columns;
		vector<string> rowEmptyData;

		for (int i = 0; i < rows; i++)
		{
			rowEmptyData.push_back("0");
		}
		for (int i = 0; i < columns; i++)
		{
			matrix.push_back(rowEmptyData);
		}
	}

	//SETTER
	void setMatrixElements(int column, int row, string data)
	{
		matrix[column][row] = data;
	}
	void setMatrixRows(vector<string> rows)
	{
		if (rows.size() <= this->rows)
		{
			this->matrix.push_back(rows);
		}
		else
		{
			cout << "MATRIX ERROR (pushRow): size not the same as the defined row" << endl;
		}
	}
	void setMatrixRows(vector<string> rows, int columns)
	{
		if (rows.size() <= this->rows)
		{
			this->matrix[columns] = rows;
		}
		else
		{
			cout << "MATRIX ERROR (setMatrixRows): size not the same as the defined row" << endl;
		}
	}
	void setMatrixColumns(vector<string> columns, int rowNum)
	{
		if (columns.size() <= this->columns)
		{
			for (int i = 0; i < columns.size(); i++)
			{
				this->matrix[i][rowNum] = columns[i];
			}
		}
		else
		{
			cout << "MATRIX ERROR (setMatrixColumns): size not the same as the defined column" << endl;
		}
	}
	void clearMatrixData()
	{
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				matrix[i][j] = "00";
			}
		}
	}

	//GETTER
	string getMatrixElements(int column, int row)
	{
		return matrix[column][row];
	}
	void getMatrixColumns(vector<string>& vec, int rows)
	{
		for (int i = 0; i < this->columns; i++)
		{
			vec.push_back(getMatrixElements(i, rows));
		}
	}

	//ASSIGN DATA
	void directlyAssignMatrix(Matrix_2S& ref)
	{
		this->matrix = ref.matrix;
		this->rows = ref.rows;
		this->columns = ref.columns;
	}

	//DISPLAY DATA
	void displayMatrix()
	{
		databaseStyleTable table;
		table.createTable(matrix, this->rows, this->columns);
		table.drawTable();
	}
	void displayMatrix_RowHeader()
	{

	}
protected:
};
