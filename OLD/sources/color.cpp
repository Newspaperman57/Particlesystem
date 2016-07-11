#include "color.h"

void Color::TO_HSV(int H, int S, int V)
{
    unsigned char region, remainder, p, q, t;

    if (S == 0)
    {
        r = V;
        g = V;
        b = V;
    }

    region = H / 43;
    remainder = (H - (region * 43)) * 6; 

    p = (V * (255 - S)) >> 8;
    q = (V * (255 - ((S * remainder) >> 8))) >> 8;
    t = (V * (255 - ((S * (255 - remainder)) >> 8))) >> 8;

    switch (region)
    {
        case 0:
            r = V; g = t; b = p;
            break;
        case 1:
            r = q; g = V; b = p;
            break;
        case 2:
            r = p; g = V; b = t;
            break;
        case 3:
            r = p; g = q; b = V;
            break;
        case 4:
            r = t; g = p; b = V;
            break;
        default:
            r = V; g = p; b = q;
            break;
    }
}
