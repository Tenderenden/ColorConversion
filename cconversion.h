#include <iostream>
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
    
    HSL_Color_T RGB2HSL(RGB_Color_T *src);
    RGB_Color_T HSL2RGB(HSL_Color_T *src);
}