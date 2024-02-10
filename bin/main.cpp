#include <iostream>
#include "lib/mass_17btd.h"

using namespace Mass17btd;

int main(){
    Array arr = Array::make_array(3, 3, 3);
    arr[0][0][0] = 3;
    arr[0][0][1] = 6;
    arr[0][1][2] = arr[0][0][0] + arr[0][0][1] + 1;
    arr[0][0][3] = arr[0][1][2] * 3;
    arr = arr * 2;
    long int res = arr[0][0][0].to_int(), res2 = arr[0][0][1].to_int(), res3 = arr[0][1][2].to_int(), res4 = arr[0][0][3].to_int();
    std::cout << res << " " << res2 << " " << res3 << " " << res4 << std::endl;
}
