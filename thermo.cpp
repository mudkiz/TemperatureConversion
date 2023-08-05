#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
/*
Austin Niwa
8/5/23
This program is designed to read cities and fahrenheit temps from a file and output them in celcius
*/
using namespace std;
using std::string;
int main() {
    string city = "";
    int
        celcius =  0,
        fahrenheit = 0;
    
    ifstream myInFile;//instream
    ofstream myOutFile;//outstream so the temperatures can be outputted

    myInFile.open("FahrenheitTemperature.txt");
    myOutFile.open("CelciusTemperature.txt");
    if (!myInFile) {
        cout << "File not found!!";//fail safe
        return 1;
    }//if
    else {//an else and while loop to run through the list until it is done
        while (myInFile >> city >> fahrenheit) {
            celcius = (fahrenheit - 32) * (5.0 / 9.0);//i ended up putting the celcius calculation in the loop as putting it above or below resulted in incorrect math
            cout << city << " Celcius " << celcius << endl;//added a cout because it didn't feel right without one
            myOutFile << city << " Celcius " << celcius << endl;//outputs celcius temperatures to the file CelsiusTemperature.txt
            
    }//else
}
    cout << endl;//endlines to make the cout look better 
    cout << "Temperatures have been outputted in celcius to the file CelsiusTemperature.txt";
    cout << endl;
    return 0;
    myInFile.close();//files closed as specified
    myOutFile.close();
}//main