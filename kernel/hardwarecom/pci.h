#ifndef __PCI_H
#define __PCI_H

    #include "port.h"
    #include "../drivers/driver.h"
    #include "../common/types.h"
    #include "interrupts.h"

    namespace obsidian{

        namespace hardwarecom{
            enum BaseAddressRegisterType{
                MemoryMapping = 0,
                InputOutput = 1
            };

            class BaseAddressRegister{
            public:
                bool prefetchable;
                obsidian::common::uint8_t* address;
                obsidian::common::uint32_t size;
                BaseAddressRegisterType type;
            };

            class PeripheralComponentInterconnectDeviceDescriptor{
            public:
                obsidian::common::uint32_t portBase;
                obsidian::common::uint32_t interrupt;

                obsidian::common::uint16_t bus;
                obsidian::common::uint16_t device;
                obsidian::common::uint16_t function;

                obsidian::common::uint16_t vendor_id;
                obsidian::common::uint16_t device_id;

                obsidian::common::uint8_t class_id;
                obsidian::common::uint8_t subclass_id;
                obsidian::common::uint8_t interface_id;

                obsidian::common::uint8_t revision;

                PeripheralComponentInterconnectDeviceDescriptor();
                ~PeripheralComponentInterconnectDeviceDescriptor();
            };

            class PeripheralComponentInterconnectController{
                Port32Bit dataPort;
                Port32Bit commandPort;

            public:
                PeripheralComponentInterconnectController();
                ~PeripheralComponentInterconnectController();

                obsidian::common::uint32_t Read(obsidian::common::uint16_t bus, obsidian::common::uint16_t device, obsidian::common::uint16_t function, obsidian::common::uint32_t registeroffset);
                void Write(obsidian::common::uint16_t bus, obsidian::common::uint16_t device, obsidian::common::uint16_t function, obsidian::common::uint32_t registeroffset, obsidian::common::uint32_t value);
                bool DeviceHasFunctions(obsidian::common::uint16_t bus, obsidian::common::uint16_t device);

                void SelectDrivers(obsidian::drivers::DriverManager* driverManager, obsidian::hardwarecom::InterruptManager* interrupts);
                obsidian::drivers::Driver* GetDriver(PeripheralComponentInterconnectDeviceDescriptor dev, obsidian::hardwarecom::InterruptManager* interrupts);
                PeripheralComponentInterconnectDeviceDescriptor GetDeviceDescriptor(obsidian::common::uint16_t bus, obsidian::common::uint16_t device, obsidian::common::uint16_t function);
                BaseAddressRegister GetBaseAddressRegister(obsidian::common::uint16_t bus, obsidian::common::uint16_t device, obsidian::common::uint16_t function, obsidian::common::uint16_t bar);
            };
        }
    }

#endif//__PCI_H