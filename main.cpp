#include <iostream>
//#include <math.h>
#include <stdint.h>
#include <algorithm>
#include "cconversion.h"

using namespace std;

int main()
{
    int R = 213, G = 100, B = 32;
    float H = 360.0, S = 0.8, L = 0.12;
    
    ColorConv::RGB_Color_T ColorRGB = 
    {
        .R = 213,
        .G = 100,
        .B = 32
    };

    ColorConv::HSL_Color_T ColorHSL = 
    {
        .H = 1.0,
        .S = 0.8,
        .L = 0.12
    };

    printf("RGB -> HSL\n");
    ColorConv::RGB2HSL(&ColorRGB);
    printf("HSL -> RGB\n");
    ColorConv::HSL2RGB(&ColorHSL);
    return 0;
}