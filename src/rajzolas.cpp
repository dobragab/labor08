#include "rajzolas.h"

#include <SDL.h>
#include <SDL_gfxPrimitives.h>

static SDL_Surface *screen;

void init() {

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    screen = SDL_SetVideoMode(600, 600, 32, 0);
    SDL_WM_SetCaption("Labor08", "Labor08");

}

void rajzol() {
    SDL_Flip(screen);
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
            case SDL_KEYDOWN:
                quit = true;
                break;
            default:
                break;
        }
    }

    SDL_Quit();
}

void teglalap_rajzol(Point p1, Point p2, Color c) {
    boxColor(screen, p1.x, p1.y, p2.x, p2.y, c.convert());
}


void kor_rajzol(Point k, int atmero, Color c) {
    filledCircleColor(screen, k.x, k.y, atmero, c.convert());
}

void kerekitett_teglalap_rajzol(Point p1, Point p2, int sugar, Color c) {
    roundedBoxColor(screen, p1.x, p1.y, p2.x, p2.y, sugar, c.convert());
}

void szakasz_rajzol(Point p1, Point p2, int vastagsag, Color c) {
    thickLineColor(screen, p1.x, p1.y, p2.x, p2.y, vastagsag, c.convert());
}

void szoveg_rajzol(Point p, std::string const& szoveg, Color c) {
    stringColor(screen, p.x, p.y, szoveg.c_str(), c.convert());
}

void sokszog_rajzol(std::vector<Point> const& pontok, Color c) {
    int n = pontok.size();
    int16_t * px = new int16_t[n];
    int16_t * py = new int16_t[n];

    for(int i = 0; i < n; ++i) {
        px[i] = pontok[i].x;
        py[i] = pontok[i].y;
    }

    filledPolygonColor(screen, px, py, n, c.convert());

    delete[] py;
    delete[] px;
}

