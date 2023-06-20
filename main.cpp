#include <iostream>
//#include <math.h>
#include <stdint.h>
#include <algorithm>
#include "cconversion.h"

using namespace std;

int main()
{
    ColorConv::HSL_Color_T ColorHSL;
    ColorConv::RGB_Color_T ColorRGB = 
    {
        .R = 213,
        .G = 100,
        .B = 32
    };

    printf("RGB -> HSL\n");
    ColorConv::RGB2HSL(&ColorRGB, &ColorHSL);
    printf("H: %f, S: %f, L: %d\n", ColorHSL.H, ColorHSL.S, ColorHSL.L);


    printf("HSL -> RGB\n");
    ColorHSL.H = 1.0;
    ColorHSL.S = 0.8;
    ColorHSL.L = 0.12;
    ColorConv::HSL2RGB(&ColorHSL, &ColorRGB);
    printf("R: %d, G: %d, B: %d\n", ColorRGB.R, ColorRGB.G, ColorRGB.B);
    
    return 0;
}