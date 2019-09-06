#include <list>
#include <string> 
#include <iostream>
using namespace std;

class AccelerometerSample
{
private:
    int timestamp;
    float accel_x;
    float accel_y;
    float accel_z;
    const float mi; // constant for regions of instability
    const int error; // maximum constraint error for test samples

public:
    AccelerometerSample(const float mi_value = 0.01, const int error = 100);
    int getTimeStamp();
    float getRoll();
    float getPitch();
    int signalGz(float az); // part of solution to the problem of the roll and picth instability
    bool verifyConstraint(); // verify sum of square of terms equal to square of g

    friend istream& operator>>(istream& is, AccelerometerSample& a) //overload of operator>>
    {
        char separator;
        is >> a.timestamp >> separator >> a.accel_x >> separator >> a.accel_y >> separator >> a.accel_z;
        return is;
    }
};