
#include <iostream>
#include "TableList.h"
#include "AddTable.h"
#include "ShowTables.h";

using namespace std;

int menu();

int main()
{
    TableList tables = TableList();

    int opt;

    do
    {
        opt = menu();

        switch (opt)
        {
            case 1:
                tables.addTable(AddTable().render());
                break;
            case 2:
                ShowTables(tables).render();
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