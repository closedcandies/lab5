#include "mass_17btd.h"

using namespace Mass17btd;


Segment::Segment(Array& parental_array, int z){
    this->parental_array = &parental_array;
    this->start_bit = z * parental_array.x * parental_array.y * SIZE;
    this->lengh = parental_array.x * parental_array.y * parental_array.z * SIZE;
}


/*Segment::~Segment() {
    delete &start_bit;
    delete &lengh;
}*/


Segment Segment::operator[](int coord){     // TODO: make python features
    if (lengh > parental_array->x * SIZE){
        start_bit += coord * parental_array->x * SIZE;
        lengh = parental_array->x * SIZE;
    }
    else{
        start_bit += coord * SIZE;
        lengh = SIZE;
    }

    return *this;
}


long int Segment::to_int(){
    // TODO: replace it with sum of whole matrix
    if (lengh > SIZE){
        throw std::invalid_argument("Segment is too big. Try to fill every coord(Ex: mass[x][y][z])");
    }

    int start_byte = this->start_bit / 8, end_byte = (this->start_bit + SIZE) / 8;
    int start = this->start_bit % 8, end = (this->start_bit + SIZE) % 8;

    long int total = 0;
    long int add = 1 << (SIZE - 1);
    for (int i = start; i < 8; i++){
        if (parental_array->arr[start_byte] & (1 << (7 - i))){
            total += add;
        }
        add = add >> 1;
    }

    for (int i = 0; i < 8; i++){
        if (parental_array->arr[start_byte + 1] & (1 << (7 - i))){
            total += add;
        }
        add = add >> 1;
    }

    for (int i = 0; i < end; i++){
        if (parental_array->arr[end_byte] & (1 << (7 - i))){
            total += add;
        }
        add = add >> 1;
    }
    return total;
}


Segment* Segment::operator=(long new_value) {
    // TODO: replace it with filling every coord
    if (lengh > SIZE){
        throw std::invalid_argument("Segment contains multiple values. Try to fill every coord(Ex: mass[x][y][z] = value).");
    }

    int start_byte = this->start_bit / 8, end_byte = (this->start_bit + SIZE) / 8;
    int start = this->start_bit % 8, end = (this->start_bit + SIZE) % 8;

    int delta = SIZE - 1;
    // inserting new value into first byte
    for (int i = start; i < 8; i++){
        if (1 << delta & new_value){
            parental_array->arr[start_byte] = parental_array->arr[start_byte] | 128 >> i;
        }
        else{
            if (parental_array->arr[end_byte] & (128 >> i)){
                parental_array->arr[end_byte] -= 128 >> i;
            }
        }
        delta--;
    }
    // inserting new value into byte between first and last
    for (int i = 0; i < 8; i++){
        if (1 << delta & new_value){
            parental_array->arr[start_byte + 1] = parental_array->arr[start_byte + 1] | 128 >> i;
        }
        else{
            if (parental_array->arr[end_byte] & (128 >> i)){
                parental_array->arr[end_byte] -= 128 >> i;
            }
        }
        delta--;
    }
    // inserting new value into last byte
    for (int i = 0; i < end; i++){
        if (1 << delta & new_value){
            parental_array->arr[end_byte] = parental_array->arr[end_byte] | 128 >> i;
        }
        else{
            if (parental_array->arr[end_byte] & (128 >> i)){
                parental_array->arr[end_byte] -= 128 >> i;
            }
        }
        delta--;
    }

    return this;
}


Segment* Segment::operator=(Segment* new_value){
    if (this == new_value) return this;

    long int value = new_value->to_int();
    *this = value;
    return this;
}


long int Segment::operator+(Segment add_value){
    return this->to_int() + add_value.to_int();
}


long int operator+(int left, Segment right){
    return left + right.to_int();
}


long int Segment::operator+(int add_value){
    return this->to_int() + add_value;
}


long int Segment::operator-(Segment minus_value){
    return this->to_int() - minus_value.to_int();
}


long int operator-(int left, Segment& right){
    return left - right.to_int();
}


long int Segment::operator-(int minus_value){
    return this->to_int() - minus_value;
}


long int Segment::operator*(Segment& mult_value){
    return this->to_int() * mult_value.to_int();
}


long int operator*(int left, Segment& right){
    return left * right.to_int();
}


long int Segment::operator*(int mult_value){
    return this->to_int() * mult_value;
}


long int Segment::operator/(Segment& div_value){
    return this->to_int() / div_value.to_int();
}


long int operator/(int left, Segment& right){
    return left / right.to_int();
}


long int Segment::operator/(int div_value){
    return this->to_int() / div_value;
}


std::ostream& operator<<(std::ostream &out, Segment &seg) {
    out << seg.to_int();
    return out;
}


std::istream& operator>>(std::istream &in, Segment &seg) {
    long int value;
    in >> value;
    seg = value;
    return in;
}

