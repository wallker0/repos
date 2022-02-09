#include <windows.h>
extern int Main(); //This line tells our compiler that our Main function is located at other place(external).

void WINAPI MainThread() //This is the fuction that will be called once we inject this dll into our game.
{
	Main(); //Here we are calling our external main function which we will add in Form1.cpp later.
}


//Below code was copied from someone from another forum. What this does is basically telling the dll what to do after injection.
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:

		DisableThreadLibraryCalls(hModule);

		if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL) == NULL) {
			return FALSE;
		}
		break;

	case DLL_PROCESS_DETACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}