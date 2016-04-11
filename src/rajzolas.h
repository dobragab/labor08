#ifndef RAJZOLAS_H_INCLUDED
#define RAJZOLAS_H_INCLUDED

#include <cstdint>
#include <string>
#include <vector>

struct Point {
    int x;
    int y;

    Point(int x = 0, int y = 0) :
        x(x),
        y(y) {
    }
};

struct Color
{
    uint8_t r, g, b, a;

    Color() :
        r(0x00), g(0x00), b(0x00), a(0xFF) {
        }

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xFF) :
        r(r), g(g), b(b), a(a)
    { }

    explicit Color(uint32_t c) :
        r((c & 0xFF000000) >> 24),
        g((c & 0x00FF0000) >> 16),
        b((c & 0x0000FF00) >> 8),
        a((c & 0x000000FF) >> 0)
    { }

    uint32_t convert() const
    {
        return  r << 24 |
                g << 16 |
                b << 8  |
                a;
    }
};

void init();
void rajzol();

void teglalap_rajzol(Point p1, Point p2, Color c);
void kerekitett_teglalap_rajzol(Point p1, Point p2, int sugar, Color c);
void szakasz_rajzol(Point p1, Point p2, int vastagsag, Color c);
void kor_rajzol(Point k, int atmero, Color c);
void szoveg_rajzol(Point p, std::string const& szoveg, Color c);
void sokszog_rajzol(std::vector<Point> const& pontok, Color c);

#endif // RAJZOLAS_H_INCLUDED
