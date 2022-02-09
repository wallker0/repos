#include "stdafx.h"
#include <mmsystem.h>
::std::unordered_map<uint64_t, uint64_t> nativeHashMap;

uint64_t __HASHMAPDATA[] = {
	0x4F8644AF03D0E0D6, 0xB5CEFD608600A09F,
	0xD80958FC74E988A6, 0xBC25C936A095B5BA,
	
	0xE28E54788CE8F12D, 0x904E94842BB9E173,
	0xE9B09589827545E7, 0x16F9568D5D08F080,
	0xFDD179EAF45B556C, 0x88B0E2A64EF693DE,
	0x9B0BB33B04405E7A, 0x7B6A06DE40F28782,
	0x520E541A97A13354, 0x38428C0051CE903C,
	0xDB172424876553F4, 0x635083B90B1A9C63,
	0xB302540597885499, 0xA98B19EC1C93FC3C,

	0x39BE7CEA8D9CC8E6, 0xCEA9F48EB9CF0CC7,
	0x3C5FD37B5499582E, 0x4EB807D82D2F9433,
	0x05A42BA9FC8DA96B, 0x020AD13B55E99AC1,
	0xC30338E8088E2E21, 0x8A55B15F4133C912,
};

void CrossMapping::initNativeMap() {
	static int init = 0;
	struct twoQwords {
		uint64_t first;
		uint64_t second;
	} *p2q;

	if (init) {
		DEBUGMSG("Already init, nativeHashMap has %lli members", nativeHashMap.size());
		return;
	}

	p2q = reinterpret_cast<twoQwords *>(__HASHMAPDATA);
	//DEBUG_OUT("p2q: %p", p2q);
	//DEBUG_OUT("p2q->first: %llx", p2q->first);
	//DEBUG_OUT("p2q->second: %llx", p2q->second);
	while (p2q->first) {
		//DEBUG_OUT("initNHM: %llx, %llx", p2q->first, p2q->second);
		nativeHashMap.emplace(p2q->first, p2q->second);
		//DEBUG_OUT("nativeHashMap now has %lli members", nativeHashMap.size());
		++p2q;
	}
	init = 1;
	DEBUGMSG("nativeHashMap has %lli members", nativeHashMap.size());
}
/*##################################################################################################*/

static nMap nativeCache;

bool CrossMapping::searchMap(nMap map, uint64_t inNative, uint64_t *outNative)
{
	bool found = false;
	//LOG_DEBUG("inNative 0x%016llx", inNative);
	for (nMap::const_iterator it = map.begin(); it != map.end(); ++it)
	{
		found = (inNative == it->first);
		if (found) {
			*outNative = it->second;
			//LOG_DEBUG("outNative 0x%016llx", outNative);
			break;
		}
	}

	return found;

}

uint64_t CrossMapping::MapNative(uint64_t inNative)
{
	uint64_t currentNative, outNative;
	bool found = false;

	currentNative = inNative;
	found = searchMap(nativeCache, currentNative, &outNative);
	if (found) return outNative;
	found = searchMap(nativeHashMap, currentNative, &outNative);
	if (found) {
		nativeCache[inNative] = outNative;
		return outNative;
	}

	// Fail safe to prevent LOG_ERROR spam due to ontick run failed natives
	found = std::find(nativeFailedVec.begin(), nativeFailedVec.end(), inNative) != nativeFailedVec.end();
	if (found) {
		return NULL;
	}
	else nativeFailedVec.push_back(inNative);
	Log::Error("Failed to find new hash for 0x%p", inNative);
	return NULL;
}

void CrossMapping::dumpNativeMappingCache()
{
	FILE *file;
	int file_exists;
	char filename[0x400];
	snprintf(filename, sizeof(filename), "SudoHook_native_cache.log");
	/*first check if the file exists...*/
	fopen_s(&file, filename, "r");
	if (file == NULL) file_exists = 0;
	else { file_exists = 1; fclose(file); }

	/*...then open it in the appropriate way*/
	if (file_exists == 1)
	{
		fopen_s(&file, filename, "r+b");
	}
	else
	{
		fopen_s(&file, filename, "w+b");
	}

	if (file != NULL)
	{
		char buffer[50];
		for (nMap::const_iterator it = nativeCache.begin(); it != nativeCache.end(); ++it)
		{
			sprintf_s(buffer, "{ 0x%llx, 0x%llx },\n", it->first, it->second);
			fputs(buffer, file);
		}

		PlaySound(L"C:\\WINDOWS\\Media\\tada.wav", NULL, SND_ASYNC);

		fclose(file);
	}
}