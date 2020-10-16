#ifndef __MOUSE_H
#define __MOUSE_H

    #include "../common/types.h"
    #include "../hardwarecom/port.h"
    #include "driver.h"
    #include "../hardwarecom/interrupts.h"

    namespace obsidian{

        namespace drivers{

            class MouseEventHandler{
            public:
                MouseEventHandler();

                virtual void OnActivate();
                virtual void OnMouseDown(obsidian::common::uint8_t button);
                virtual void OnMouseUp(obsidian::common::uint8_t button);
                virtual void OnMouseMove(int x, int y);
            };


            class MouseDriver : public obsidian::hardwarecom::InterruptHandler, public Driver{
                obsidian::hardwarecom::Port8Bit dataport;
                obsidian::hardwarecom::Port8Bit commandport;
                obsidian::common::uint8_t buffer[3];
                obsidian::common::uint8_t offset;
                obsidian::common::uint8_t buttons;

                MouseEventHandler* handler;
            public:
                MouseDriver(obsidian::hardwarecom::InterruptManager* manager, MouseEventHandler* handler);
                ~MouseDriver();
                virtual obsidian::common::uint32_t HandleInterrupt(obsidian::common::uint32_t esp);
                virtual void Activate();
            };
        }
    }



#endif//__MOUSE_H