#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

float convert (char startUnit, float temp, char endUnit) {
    //converts temp parameter of mesurment startUnit paramerter to unit of endUnit parameter

    //converts from startUnit to celsius
    switch (startUnit)
    {
        case 'k':
            temp = temp - 273.15;
            break;
        case 'f':
            temp = (temp -32) * (0.555555555);
            break;
        default:
            break;
    }

    //converts from celsius to endUnit
    switch (endUnit)
    {
        case 'k':
            temp = temp + 273.15;
            break;
        case 'f':
            temp = ((temp * (1.8)) + 32);
        default:
            break;
    }
    return temp;
}

int main (int argc, char *argv[]) {

    // vector to store command line arguments
    vector<string> allArgs(argv + 1, argv+argc);

    //return 1 when no command line arguments are entered
    if (argc == 1) {
        cout << "no arguments specified (use -h for help)" << endl;
        return 1;
    }

    //help argument
    if (!allArgs[0].compare("-h")) {
        cout << "-c     celcius" << endl;
        cout << "-f     fahrenheit" << endl;
        cout << "-c     kelvin" << endl;
        cout << "example: temp -c 22 -f" << endl;
        return 2;
    }
    //not enough arguments
    else if (argc < 4) {
        cout << "not enough arguments to preform convertion (use -h for help)" << endl;
        return 3;
    }
    // convert temp
    else {
        float convertedTemp = convert(allArgs[0].at(1), stof(allArgs[1]), allArgs[2].at(1));
        cout << convertedTemp << endl;
        return 0;
    }
}