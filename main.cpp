#include <stdio.h>
#include "cconversion.h"

void TestRGB2HSL(void)
{
    ColorConv::RGB_Color_T ColorRGB = {213, 100, 32};
    ColorConv::HSL_Color_T ColorHSL;
    printf("RGB -> HSL\n");
    ColorConv::RGB2HSL(&ColorRGB, &ColorHSL);
    printf("RGB: %d, %d, %d\n", ColorRGB.R, ColorRGB.G, ColorRGB.B);
    printf("HSL: %.2f, %.2f, %.2f\n", ColorHSL.H, ColorHSL.S, ColorHSL.L);
    printf("--------------\n");
}

void TestHSL2RGB(void)
{
    ColorConv::HSL_Color_T ColorHSL = {1.0, 0.8, 0.12};
    ColorConv::RGB_Color_T ColorRGB;
    printf("HSL -> RGB\n");
    ColorConv::HSL2RGB(&ColorHSL, &ColorRGB);
    printf("RGB: %d, %d, %d\n", ColorRGB.R, ColorRGB.G, ColorRGB.B);
    printf("HSL: %.2f, %.2f, %.2f\n", ColorHSL.H, ColorHSL.S, ColorHSL.L);
    printf("--------------\n");
}

void TestRGB2HSV(void)
{
    ColorConv::RGB_Color_T ColorRGB = {213, 100, 32};
    ColorConv::HSV_Color_T ColorHSV;
    printf("RGB -> HSV\n");
    ColorConv::RGB2HSV(&ColorRGB, &ColorHSV);
    printf("RGB: %d, %d, %d\n", ColorRGB.R, ColorRGB.G, ColorRGB.B);
    printf("HSV: %.2f, %.2f, %.2f\n", ColorHSV.H, ColorHSV.S, ColorHSV.V);
    printf("--------------\n");
}

void TestHSV2RGB(void)
{
    ColorConv::HSV_Color_T ColorHSV = {1.0, 0.8, 0.12};
    ColorConv::RGB_Color_T ColorRGB;
    printf("HSV -> RGB\n");
    ColorConv::HSV2RGB(&ColorHSV, &ColorRGB);
    printf("RGB: %d, %d, %d\n", ColorRGB.R, ColorRGB.G, ColorRGB.B);
    printf("HSV: %.2f, %.2f, %.2f\n", ColorHSV.H, ColorHSV.S, ColorHSV.V);
    printf("--------------\n");
}

int main()
{
    TestRGB2HSL();
    TestHSL2RGB();
    TestRGB2HSV();
    TestHSV2RGB();
    return 0;
}