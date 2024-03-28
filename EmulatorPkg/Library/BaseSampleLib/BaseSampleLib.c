//uwuwuw

#include<Library/DebugLib.h>
#include<Base.h>
#include<Library/BaseSampleLib.h>

VOID
EFIAPI
BaseSamplePrintFunc(VOID)
{
    DEBUG(("DEBUG_INFO","[BIOS] test message from baselib\n" ));
    return;
}