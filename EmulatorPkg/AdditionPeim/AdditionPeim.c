#include <PiPei.h>

#include <Library/PcdLib.h>
#include <Library/PeiServicesLib.h>

#include <Library/DebugLib.h>
#include <Library/PeimEntryPoint.h>


EFI_GUID gAdditionPpiGuid = { 0x12345678, 0x1234, 0x5678, { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0 } };

typedef struct _ADDITION_PPI {
  UINT64 (*AddNumbers)(UINT64 A, UINT64 B);
} ADDITION_PPI;

UINT64 AdditionFunction(UINT64 A, UINT64 B) {
  return A + B;
}

ADDITION_PPI mAdditionPpi = {
  AdditionFunction
};

EFI_PEI_PPI_DESCRIPTOR mAdditionPpiList = {
  (EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
  &gAdditionPpiGuid,
  &mAdditionPpi
};

EFI_STATUS
EFIAPI
AdditionPeimEntryPoint (
  IN EFI_PEI_FILE_HANDLE FileHandle,
  IN CONST EFI_PEI_SERVICES **PeiServices
  )
{
  EFI_STATUS Status;

  DEBUG ((DEBUG_INFO, "Addition PEIM Loaded\n"));

  Status = PeiServicesInstallPpi (&mAdditionPpiList);
  ASSERT_EFI_ERROR (Status);

  return Status;
}