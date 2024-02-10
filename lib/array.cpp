#include "mass_17btd.h"


using namespace Mass17btd;

Array::Array(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->arr = new uint8_t[x * y * z];
    for (int i = 0; i < x * y * z; i++) {
        arr[i] = 0;
    }
}


Array::~Array() {
    delete[] this->arr;
}


Array Array::make_array(int x, int y, int z) {
    return Array(x, y, z);
}


Segment Array::operator[](int coord){
    return Segment(*this, coord);
}


/*std::istream &operator>>(std::istream &in, Array &arr) {
    for (int i = 0; i < arr.x * arr.y * arr.z; i++) {
        in >> arr[i % arr.x][i / arr.x % arr.y][i / arr.x / arr.y];
    }
    return in;
}


std::ostream &operator<<(std::ostream &out, Array &arr) {
    for(int i = 0; i < arr.x * arr.y * arr.z; i++){
        out << arr[i % arr.x][i / arr.x % arr.y][i / arr.x / arr.y] << " ";
    }
    return out;
}*/


Array operator*(Array &arr, int num) {
    Array new_arr = Array::make_array(arr.x, arr.y, arr.z);
    for (int i = 0; i < arr.x * arr.y * arr.z * 17 / 8; i++) {  // TODO: make with ceil
        new_arr[i % arr.x][i / arr.x % arr.y][i / arr.x / arr.y] = arr[i % arr.x][i / arr.x % arr.y][i / arr.x / arr.y] * num;
    }
    return new_arr;
}


Array operator+(Array &arr1, Array &arr2) {
    if (arr1.x != arr2.x || arr1.y != arr2.y || arr1.z != arr2.z) {
        throw std::invalid_argument("Arrays have different sizes");
    }

    Array new_arr = Array::make_array(arr1.x, arr1.y, arr1.z);
    for (int i = 0; i < arr1.x * arr1.y * arr1.z; i++) {
        new_arr[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y] =
                arr1[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y]
                + arr2[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y];
    }
    return new_arr;
}


Array operator-(Array &arr1, Array &arr2) {
    if (arr1.x != arr2.x || arr1.y != arr2.y || arr1.z != arr2.z) {
        throw std::invalid_argument("Arrays have different sizes");
    }

    Array new_arr = Array::make_array(arr1.x, arr1.y, arr1.z);
    for (int i = 0; i < arr1.x * arr1.y * arr1.z; i++) {
        new_arr[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y] =
                arr1[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y]
                - arr2[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y];
    }
    return new_arr;
}


Array operator/(Array &arr1, int num) {
    if (num == 0) {
        throw std::invalid_argument("Division by zero");
    }

    Array new_arr = Array::make_array(arr1.x, arr1.y, arr1.z);
    for (int i = 0; i < arr1.x * arr1.y * arr1.z; i++) {
        new_arr[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y] =
                arr1[i % arr1.x][i / arr1.x % arr1.y][i / arr1.x / arr1.y]
                / num;
    }
    return new_arr;
}



