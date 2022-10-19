#include <windows.h>

using namespace std;

using RtlAdjustPrivilege = NTSTATUS(NTAPI*)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);
using NtRaiseHardError = NTSTATUS(NTAPI*)(NTSTATUS ErrorStatus, ULONG NumberOfPararmeters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);

int main()
{
    RtlAdjustPrivilege adjustPrivilege = (RtlAdjustPrivilege)GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
    BOOLEAN dummy;
    adjustPrivilege(19, TRUE, FALSE, &dummy);
    NtRaiseHardError raiseHardError = (NtRaiseHardError)GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtRaiseHardError");
    ULONG dummy2;
    raiseHardError(STATUS_NO_MEMORY, 0, 0, 0, 6, &dummy2);
}
