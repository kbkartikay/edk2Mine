
#include <PiPei.h>
#include <Library/PeiServicesLib.h>
#include <Library/HobLib.h>
//#include <Library/MemoryAllocationLib.h>
//#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/PeimEntryPoint.h>

EFI_GUID gCustomHobGuid  = {0x01c47e61, 0x38ee, 0x45d1, {0xb3, 0xaa, 0x0e, 0x89, 0x74, 0x82, 0xc0, 0x62}};

typedef struct {
  EFI_HOB_GUID_TYPE EfiHobGuidType;
  CHAR16 Name[32];
  CHAR16 City[32];
  CHAR16 Company[32];
} CUSTOM_HOB_DATA;

EFI_STATUS
EFIAPI
CustomHobPeimEntryPoint(
  IN EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES  **PeiServices
)
{
  CUSTOM_HOB_DATA *HobData;

  HobData = BuildGuidHob(&gCustomHobGuid, sizeof(CUSTOM_HOB_DATA));
  if (HobData == NULL) {
    DEBUG((EFI_D_ERROR, "Failed to build HOB\n"));
    return EFI_OUT_OF_RESOURCES;
  }

  // Initialize the data in the HOB
  StrCpyS(HobData->Name, ARRAY_SIZE(HobData->Name), L"Kartikay");
  StrCpyS(HobData->City, ARRAY_SIZE(HobData->City), L"New Delhi");
  StrCpyS(HobData->Company, ARRAY_SIZE(HobData->Company), L"Dell");

  DEBUG((EFI_D_INFO, "Custom HOB created successfully!\n"));
  return EFI_SUCCESS;
}
