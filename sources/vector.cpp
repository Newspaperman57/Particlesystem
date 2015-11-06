#include "vector.h"

Vector Vector::operator+(Vector v) {
    return (Vector){x + v.x, y + v.y};
}

Vector Vector::operator-(Vector v) {
    return (Vector){x - v.x, y - v.y};
}

Vector Vector::operator/(double d) {
    return (Vector){x / d, y / d};
}

Vector Vector::operator*(double d) {
    return (Vector){x * d, y * d};
}

Vector Vector::operator*=(double d) {
    x = x * d;
    y = y * d;
    return *this;
}

Vector Vector::operator/=(double d) {
    x = x / d;
    y = y / d;
    return *this;
}

Vector Vector::operator+=(Vector v) {
    x = x + v.x;
    y = y + v.y;
    return *this;
}

Vector Vector::operator-=(Vector v) {
    x = x - v.x;
    y = y - v.y;
    return *this;
}

bool Vector::operator==(Vector v) {
    return (v.x == x && v.y == y);
}

Vector Vector::Pow(Vector v, int e) {
    v.x = pow(v.x, e);
    v.y = pow(v.y, e);
    return v;
}

double Vector::GetDistance(Vector v1, Vector v2) {
    return sqrt(pow(v2.x - v1.x, 2) + 
                pow(v2.y - v1.y, 2));
}

double Vector::GetLength(Vector v1) {
    return sqrt(pow(v1.x,2)+pow(v1.y,2));
}

double Vector::GetLength() {
    return sqrt(pow(x,2)+pow(y,2));
}

Vector Vector::Normalize(Vector v1) {
    return v1/GetLength(v1);
}

void Vector::Normalize() {
    *this /= GetLength();
}

void Vector::Rotate(double radians) {
    double len1 = GetLength();

    x = x*cos(radians) - y*sin(radians);
    y = y*cos(radians) + x*sin(radians);
    
    Normalize();
    *this *= len1;
}