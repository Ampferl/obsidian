#ifndef __RENDER_H
#define __RENDER_H

    #include "../drivers/vga.h"
    #include "../common/graphicscontext.h"

    namespace obsidian{
        namespace gui{

            class Pixel{
                public:
                    obsidian::common::uint8_t r;
                    obsidian::common::uint8_t g;
                    obsidian::common::uint8_t b;
            };

            class Render : public obsidian::drivers::VideoGraphicsArray{
                private:
                    Pixel pixels[320][200];

                public:
                    Render(
                        common::int32_t w, common::int32_t h
                    );

                    ~Render();

                    void display(common::GraphicsContext* gc);

                    void PutPixel(obsidian::common::int32_t x, obsidian::common::int32_t y, obsidian::common::uint8_t r, obsidian::common::uint8_t g, obsidian::common::uint8_t b);
            };
        }
    }


#endif//__RENDER_H