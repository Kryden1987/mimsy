#ifndef EFI_NATIVE_H
#define EFI_NATIVE_H



extern "C"
{
extern unsigned long long int efi_call(u64 function, ...);
}


#endif // EFI_NATIVE_H
