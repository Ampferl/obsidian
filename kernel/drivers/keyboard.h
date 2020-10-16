#ifndef __KEYBOARD_H
#define __KEYBOARD_H

    #include "../common/types.h"
    #include "../hardwarecom/interrupts.h"
    #include "driver.h"
    #include "../hardwarecom/port.h"


    namespace obsidian{

        namespace drivers{

            class KeyboardEventHandler{
            public:
                KeyboardEventHandler();

                virtual void OnKeyDown(char);
                virtual void OnKeyUp(char);
            };

            class KeyboardDriver : public obsidian::hardwarecom::InterruptHandler, public Driver{
                obsidian::hardwarecom::Port8Bit dataport;
                obsidian::hardwarecom::Port8Bit commandport;
                KeyboardEventHandler* handler;
            public:
                KeyboardDriver(obsidian::hardwarecom::InterruptManager* manager, KeyboardEventHandler *handler);
                ~KeyboardDriver();
                virtual obsidian::common::uint32_t HandleInterrupt(obsidian::common::uint32_t esp);
                virtual void Activate();
            };
        }
    }


#endif//__KEYBOARD_H