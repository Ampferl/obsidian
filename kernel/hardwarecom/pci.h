#ifndef __PCI_H
#define __PCI_H

    #include "port.h"
    #include "../drivers/driver.h"
    #include "../common/types.h"
    #include "interrupts.h"

    namespace obsidian{

        namespace hardwarecom{
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

                void SelectDrivers(obsidian::drivers::DriverManager* driverManager);
                PeripheralComponentInterconnectDeviceDescriptor GetDeviceDescriptor(obsidian::common::uint16_t bus, obsidian::common::uint16_t device, obsidian::common::uint16_t function);
            };
        }
    }

#endif//__PCI_H