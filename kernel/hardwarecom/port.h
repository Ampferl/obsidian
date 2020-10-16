#ifndef __PORT_H
#define __PORT_H


    #include "../common/types.h"

    namespace obsidian{
        namespace hardwarecom{
            class Port{
                protected:
                    Port(obsidian::common::uint16_t portnumber);
                    ~Port();
                    obsidian::common::uint16_t portnumber;
            };


            class Port8Bit : public Port{
                public:
                    Port8Bit(obsidian::common::uint16_t portnumber);
                    ~Port8Bit();

                    virtual obsidian::common::uint8_t Read();
                    virtual void Write(obsidian::common::uint8_t data);

                protected:
                    static inline obsidian::common::uint8_t Read8(obsidian::common::uint16_t _port){
                        obsidian::common::uint8_t result;
                        __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (_port));
                        return result;
                    }

                    static inline void Write8(obsidian::common::uint16_t _port, obsidian::common::uint8_t _data){
                        __asm__ volatile("outb %0, %1" : : "a" (_data), "Nd" (_port));
                    }
            };



            class Port8BitSlow : public Port8Bit{
                public:
                    Port8BitSlow(obsidian::common::uint16_t portnumber);
                    ~Port8BitSlow();

                    virtual void Write(obsidian::common::uint8_t data);
                protected:
                    static inline void Write8Slow(obsidian::common::uint16_t _port, obsidian::common::uint8_t _data){
                        __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (_data), "Nd" (_port));
                    }

            };



            class Port16Bit : public Port{
                public:
                    Port16Bit(obsidian::common::uint16_t portnumber);
                    ~Port16Bit();

                    virtual obsidian::common::uint16_t Read();
                    virtual void Write(obsidian::common::uint16_t data);

                protected:
                    static inline obsidian::common::uint16_t Read16(obsidian::common::uint16_t _port){
                        obsidian::common::uint16_t result;
                        __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (_port));
                        return result;
                    }

                    static inline void Write16(obsidian::common::uint16_t _port, obsidian::common::uint16_t _data){
                        __asm__ volatile("outw %0, %1" : : "a" (_data), "Nd" (_port));
                    }
            };



            class Port32Bit : public Port
            {
                public:
                    Port32Bit(obsidian::common::uint16_t portnumber);
                    ~Port32Bit();

                    virtual obsidian::common::uint32_t Read();
                    virtual void Write(obsidian::common::uint32_t data);

                protected:
                    static inline obsidian::common::uint32_t Read32(obsidian::common::uint16_t _port){
                        obsidian::common::uint32_t result;
                        __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (_port));
                        return result;
                    }

                    static inline void Write32(obsidian::common::uint16_t _port, obsidian::common::uint32_t _data){
                        __asm__ volatile("outl %0, %1" : : "a"(_data), "Nd" (_port));
                    }
            };
        }
    }





#endif