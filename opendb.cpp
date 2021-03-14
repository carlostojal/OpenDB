
#include <iostream>
#include "TableList.h"
#include "AddTable.h"
#include "ShowTables.h"
#include "InsertData.h"

using namespace std;

int menu();

int main()
{
    TableList* tables = new TableList();

    int opt;

    do
    {
        opt = menu();

        switch (opt)
        {
            case 1:
                tables->addTable(AddTable().render());
                break;
            case 2:
                ShowTables(tables).render();
                break;
            case 3:
                InsertData(tables).render();
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
        cout << "3. Insert Data" << endl;
        cout << "0. Exit" << endl;
        cout << "\nOption: ";

        cin >> opt;

    } while (opt < 0 || opt > 3);

    return opt;
}