#include <math.h>
#include "accelerometersample.h"

AccelerometerSample::AccelerometerSample(const float mi_value, const int error_value):
    mi(mi_value),
    error(error_value)
{
}

float AccelerometerSample::getRoll()
{
    float roll = atan2(accel_y, signalGz(accel_z) * sqrt((accel_z*accel_z)+mi*(accel_x*accel_x))) * 180/3.14159;

    return roll;
}

float AccelerometerSample::getPitch()
{
    float pitch = atan2(-accel_x, sqrt((accel_y*accel_y)+(accel_z*accel_z))) * 180/3.14159;

    return pitch;
}

int AccelerometerSample::getTimeStamp()
{
    return timestamp;
}

int AccelerometerSample::signalGz(float az)
{    
    if(az<0) return -1;
    
    return 1;
}

bool AccelerometerSample::verifyConstraint()
{
    float root_sum = sqrt((accel_x*accel_x) + (accel_y*accel_y) + (accel_z*accel_z));
    float diff = 980-root_sum;
    diff = sqrt(diff*diff);
    if(diff > error)
        return false;
    return true;
}