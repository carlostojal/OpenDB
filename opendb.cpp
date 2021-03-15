
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Table.h"
#include "AddTable.h"
#include "ShowTables.h"
#include "InsertData.h"

using namespace std;

int menu();
vector<string> getTableNames();

int main()
{
    vector<Table> tables;

    // get table names from "tables.list" file
    vector<string> tableNames = getTableNames();

    for (unsigned int i = 0; i < tableNames.size(); i++)
    {
        Table t = Table(); // create new empty table
        t.load(tableNames.at(i)); // load table by name
        tables.push_back(t); // add table to table vector
    }

    int opt;

    do
    {
        opt = menu();

        switch (opt)
        {
            case 1:
                tables.push_back(AddTable().render());
                break;
            case 2:
                ShowTables(&tables).render();
                break;
        }
    } while (opt != 0);
}

int menu()
{
    int opt;

    do
    {
        cout << "\n** OpenDB **" << endl;
        cout << "\n1. Add Table" << endl;
        cout << "2. Show Tables" << endl;
        cout << "0. Exit" << endl;
        cout << "\nOption: ";

        cin >> opt;

    } while (opt < 0 || opt > 2);

    return opt;
}

vector<string> getTableNames()
{

    vector<string> tableNames;

    string temp;

    ifstream f("data/tables.list");


    while (f >> temp)
        tableNames.push_back(temp);

    f.close();

    return tableNames;
}