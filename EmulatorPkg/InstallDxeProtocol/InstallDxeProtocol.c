#include <PiPei.h>
#include <Library/PeiServicesLib.h>
#include <Library/HobLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiLib.h>
#include <Uefi.h>
#include<Library/UefiDriverEntryPoint.h>

EFI_GUID gCustomProtocolGuid  = {0x0ca4886e, 0x2a4d, 0x4369, {0x97, 0x23, 0x27, 0x8c, 0xf4, 0xf8, 0x3f, 0x9f}};

typedef struct _CUSTOM_PROTOCOL {
  UINTN Data;
} CUSTOM_PROTOCOL;

EFI_STATUS
EFIAPI
Driver1EntryPoint(
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
)
{
  EFI_STATUS Status;
  CUSTOM_PROTOCOL *CustomProtocolInstance;
  
  // Allocate memory for the protocol instance
  Status = gBS->AllocatePool(EfiBootServicesData, sizeof(CUSTOM_PROTOCOL), (void **)&CustomProtocolInstance);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  // Initialize protocol data
  CustomProtocolInstance->Data = 123; // Some arbitrary data

  // Install the protocol
  Status = gBS->InstallProtocolInterface(&ImageHandle, &gCustomProtocolGuid, EFI_NATIVE_INTERFACE, CustomProtocolInstance);
  if (EFI_ERROR(Status)) {
    // Free allocated memory if installation failed
    gBS->FreePool(CustomProtocolInstance);
    return Status;
  }

  return EFI_SUCCESS;
}
