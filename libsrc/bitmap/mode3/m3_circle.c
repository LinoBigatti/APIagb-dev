//Draw a circle on mode 3.

#include <bitmap/mode3/m3_circle.h>

void m3_circle(u32 x0, u32 y0, int radius, m3_color clr)
{
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int error = dx - (radius << 1);

    while (x >= y)
    {
        m3_pixel(x0 + x, y0 + y, clr);
        m3_pixel(x0 + y, y0 + x, clr);
        m3_pixel(x0 - y, y0 + x, clr);
        m3_pixel(x0 - x, y0 + y, clr);
        m3_pixel(x0 - x, y0 - y, clr);
        m3_pixel(x0 - y, y0 - x, clr);
        m3_pixel(x0 + y, y0 - x, clr);
        m3_pixel(x0 + x, y0 - y, clr);

        if (error <= 0)
        {
            y++;
            error += dy;
            dy += 2;
        }
        
        if (error > 0)
        {
            x--;
            dx += 2;
            error += dx - (radius << 1);
        }
    }
}