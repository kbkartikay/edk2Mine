#include <PiPei.h>
#include <Library/PcdLib.h>
#include <Library/PeiServicesLib.h>
#include <Library/DebugLib.h>
#include <Library/PeimEntryPoint.h>

// Include the GUID definition for the Addition PPI
extern EFI_GUID gAdditionPpiGuid;

// Include the structure definition for the Addition PPI
typedef struct _ADDITION_PPI {
  UINT64 (*AddNumbers)(UINT64 A, UINT64 B);
} ADDITION_PPI;

EFI_STATUS EFIAPI UseAdditionPeimEntryPoint(
  IN EFI_PEI_FILE_HANDLE     FileHandle,
  IN CONST EFI_PEI_SERVICES  **PeiServices
  )
{
  EFI_STATUS   Status;
  ADDITION_PPI *AdditionPpi;
  UINT64       Result;

  DEBUG((DEBUG_INFO, "Use PEIM Loaded\n"));

  // Locate the Addition PPI
  Status = PeiServicesLocatePpi(
             &gAdditionPpiGuid,
             0,
             NULL,
             (VOID **)&AdditionPpi
             );
  ASSERT_EFI_ERROR(Status);

  // Use the Addition PPI to add two numbers
  Result = AdditionPpi->AddNumbers(10, 20);

  DEBUG((DEBUG_INFO, "Result of addition: %d\n", Result));

  return EFI_SUCCESS;
}