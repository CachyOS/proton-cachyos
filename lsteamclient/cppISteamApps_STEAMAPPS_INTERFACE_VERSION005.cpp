#include "steam_defs.h"
#pragma push_macro("__cdecl")
#undef __cdecl
#define __cdecl
#include "steamworks_sdk_125/steam_api.h"
#pragma pop_macro("__cdecl")
#include "steamclient_private.h"
#ifdef __cplusplus
extern "C" {
#endif
#define SDKVER_125
#include "struct_converters.h"
#include "cppISteamApps_STEAMAPPS_INTERFACE_VERSION005.h"
bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsSubscribed(void *linux_side)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsSubscribed();
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsLowViolence(void *linux_side)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsLowViolence();
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsCybercafe(void *linux_side)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsCybercafe();
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsVACBanned(void *linux_side)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsVACBanned();
    return (_ret);
}

const char * cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_GetCurrentGameLanguage(void *linux_side)
{
    const char * _ret;
    _ret = ((ISteamApps*)linux_side)->GetCurrentGameLanguage();
    return (_ret);
}

const char * cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_GetAvailableGameLanguages(void *linux_side)
{
    const char * _ret;
    _ret = ((ISteamApps*)linux_side)->GetAvailableGameLanguages();
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsSubscribedApp(void *linux_side, AppId_t appID)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsSubscribedApp((AppId_t)appID);
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsDlcInstalled(void *linux_side, AppId_t appID)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsDlcInstalled((AppId_t)appID);
    return (_ret);
}

uint32 cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_GetEarliestPurchaseUnixTime(void *linux_side, AppId_t nAppID)
{
    uint32 _ret;
    _ret = ((ISteamApps*)linux_side)->GetEarliestPurchaseUnixTime((AppId_t)nAppID);
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsSubscribedFromFreeWeekend(void *linux_side)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsSubscribedFromFreeWeekend();
    return (_ret);
}

int cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_GetDLCCount(void *linux_side)
{
    int _ret;
    _ret = ((ISteamApps*)linux_side)->GetDLCCount();
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BGetDLCDataByIndex(void *linux_side, int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BGetDLCDataByIndex((int)iDLC, (AppId_t *)pAppID, (bool *)pbAvailable, (char *)pchName, (int)cchNameBufferSize);
    return (_ret);
}

void cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_InstallDLC(void *linux_side, AppId_t nAppID)
{
    ((ISteamApps*)linux_side)->InstallDLC((AppId_t)nAppID);
}

void cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_UninstallDLC(void *linux_side, AppId_t nAppID)
{
    ((ISteamApps*)linux_side)->UninstallDLC((AppId_t)nAppID);
}

void cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_RequestAppProofOfPurchaseKey(void *linux_side, AppId_t nAppID)
{
    ((ISteamApps*)linux_side)->RequestAppProofOfPurchaseKey((AppId_t)nAppID);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_GetCurrentBetaName(void *linux_side, char *pchName, int cchNameBufferSize)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->GetCurrentBetaName((char *)pchName, (int)cchNameBufferSize);
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_MarkContentCorrupt(void *linux_side, bool bMissingFilesOnly)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->MarkContentCorrupt((bool)bMissingFilesOnly);
    return (_ret);
}

uint32 cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_GetInstalledDepots(void *linux_side, DepotId_t *pvecDepots, uint32 cMaxDepots)
{
    uint32 _ret;
    _ret = ((ISteamApps*)linux_side)->GetInstalledDepots((DepotId_t *)pvecDepots, (uint32)cMaxDepots);
    return (_ret);
}

uint32 cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_GetAppInstallDir(void *linux_side, AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize)
{
    uint32 _ret;
    _ret = ((ISteamApps*)linux_side)->GetAppInstallDir((AppId_t)appID, (char *)pchFolder, (uint32)cchFolderBufferSize);
    return (_ret);
}

bool cppISteamApps_STEAMAPPS_INTERFACE_VERSION005_BIsAppInstalled(void *linux_side, AppId_t appID)
{
    bool _ret;
    _ret = ((ISteamApps*)linux_side)->BIsAppInstalled((AppId_t)appID);
    return (_ret);
}

#ifdef __cplusplus
}
#endif
