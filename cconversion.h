#ifndef CCONVERSION_H
#define CCONVERSION_H
#include <algorithm>
namespace ColorConv
{
    typedef struct 
    {
        int R;
        int G; 
        int B;
    }RGB_Color_T;

    typedef struct
    {
        float H;
        float S;
        float L;
    }HSL_Color_T;
    
    void RGB2HSL(RGB_Color_T *src, HSL_Color_T *dst);
    void HSL2RGB(HSL_Color_T *src, RGB_Color_T *dst);
}

#endif