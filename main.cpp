#include "workermanager.h"
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
                wm.Add_Worker();
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
                break;
        }
    }
    return 0;
}
