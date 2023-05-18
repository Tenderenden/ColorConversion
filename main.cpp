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

int main()
{
    int R = 255, G = 255, B = 255;
    //int H, S, L;
    RGBToHSL(R, G, B);
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
