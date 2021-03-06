#ifndef EFI_COMMON_HPP
#define EFI_COMMON_HPP





enum EFI_STATUS
  {
  EFI_SUCCESS            = 0,
  EFI_LOAD_ERROR         = 0x8000000000000001,
  EFI_INVALID_PARAMETER  = 0x8000000000000002,
  EFI_UNSUPPORTED        = 0x8000000000000003,
  EFI_BAD_BUFFER_SIZE    = 0x8000000000000004,
  EFI_BUFFER_TOO_SMALL   = 0x8000000000000005,
  EFI_NOT_READY          = 0x8000000000000006,
  EFI_DEVICE_ERROR       = 0x8000000000000007,
  EFI_WRITE_PROTECTED    = 0x8000000000000008,
  EFI_OUT_OF_RESOURCES   = 0x8000000000000009,
  EFI_NOT_FOUND          = 0x8000000000000014,
  EFI_ABORTED            = 0x8000000000000021,
  EFI_SECURITY_VIOLATION = 0x8000000000000026,
};



#endif // EFI_COMMON_HPP
