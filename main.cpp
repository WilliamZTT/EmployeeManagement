#include <iostream>
#include "workermanager.h"
using namespace std;
int main()
{
    WorkerManager wm;
    int choice = 0;
    while(1)
    {
        wm.Show_Menu();
        cout << "Please enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                wm.ExitSystem();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                cout << 111111111111111 << endl;
                break;
        }
    }
    return 0;
}
