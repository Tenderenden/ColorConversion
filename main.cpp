#include <iostream>
#include <math.h>
#include <stdint.h>
#include <algorithm>
using namespace std;

typedef struct RGB_Color
{
	int R;
	int G;
	int B;
}RGB_Color;

typedef struct HSL_Color
{
	int H;
	int S;
	int L;
}HSL_Color;

void RGBToHSL(int R, int G, int B);

void HSLToRGB(int H, int S, int L);

float Hue2RGB(float v1, float v2, float vH )
{
    if ( vH < 0 ) vH += 1;
    if( vH > 1 ) vH -= 1;
    if ( ( 6 * vH ) < 1 ) return ( v1 + ( v2 - v1 ) * 6 * vH );
    if ( ( 2 * vH ) < 1 ) return ( v2 );
    if ( ( 3 * vH ) < 2 ) return ( v1 + ( v2 - v1 ) * ( ( 2 / 3 ) - vH ) * 6 );
    return ( v1 );
}


void HSL2RGB(float H, float S, float L)
{
    //Using algorithm from http://www.easyrgb.com/en/math.php#text19
    float R, G, B, var_1, var_2;
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
    int R = 255, G = 255, B = 255;
    //RGBToHSL(R, G, B);
    float H = 360.0, S = 0.8, L = 0.12;
    HSL2RGB(H, S, L);
    //HSLToRGB(H, S, L);
	return 0;
}

void RGBToHSL(int R, int G, int B)
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
        H = 60 * ((int)(( G1 - B1) / dC) % 6);
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

void HSLToRGB(int H, int S, int L)
{
	cout<<"Convert HSL to RGB"<<endl;
}
