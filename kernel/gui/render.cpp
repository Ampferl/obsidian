#include "render.h"

using namespace obsidian;
using namespace obsidian::common;
using namespace obsidian::gui;

Render::Render(common::int32_t w, common::int32_t h){

}

Render::~Render(){

}

void Render::display(GraphicsContext* gc){
    for(int ix = 0; ix < 320; ix++){
        for(int iy = 0; iy < 200; iy++){
            gc->PutPixel(ix,iy, pixels[ix][iy].r, pixels[ix][iy].g, pixels[ix][iy].b);
        }
    }
}

void Render::PutPixel(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b){
    pixels[x][y].r = r;
    pixels[x][y].g = g;
    pixels[x][y].b = b;
}