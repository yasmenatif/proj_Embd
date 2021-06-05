#include <math.h>
#include <stdio.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#define pi 3.14159265358979323846


double DegreeToRadian(double);
double RadianToDegree(double);

double TotalDistance(double latitude1, double longitude1, double latitude2, double longitude2) {
    double theta, distance;
    if ((latitude1 == latitude2) && (longitude1 == longitude2)) {
        return 0;
    }
    else {
        theta = longitude1 - longitude2;
        distance = sin(DegreeToRadian(latitude1)) * sin(DegreeToRadian(latitude2)) + cos(DegreeToRadian(latitude1)) * cos(DegreeToRadian(latitude2)) * cos(DegreeToRadian(theta));
        distance = acos(distance);
        distance = RadianToDegree(distance);
        distance = distance * 60 * 1.1515 * 1609.344;

        return (distance);
    }
}


double DegreeToRadian(double degree) {
    return (degree * pi / 180);
}

double RadianToDegree(double radian) {
    return (radian * 180 / pi);
}

int main() {
    double Y;
    Y = TotalDistance(34.45, 43.54, 43.54, 32.43);
    printf("TotalDistance =%lf", Y);

}