#include "HeaderTime.h"
#include "StandHeader.h"


int fTime() {

    Time test_time_one, test_time_two;
    cout << "Enter please the time in 24-x format in hours, minutes, seconds by a space. Example: 23:59:59" << endl;
    cin >> test_time_one;
    cout << endl;
    cout << "You have entered: " << test_time_one << endl;

    cout << "Converting time to 12 hour format..." << endl;
    test_time_one.convertateToAMPMformat();
    cout << test_time_one << endl;


    cout << "It is necessary to add one more time." << endl;
    cout << "Enter please the time in 24-x format in hours, minutes, seconds by a space. Example: 23:59:59" << endl;
    cin >> test_time_two;
    cout << endl;
    cout << "You have entered: " << test_time_two << endl;

    cout << "Converting time to 12 hour format..." << endl;
    test_time_two.convertateToAMPMformat();
    cout << test_time_two << endl;

    test_time_one.convertateToStandatformat();
    test_time_two.convertateToStandatformat();

    cout << "Adding two dates... " << endl;
    Time time_add = test_time_one + test_time_two;
    cout << time_add << endl;

    cout << "Subtracting two dates... " << endl;
    Time time_Sub = test_time_one - test_time_two;
    cout << time_Sub << endl;

    cout << "Adding a second date to the first... " << endl;
    test_time_one += test_time_two;
    cout << test_time_one << endl;

    cout << "Subtracting the second date from the first... " << endl;
    test_time_one -= test_time_two;
    cout << test_time_one << endl;

    cout << "The first date is bigger than the second: " << (test_time_one > test_time_two) << endl;
    cout << "The first date is less than the second: " << (test_time_one < test_time_two) << endl;
    cout << "The first date is equal to the second: " << (test_time_one == test_time_two) << endl;
    cout << "The first date is not equal to the second: " << (test_time_one != test_time_two) << endl;

}