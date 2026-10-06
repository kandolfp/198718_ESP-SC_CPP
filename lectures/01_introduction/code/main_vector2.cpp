#include <iostream>
#include <vector>
#include <cmath>

int main(){
    std::vector<float> v1(3), v2(3),v3(3);
    v1[0] = 0; v1[1] = 0.5; v1[2] = 0.1;
    v2[0] = 0; v2[1] = sin(0.1); v2[2] = 1.0;
    v3[0] = v1[0] + v2[0];
    v3[1] = v1[1] + v2[1];
    v3[2] = v1[2] + v2[2];

    std::cout<< v3[0] <<" "<<v3[1]<<" "<<v3[2]<<std::endl;

    return 0;
}