#include <iostream>
#include <math.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

void RGB2HSL(int R, int G, int B)
{
    float min_val, max_val, delta;
    float r, g, b, L, H, S, del_R, del_G, del_B;
    r = ((float)R / 255.0f);
    g = ((float)G / 255.0f);
    b = ((float)B / 255.0f);
    min_val = min({r, g, b});
    max_val = max({r, g, b});
    delta = max_val - min_val;
    L = (min_val + max_val)/2;

    if(0 == max_val)
    {
        /* Gray color. No chroma */
        H = 0;
        S = 0;
    }
    else
    {
        if(0.5 < L) S = max_val / (max_val + min_val);
        else S = max_val / (2 - max_val - min_val);
        del_R = ( ( ( max_val - r ) / 6 ) + ( delta / 2 ) ) / delta;
        del_G = ( ( ( max_val - g ) / 6 ) + ( delta / 2 ) ) / delta;
        del_B = ( ( ( max_val - b ) / 6 ) + ( delta / 2 ) ) / delta;

        if (r == max_val)
        {
            H = b - g;
        }
        else if(g == max_val)
        {
            H = (1 / 3) + r - b;
        }
        else if(b == max_val)
        {
            H = (2 / 3) + g - r;
        }

        if(0 > H) H += 1;
        if(1 < H) H -= 1;
    }
    cout<<H<<endl;
    cout<<S<<endl;
    cout<<L<<endl;
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
    cout<<R<<endl;
    cout<<G<<endl;
    cout<<B<<endl;
}

int main()
{
    int R = 213, G = 100, B = 32;
    float H = 360.0, S = 0.8, L = 0.12;
    HSL2RGB(H, S, L);
	return 0;
}

void RGBToHSV(int R, int G, int B)
{
	//Using algorithm from:
    //rapidtables.com/convert/color/rgb-to-hsv.html
    float R1 = (float)R / 255;
    float G1 = (float)G / 255;
    float B1 = (float)B / 255;

    float Cmax = max(max(R1, G1), B1);
    float Cmin = min(min(R1, G1), B1);

    float H, S = 0, V, dC;

    V = Cmax;

    dC = Cmax - Cmin;
    if(0 == dC)
    {
        H = 0;
    }
    else if(Cmax == R1)
    {
        H = 60 * ((( G1 - B1) / dC) % 6);
    }
    else if(Cmax == G1)
    {
        H = 60 * ((( B1 - R1) / dC) + 2);;
    }
    else if(Cmax == B1)
    {
        H = 60 * ((( G1 - B1) / dC) + 4);
    }

    if(0 != Cmax) S = dC / Cmax;


    cout << "H: " << H << endl;
    cout << "S: " << S << endl;
    cout << "V: " << V << endl;
}