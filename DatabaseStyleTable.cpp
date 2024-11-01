#include "DatabaseStyleTable.h"

//FOR MATRIX
    void databaseStyleTable::createTable(vector<vector<string>> data, int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;

    vector<string> str_1dMatrix;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[0].size(); j++)
        {
            str_1dMatrix.push_back(data[i][j]);
        }
    }

    insertRowData(str_1dMatrix);
}
//FOR MATRIX
void databaseStyleTable::createTable(vector<string> rows)
{
    insertRowData(rows);
}
void databaseStyleTable::createTable(vector<string> header, vector<string> rows)
{
    insertHeaderData_Row(header);
    insertRowData(rows);
}
void databaseStyleTable::createTable(vector<string> header, vector<string> rows, vector<string> column)
{

}

void databaseStyleTable::drawTable()
{
    if (!rowHeaderData.empty())
    {
        printDivider();
        printHeader();
    }
    printDivider();

    int remainderOfRowData = rowData.size() % rows;

    //FIX THE LENGTH OF ROWDATA
    if (remainderOfRowData != 0)
    {
        //LESS THAN (REMAINING NUMBER TO GET 0 REMAINDER) (NAA NAY SULOD TANAN COLUMN)
        for (int i = 0; i < rows - remainderOfRowData; i++)
        {
            rowData.push_back(" ");
        }
    }

    columns = rowData.size() / rows;

    for (int i = 0; i < columns; i++)
    {
        printRows();
        printDivider();
    }
}
void databaseStyleTable::drawTable(int rows)
{
    printDivider();
    printHeader();

    for (int i = 0; i < rows; i++)
    {
        printDivider();
        printRows();
        printDivider();
    }
}

void databaseStyleTable::insertHeaderData_Row(vector<string> header)
{
    rows = header.size();

    for (int i = 0; i < rows; i++)
    {
        //UPDATE THE SIZE OF EVERY DATA (ROW)
        if ((header[i].size() + 2) > spacesInBetween)
        {
            spacesInBetween = (header[i].size() + 2);
        }

        rowHeaderData.push_back(header[i]);
    }
}
//ACCEPTS A 1D VECTOR OF STRING AND BASED ON ROW AND COLUMN IT WILL MAKE THE TABLE
void databaseStyleTable::insertRowData(vector<string> rows)
{
    for (int i = 0; i < rows.size(); i++)
    {
        //UPDATE THE SIZE OF EVERY DATA (ROW)
        if ((rows[i].size() + 2) > spacesInBetween)
        {
            spacesInBetween = (rows[i].size() + 2);
        }

        rowData.push_back(rows[i]);
    }
}
void databaseStyleTable::insertHeaderData_Column(vector<string> column)
{

}

void databaseStyleTable::printDivider()
{
    for (int i = 0; i < rows; i++)
    {
        cout << "+";
        for (int j = 0; j < spacesInBetween; j++)
        {
            cout << "-";
        }
    }
    cout << "+" << endl;
}
void databaseStyleTable::printHeader()
{
    cout << "|";

    for (int i = 0; i < rows; i++)
    {
        string temp = rowHeaderData[i];
        if ((temp.size() + 2) < spacesInBetween)
        {
            temp.insert(0, " ");
            temp.insert(temp.size(), (spacesInBetween - temp.size()), ' ');

            cout << temp;
        }
        else
        {
            temp.insert(0, " ");
            temp.insert(temp.size(), " ");
            cout << temp;

        }
        cout << "|";
    }
    cout << endl;
}
void databaseStyleTable::printRows()
{
    cout << "|";
    for (int i = 0; i < rows; i++, cIDX_RowData++)
    {
        string temp = rowData[cIDX_RowData];

        if ((temp.size() + 2) < spacesInBetween)
        {
            temp.insert(0, " ");
            temp.insert(temp.size(), (spacesInBetween - temp.size()), ' ');

            cout << temp;
        }
        else
        {
            temp.insert(0, " ");
            temp.insert(temp.size(), " ");
            cout << temp;
        }
        cout << "|";
    }
    cout << endl;
}
