#include <Windows.h> 
#include <d3d11.h> 

// Windows Library Files:
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")


#pragma comment(lib, "d3d11.lib")
//#pragma comment(lib, "FW1FontWrapper.lib")
#include "BeaEngine\Include\BeaEngine.h"

//#pragma comment(lib, "BeaEngine64.lib")
#include "fw1\FW1FontWrapper\Source\FW1FontWrapper.h"


// Windows Header Files:
#include <windows.h>
#include <Mmsystem.h>
#include <intrin.h>
#include <emmintrin.h>  
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <Psapi.h>
#include "MinHook\include\MinHook.h"
#include <timeapi.h>
#include <time.h>

// Additional Header Files:
#include "Log.h"
#include "types.h"
#include "CrossMapping.h"
#include "NativeInvoker.h"
#include "nativeCaller.h"
#include "natives.h"
#include "Memory.h"
#include "Hooking.h"

#include <locale>
#include <codecvt>
#include <stdio.h>