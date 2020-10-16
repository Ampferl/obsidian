#ifndef __DESKTOP_H
#define __DESKTOP_H

    #include "widget.h"
    #include "../drivers/mouse.h"

    namespace obsidian{

        namespace gui{

            class Desktop : public CompositeWidget, public obsidian::drivers::MouseEventHandler{
                protected:
                    common::uint32_t MouseX;
                    common::uint32_t MouseY;

                public:
                    Desktop(common::int32_t w, common::int32_t h, common::uint8_t r, common::uint8_t g, common::uint8_t b);
                    ~Desktop();

                    void Draw(common::GraphicsContext* gc);

                    void OnMouseDown(obsidian::common::uint8_t button);
                    void OnMouseUp(obsidian::common::uint8_t button);
                    void OnMouseMove(int x, int y);
            };
        }
    }

#endif//__DESKTOP_H