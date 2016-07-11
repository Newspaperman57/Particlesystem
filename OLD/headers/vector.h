#ifndef _VECTOR_
#define _VECTOR_

#include <cmath>
#include <iostream>
using namespace std;

class Vector{
private:
public:
    double x;
    double y;
    Vector operator+(Vector);
    Vector operator+=(Vector);
    Vector operator-(Vector);
    Vector operator-=(Vector);
    Vector operator/(double);
    Vector operator/=(double);
    Vector operator*(double);
    Vector operator*=(double);
    bool   operator==(Vector);
    static double GetDistance(Vector, Vector);
    static double GetLength(Vector);
    static Vector Normalize(Vector);
    static Vector Pow(Vector, int);
    double GetLength();
    void Normalize();
    void Rotate(double);
};

#endif