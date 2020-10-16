#ifndef __GDT_H
#define __GDT_H

    #include "common/types.h"

    namespace obsidian{
        class GlobalDescriptorTable{
            public:
                class SegmentDescriptor{
                    private:
                        obsidian::common::uint16_t limit_lo;
                        obsidian::common::uint16_t base_lo;
                        obsidian::common::uint8_t base_hi;
                        obsidian::common::uint8_t type;
                        obsidian::common::uint8_t limit_hi;
                        obsidian::common::uint8_t base_vhi;

                    public:
                        SegmentDescriptor(obsidian::common::uint32_t base, obsidian::common::uint32_t limit, obsidian::common::uint8_t type);
                        obsidian::common::uint32_t Base();
                        obsidian::common::uint32_t Limit();
                } __attribute__((packed));

            private:
                SegmentDescriptor nullSegmentSelector;
                SegmentDescriptor unusedSegmentSelector;
                SegmentDescriptor codeSegmentSelector;
                SegmentDescriptor dataSegmentSelector;

            public:
                GlobalDescriptorTable();
                ~GlobalDescriptorTable();

                obsidian::common::uint16_t CodeSegmentSelector();
                obsidian::common::uint16_t DataSegmentSelector();
        };
    }


#endif//__GDT_H