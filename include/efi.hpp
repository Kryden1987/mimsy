#ifndef EFI_HPP
#define EFI_HPP

#include "efi_types.hpp"

struct efi_table_header
  {
  u64 Signature;
  u32 Revision;
  u32 HeaderSize;
  u32 CRC32;
  u32 Reserved;
};

struct efi_simple_text_output_protocol
  {
  u64 Reset;
  EFI_STATUS (*OutputString)(void*,unsigned short*);
  u64 TestString;
  u64 QueryMode;
  u64 SetMode;
  EFI_STATUS (*SetAttribute)(void*,unsigned long long int);
  u64 ClearScreen;
  u64 SetCursorPosition;
  u64 EnableCursor;
};

struct efi_simple_text_input_protocol
  {

};

struct efi_boot_services
  {

};

struct efi_runtime_services
  {

};


struct efi_configuration_table
  {

};

struct efi_system_table
  {
  efi_table_header                 Header;
  char16                          *FirmwareVendor;
  u32                              FirmwareRevision;
  efi_handle                       ConsoleInputHandle;
  efi_simple_text_input_protocol  *ConsoleInput;
  efi_handle                       ConsoleOutputHandle;
  efi_simple_text_output_protocol *ConsoleOutput;
  efi_handle                       StandardErrorHandle;
  efi_simple_text_output_protocol *StandardError;
  efi_runtime_services            *RuntimeServices;
  efi_boot_services               *BootServices;
  efi_uintn                        NumberOfTableEntries;
  efi_configuration_table          ConfigurationTable;
  };





#endif // EFI_HPP
