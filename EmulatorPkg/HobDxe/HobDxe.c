#include <PiPei.h>
#include <Library/PeiServicesLib.h>
#include <Library/HobLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiLib.h>
#include <Uefi.h>
#include<Library/UefiDriverEntryPoint.h>

extern EFI_GUID gCustomHobGuid;

typedef struct {
  EFI_HOB_GUID_TYPE EfiHobGuidType;
  CHAR16 Name[32];
  CHAR16 City[32];
  CHAR16 Company[32];
} CUSTOM_HOB_DATA;

EFI_STATUS
EFIAPI
CustomHobDxeEntryPoint(
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
)
{
  CUSTOM_HOB_DATA *HobData;
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_HOB_GENERIC_HEADER *Hob;
  Hob = GetFirstGuidHob(&gCustomHobGuid);
  if (Hob == NULL) {
    DEBUG((EFI_D_ERROR, "Failed to find Custom HOB\n"));
    return EFI_NOT_FOUND;
  }
  HobData = GET_GUID_HOB_DATA (Hob);

  // Display the data from the HOB
  Print(L"Name: %s, City: %s, Company: %s\n",
        HobData->Name, HobData->City, HobData->Company);

  return Status;
}

