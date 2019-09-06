#include <iostream>
#include <fstream>
#include <string>
#include "accelerometersample.h"

using namespace std;

int main()
{
    string line;
    ifstream inputFile ("logs/attitude_exam.log");
    ofstream outpuFile ("logs/roll_picth.log");
    if (inputFile.is_open())
    {
        if (outpuFile.is_open())
        {
            while(!inputFile.eof())
            {
                AccelerometerSample a;
                inputFile >> a;
                //cout << a.getTimeStamp() << "; " << a.getRoll() << "; " << a.getPitch() << endl;
                if(a.verifyConstraint()){
                    outpuFile << a.getTimeStamp() << "; " << a.getRoll() << "; " << a.getPitch() << endl;
                }else outpuFile << a.getTimeStamp() << "; Invalid sample (it does not respect the constraint)" << endl;
            }
            inputFile.close();
            outpuFile.close();
            cout << "Output log was correctly save!" << endl;
        } else {
            cout << "Unable to write log file." << endl;
            inputFile.close();
        } 
    } else cout << "Unable to open file" << endl;
  return 0;
}