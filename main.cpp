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

void RGBConvertToHSL(RGB_Color *src, HSL_Color *dest);

void HSLConvertToRGB(HSL_Color *src, RGB_Color *dest);

int main()
{
	RGB_Color a = { .R = 251,
		   	.G = 30,
			.B = 21};
	HSL_Color a1 = {0};

	HSL_Color b = { .H = 0,
			.S = 100,
			.L = 50};
	RGB_Color b1 = {0};
	RGBConvertToHSL(&a, &a1);
//	HSLConvertToRGB(&b, &b1);
	return 0;
}

void RGBConvertToHSL(RGB_Color *src, HSL_Color *dest)
{
	//Using algorithm from:
	//had2know.org/technology/hsv-rgb-conversion-formula-calculator.html
	float H, M, m, V, S, temp;

	cout<<"R "<<src->R<<endl;
	cout<<"G "<<src->G<<endl;
	cout<<"B "<<src->B<<endl;

	M = (float)max({src->R, src->G, src->B});
	m = (float)min({src->R, src->G, src->B});

	V = M/(float)255;
	M>0 ? S = 1-m/M : S=0;
	H = acos((src->R - 0.5*src->G - 0.5*src->B) / sqrt((src->R * src->R) + (src->G * src->G) + (src->B * src->B) - (src->R * src->G) - (src->R * src->B) - (src->G * src->B)));
	if(src->B > src->G) H = 360 - H;
	cout<<"H "<<H<<endl;
	cout<<"S "<<S<<endl;
	cout<<"L "<<V<<endl;
}

void HSLConvertToRGB(HSL_Color *src, RGB_Color *dest)
{
	cout<<"H "<<src->H<<endl;
	cout<<"S "<<src->S<<endl;
	cout<<"L "<<src->L<<endl;
	cout<<"Convert HSL to RGB"<<endl;
}
