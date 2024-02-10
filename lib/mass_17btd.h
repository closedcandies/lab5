#pragma once
#include <iostream>

namespace Mass17btd {

    static const int SIZE = 17;

    class Array;

    class Segment{
    public:
        int start_bit, lengh;
        Array* parental_array;

        Segment(Array& parental_array, int z);
        //~Segment();

        Segment operator[](int coord);

        Segment* operator=(long int new_value);
        Segment* operator=(Segment* new_value);

        friend long int operator+(int left, Segment right);
        long int operator+(Segment add_value);
        long int operator+(int add_value);

        friend long int operator-(int left, Segment& right);
        long int operator-(Segment minus_value);
        long int operator-(int minus_value);

        friend long int operator*(int left, Segment& right);
        long int operator*(Segment& mult_value);
        long int operator*(int mult_value);

        friend long int operator/(int left, Segment& right);
        long int operator/(Segment& div_value);
        long int operator/(int div_value);

        long int to_int();
    };
    std::ostream& operator<<(std::ostream &out, Segment &seg);
    std::istream& operator>>(std::istream &in, Segment &seg);


    class Array {
    public:
        int x, y, z;
        uint8_t *arr;

        Array(int x, int y, int z);
        ~Array();

        Segment operator[](int coord);

        static Array make_array(int x, int y, int z);

    };
    Array operator+(Array &arr1, Array &arr2);
    Array operator-(Array &arr1, Array &arr2);
    Array operator*(Array &arr, int num);
    Array operator/(Array &arr1, int num);
    /*std::istream &operator>>(std::istream &in, Array &arr);
    std::ostream &operator<<(std::ostream &out, Array &arr);*/

}
