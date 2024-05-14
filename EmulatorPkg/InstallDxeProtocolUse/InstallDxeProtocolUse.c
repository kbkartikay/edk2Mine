#include <PiPei.h>
#include <Library/PeiServicesLib.h>
#include <Library/HobLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiLib.h>
#include <Uefi.h>
#include<Library/UefiDriverEntryPoint.h>

extern EFI_GUID gCustomProtocolGuid;
typedef struct _CUSTOM_PROTOCOL {
  UINTN Data;
} CUSTOM_PROTOCOL;

EFI_STATUS
EFIAPI
Driver2EntryPoint(
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
)
{
  EFI_STATUS Status;
  CUSTOM_PROTOCOL *CustomProtocolInstance;
  int d =7777;
  DEBUG((DEBUG_INFO,"%d\n",d));
  Print(L"Devansh\n");
  //printf("kartikay\n");
  // Locate the protocol
  Status = gBS->LocateProtocol(&gCustomProtocolGuid, NULL, (void **)&CustomProtocolInstance);
  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "Failed to locate the custom protocol.\n"));
    return Status;
  }

  // Check the data
  DEBUG((DEBUG_INFO, "Received data: %d\n", CustomProtocolInstance->Data));
  if (CustomProtocolInstance->Data == 123) {
    DEBUG((DEBUG_INFO, "Data verification successful!\n"));
  } else {
    DEBUG((DEBUG_ERROR, "Data verification failed!\n"));
  }

  return EFI_SUCCESS;
}
