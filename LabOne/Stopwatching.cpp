#include "StandHeader.h"
#include "HeaderStopwatch.h"
using namespace std;

int fStopWathing() {
    
    Stopwatch SecondsSW;
    int iresume, exit = 1;
   // bool exit = false;
    do
    {
        cout << "Start measuring? (0 - no; 1 - yes)" << endl;
        cin >> iresume;

        if (iresume == 1)
        {
            string x;
            SecondsSW.StartWatch();
            cout << "enter any character to stop";
            cin >> x;
            double recordsSecond = SecondsSW.StopWatching();

            cout << "Result: " << recordsSecond << endl;

            //cout << "Previous entries: " << endl;


        }
        else if (iresume != 0 and iresume != 1) {
            cout << "error" << endl;
            continue;
        }
  
        cout << "exit? (0 - no; 1 - yes)" << endl;
        cin >> exit;
        if (exit == 1 )
            SecondsSW.ClearHistory();

    } while (exit == 0);

    return 0;
}