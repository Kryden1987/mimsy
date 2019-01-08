#include "efi_common.hpp"
#include "efi.hpp"
#include "efi_native.h"


struct efi
  {
  efi_handle        ImageHandle;
  efi_system_table* SystemTable;
  }__attribute__((packed));












extern "C"
{

EFI_STATUS efi_main(efi* pefi)
  {
  EFI_STATUS status = EFI_SUCCESS;

  efi_call(pefi->SystemTable->ConsoleOutput->ClearScreen,pefi->SystemTable->ConsoleOutput);


  return status;
  }

}
