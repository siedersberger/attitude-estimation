#include <list>
#include <iostream>
using namespace std;

class AccelerometerSample
{
private:
    int timestamp;
    float accel_x;
    float accel_y;
    float accel_z;
    const float mi;

public:
    AccelerometerSample(const float mi_value = 0.01);
    int getTimeStamp();
    float getRoll();
    float getPitch();
    int signalGz(float az);
    bool verifyConstraints();

    friend istream& operator>>(istream& is, AccelerometerSample& a)
    {
        char separator;
        is >> a.timestamp >> separator >> a.accel_x >> separator >> a.accel_y >> separator >> a.accel_z;
        return is;
    }
};