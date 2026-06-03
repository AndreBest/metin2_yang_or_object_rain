// search :

const float c_fDropStartHeight = 100.0f;
const float c_fDropTime = 0.5f;

// add under :

#ifdef YANG_RAIN
const DWORD c_dwYangRainVnum  = 2;			// hardcoded vnum because I am retarded
const float c_fYangRainHeight = 2500.0f;	// fall height
const DWORD c_dwYangRainTime  = 1800;		// fall duration
#endif

// in CPythonItem::TGroundItemInstance::Update search : 

v3NewPosition.z += 100-100*rate*(3*rate-2);

// modify :

#ifdef YANG_RAIN
		if (bYangRain)
			v3NewPosition.z += fDropStartHeight*(1.0f - rate*rate);
		else
			v3NewPosition.z += 100-100*rate*(3*rate-2);
#else
		v3NewPosition.z += 100-100*rate*(3*rate-2);
#endif

// in CPythonItem::CreateItem search :

CItemData * pItemData;

// add under :

#ifdef YANG_RAIN
	bool bYangRain = (dwVirtualNumber == c_dwYangRainVnum);
	if (bYangRain)
		dwVirtualNumber = VNUM_MONEY;
#endif

// same function search : 
pGroundItemInstance->dwVirtualNumber = dwVirtualNumber;

// add under :
#ifdef YANG_RAIN
	pGroundItemInstance->bYangRain = bYangRain;
	pGroundItemInstance->fDropStartHeight = c_fDropStartHeight;	// default
#endif

// same function search :

pGroundItemInstance->dwEndTime = pGroundItemInstance->dwStartTime + 300;

// replace with :

#ifdef YANG_RAIN
		if (pGroundItemInstance->bYangRain)
		{
			pGroundItemInstance->fDropStartHeight = c_fYangRainHeight;
			pGroundItemInstance->dwEndTime = pGroundItemInstance->dwStartTime + c_dwYangRainTime;
		}
		else
#endif
		{
			pGroundItemInstance->dwEndTime = pGroundItemInstance->dwStartTime + 300;
		}