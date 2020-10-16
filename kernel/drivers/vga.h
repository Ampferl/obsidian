#ifndef __VGA_H
#define __VGA_H

#include "../common/types.h"
#include "../hardwarecom/port.h"
#include "driver.h"

namespace obsidian{

    namespace drivers{

        class VideoGraphicsArray{
        protected:
            hardwarecom::Port8Bit miscPort;
            hardwarecom::Port8Bit crtcIndexPort;
            hardwarecom::Port8Bit crtcDataPort;
            hardwarecom::Port8Bit sequencerIndexPort;
            hardwarecom::Port8Bit sequencerDataPort;
            hardwarecom::Port8Bit graphicsControllerIndexPort;
            hardwarecom::Port8Bit graphicsControllerDataPort;
            hardwarecom::Port8Bit attributeControllerIndexPort;
            hardwarecom::Port8Bit attributeControllerReadPort;
            hardwarecom::Port8Bit attributeControllerWritePort;
            hardwarecom::Port8Bit attributeControllerResetPort;

            void WriteRegisters(common::uint8_t* registers);
            common::uint8_t* GetFrameBufferSegment();

            virtual common::uint8_t GetColorIndex(common::uint8_t r, common::uint8_t g, common::uint8_t b);


        public:
            VideoGraphicsArray();
            ~VideoGraphicsArray();

            virtual bool SupportsMode(common::uint32_t width, common::uint32_t height, common::uint32_t colordepth);
            virtual bool SetMode(common::uint32_t width, common::uint32_t height, common::uint32_t colordepth);
            virtual void PutPixel(common::uint32_t x, common::uint32_t y,  common::uint8_t r, common::uint8_t g, common::uint8_t b);
            virtual void PutPixel(common::uint32_t x, common::uint32_t y, common::uint8_t colorIndex);

            virtual void FillRectangle(common::uint32_t x, common::uint32_t y, common::uint32_t w, common::uint32_t h, common::uint8_t r, common::uint8_t g, common::uint8_t b);

        };

    }
}

#endif//__VGA_H