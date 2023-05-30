#include <iostream>
#include <math.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

void RGB2HSL(int R, int G, int B)
{
    //R, G and B input range = 0 ÷ 255
    //H, S and L output range = 0 ÷ 1.0
    float var_R, var_G, var_B;
    float var_Min, var_Max, del_Max;
    float del_R, del_G, del_B;
    float H, S, L;
    var_R = ( (float)R / 255 );
    var_G = ( (float)G / 255 );
    var_B = ( (float)B / 255 );

    var_Min = min({ var_R, var_G, var_B });    //Min. value of RGB
    var_Max = max({ var_R, var_G, var_B });    //Max. value of RGB
    del_Max = var_Max - var_Min;             //Delta RGB value

    L = ( var_Max + var_Min )/ 2;

    if ( del_Max == 0 )                     //This is a gray, no chroma...
    {
        H = 0;
        S = 0;
    }
    else                                    //Chromatic data...
    {
        if ( L < 0.5 ) S = del_Max / ( var_Max + var_Min );
        else           S = del_Max / ( 2 - var_Max - var_Min );

        del_R = ( ( ( var_Max - var_R ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
        del_G = ( ( ( var_Max - var_G ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
        del_B = ( ( ( var_Max - var_B ) / 6 ) + ( del_Max / 2 ) ) / del_Max;

        if      ( var_R == var_Max ) H = del_B - del_G;
        else if ( var_G == var_Max ) H = ( 1 / 3 ) + del_R - del_B;
        else if ( var_B == var_Max ) H = ( 2 / 3 ) + del_G - del_R;

            if ( H < 0 ) H += 1;
            if ( H > 1 ) H -= 1;
    }
    H *= 360;
    cout << H << endl;
    cout << S << endl;
    cout << L << endl;
}

float Hue2RGB(float v1, float v2, float vH )
{
    if ( vH < 0 ) vH += 1.0f;
    if( vH > 1 ) vH -= 1.0f;
    if ( ( 6.0f * vH ) < 1.0f ) return ( v1 + ( v2 - v1 ) * 6.0f * vH );
    if ( ( 2.0f * vH ) < 1.0f ) return ( v2 );
    if ( ( 3.0f * vH ) < 2.0f ) return ( v1 + ( v2 - v1 ) * ( ( 2.0f / 3.0f ) - vH ) * 6.0f );
    return ( v1 );
}


void HSL2RGB(float H, float S, float L)
{
    //H, S and L input range = 0 ÷ 1.0
    //R, G and B output range = 0 ÷ 255
    //Using algorithm from http://www.easyrgb.com/en/math.php#text19
    float R, G, B, var_1, var_2;
    H = H / 360;
    if ( S == 0 )
    {
        R = L * 255.0;
        G = L * 255.0;
        B = L * 255.0;
    }
    else
    {
        if ( L < 0.5 ) var_2 = L * ( 1.0 + S );
        else           var_2 = ( L + S ) - ( S * L );

        var_1 = 2.0 * L - var_2;

        R = 255.0 * Hue2RGB( var_1, var_2, H + ( 1.0 / 3.0 ) );
        G = 255.0 * Hue2RGB( var_1, var_2, H );
        B = 255.0 * Hue2RGB( var_1, var_2, H - ( 1.0 / 3.0 ) );
    }
    cout << R << endl;
    cout << G << endl;
    cout << B << endl;
}

int main()
{
    int R = 213, G = 100, B = 32;
    cout << "RGB -> HSL" << endl;
    RGB2HSL(R, G, B);
    cout << "HSL -> RGB" << endl;
    float H = 360.0, S = 0.8, L = 0.12;
    HSL2RGB(H, S, L);
	
    return 0;
}