#include <iostream>
#include <algorithm>
namespace ColorConv
{
    typedef struct 
    {
        char R;
        char G; 
        char B;
    }RGB_Color_T;

    typedef struct
    {
        float H;
        float S;
        float V;
    }HSL_Color_T;
    
    void RGB2HSL(int R, int G, int B);
    void HSL2RGB(float H, float S, float L);
}