//Draw a circle on mode 4.

#include <bitmap/mode4/m4_circle.h>

void m4_circle(u32 x0, u32 y0, int radius, m4_color_entry clr) {
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int error = dx - (radius << 1);

    while (x >= y)
    {
        m4_pixel(x0 + x, y0 + y, clr);
        m4_pixel(x0 + y, y0 + x, clr);
        m4_pixel(x0 - y, y0 + x, clr);
        m4_pixel(x0 - x, y0 + y, clr);
        m4_pixel(x0 - x, y0 - y, clr);
        m4_pixel(x0 - y, y0 - x, clr);
        m4_pixel(x0 + y, y0 - x, clr);
        m4_pixel(x0 + x, y0 - y, clr);

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