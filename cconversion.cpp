#include "cconversion.h"
namespace ColorConv
{
    static float Hue2RGB(float v1, float v2, float vH)
    {
        if ( vH < 0 ) vH += 1.0f;
        else if( vH > 1 ) vH -= 1.0f;
        if ( ( 6.0f * vH ) < 1.0f ) return ( v1 + ( v2 - v1 ) * 6.0f * vH );
        if ( ( 2.0f * vH ) < 1.0f ) return ( v2 );
        if ( ( 3.0f * vH ) < 2.0f ) return ( v1 + ( v2 - v1 ) * ( ( 2.0f / 3.0f ) - vH ) * 6.0f );
        return ( v1 );
    }

    /*  R, G and B input range = 0 ÷ 255
        H, S and L output range = 0 ÷ 1.0 */
    void RGB2HSL(RGB_Color_T *src, HSL_Color_T *dst)
    {
        float var_R, var_G, var_B;
        float var_Min, var_Max, del_Max;
        float del_R, del_G, del_B;
        var_R = ( (float)src->R / 255 );
        var_G = ( (float)src->G / 255 );
        var_B = ( (float)src->B / 255 );

        var_Min = std::min({ var_R, var_G, var_B });    //Min. value of RGB
        var_Max = std::max({ var_R, var_G, var_B });    //Max. value of RGB
        del_Max = var_Max - var_Min;             //Delta RGB value

        dst->L = ( var_Max + var_Min )/ 2;

        if ( del_Max == 0 )                     //This is a gray, no chroma...
        {
            dst->H = 0;
            dst->S = 0;
        }
        else                                    //Chromatic data...
        {
            if ( dst->L < 0.5 ) dst->S = del_Max / ( var_Max + var_Min );
            else           dst->S = del_Max / ( 2 - var_Max - var_Min );

            del_R = ( ( ( var_Max - var_R ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
            del_G = ( ( ( var_Max - var_G ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
            del_B = ( ( ( var_Max - var_B ) / 6 ) + ( del_Max / 2 ) ) / del_Max;

            if      ( var_R == var_Max ) dst->H = del_B - del_G;
            else if ( var_G == var_Max ) dst->H = ( 1 / 3 ) + del_R - del_B;
            else if ( var_B == var_Max ) dst->H = ( 2 / 3 ) + del_G - del_R;

                if ( dst->H < 0 ) dst->H += 1;
                else if ( dst->H > 1 ) dst->H -= 1;
        }
    }
    
    
    /*  H, S and L input range = 0 ÷ 1.0
        R, G and B output range = 0 ÷ 255
        Using algorithm from http://www.easyrgb.com/en/math.php#text19 */
    void HSL2RGB(HSL_Color_T *src, RGB_Color_T *dst)
    {
        float R, G, B, var_1, var_2;
        if ( src->S == 0 )
        {
            dst->R = src->L * 255.0;
            dst->G = src->L * 255.0;
            dst->B = src->L * 255.0;
        }
        else
        {
            if ( src->L < 0.5 ) var_2 = src->L * ( 1.0 + src->S );
            else var_2 = ( src->L + src->S ) - ( src->S * src->L );

            var_1 = 2.0 * src->L - var_2;

            dst->R = 255.0 * Hue2RGB( var_1, var_2, src->H + ( 1.0 / 3.0 ) );
            dst->G = 255.0 * Hue2RGB( var_1, var_2, src->H );
            dst->B = 255.0 * Hue2RGB( var_1, var_2, src->H - ( 1.0 / 3.0 ) );
        }
    }

    void RGB2HSV(RGB_Color_T *src, HSV_Color_T *dst)
    {
        float var_R, var_G, var_B;
        float var_Min, var_Max, del_Max;
        float del_R, del_G, del_B;
        var_R = ( (float)src->R / 255 );
        var_G = ( (float)src->G / 255 );
        var_B = ( (float)src->B / 255 );

        var_Min = std::min({ var_R, var_G, var_B });    //Min. value of RGB
        var_Max = std::max({ var_R, var_G, var_B });    //Max. value of RGB
        del_Max = var_Max - var_Min;             //Delta RGB value

        dst->V = var_Max;

        if ( del_Max == 0 )                     //This is a gray, no chroma...
        {
            dst->H = 0;
            dst->S = 0;
        }
        else                                    //Chromatic data...
        {
            dst->S = del_Max / var_Max;

            del_R = ( ( ( var_Max - var_R ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
            del_G = ( ( ( var_Max - var_G ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
            del_B = ( ( ( var_Max - var_B ) / 6 ) + ( del_Max / 2 ) ) / del_Max;

            if      ( var_R == var_Max ) dst->H = del_B - del_G;
            else if ( var_G == var_Max ) dst->H = ( 1 / 3 ) + del_R - del_B;
            else if ( var_B == var_Max ) dst->H = ( 2 / 3 ) + del_G - del_R;

                if ( dst->H < 0 ) dst->H += 1;
                else if ( dst->H > 1 ) dst->H -= 1;
        }
    }
    
    /* H, S and V input range = 0 ÷ 1.0
    R, G and B output range = 0 ÷ 255 */
    void HSV2RGB(HSV_Color_T *src, RGB_Color_T *dst)
    {
        float var_h, var_i, var_1, var_2, var_3, var_r, var_g, var_b;
        if ( src->S == 0 )
        {
            dst->R = src->V * 255;
            dst->G = src->V * 255;
            dst->B = src->V * 255;
        }
        else
        {
            var_h = src->H * 6;
            if ( var_h == 6 ) var_h = 0;      //H must be < 1
            var_i = int( var_h );             //Or ... var_i = floor( var_h )
            var_1 = src->V * ( 1 - src->S );
            var_2 = src->V * ( 1 - src->S * ( var_h - var_i ) );
            var_3 = src->V * ( 1 - src->S * ( 1 - ( var_h - var_i ) ) );

            if      ( var_i == 0 ) 
            {
                var_r = src->V;
                var_g = var_3;
                var_b = var_1;
            }
            else if ( var_i == 1 ) 
            { 
                var_r = var_2;
                var_g = src->V;
                var_b = var_1;
            }
            else if ( var_i == 2 ) 
            {
                var_r = var_1;
                var_g = src->V;
                var_b = var_3;
            }
            else if ( var_i == 3 ) 
            {
                var_r = var_1;
                var_g = var_2;
                var_b = src->V;
            }
            else if ( var_i == 4 ) 
            {
                var_r = var_3;
                var_g = var_1;
                var_b = src->V;
            }
            else
            {
                var_r = src->V;
                var_g = var_1;
                var_b = var_2;
            }

            dst->R = var_r * 255;
            dst->G = var_g * 255;
            dst->B = var_b * 255;
        }
    }
}