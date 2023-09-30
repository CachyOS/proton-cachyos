/* This file is auto-generated, do not edit. */
#include "unix_private.h"
#include "cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003.h"

struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003
{
#ifdef __cplusplus
    virtual uint32_t WriteScreenshot( void *, uint32_t, int32_t, int32_t ) = 0;
    virtual uint32_t AddScreenshotToLibrary( const char *, const char *, int32_t, int32_t ) = 0;
    virtual void TriggerScreenshot(  ) = 0;
    virtual void HookScreenshots( bool ) = 0;
    virtual bool SetLocation( uint32_t, const char * ) = 0;
    virtual bool TagUser( uint32_t, CSteamID ) = 0;
    virtual bool TagPublishedFile( uint32_t, uint64_t ) = 0;
    virtual bool IsScreenshotsHooked(  ) = 0;
    virtual uint32_t AddVRScreenshotToLibrary( uint32_t, const char *, const char * ) = 0;
#endif /* __cplusplus */
};

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_WriteScreenshot( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_WriteScreenshot_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    params->_ret = iface->WriteScreenshot( params->pubRGB, params->cubRGB, params->nWidth, params->nHeight );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_AddScreenshotToLibrary( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_AddScreenshotToLibrary_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    params->_ret = iface->AddScreenshotToLibrary( params->pchFilename, params->pchThumbnailFilename, params->nWidth, params->nHeight );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_TriggerScreenshot( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_TriggerScreenshot_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    iface->TriggerScreenshot(  );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_HookScreenshots( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_HookScreenshots_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    iface->HookScreenshots( params->bHook );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_SetLocation( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_SetLocation_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    params->_ret = iface->SetLocation( params->hScreenshot, params->pchLocation );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_TagUser( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_TagUser_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    params->_ret = iface->TagUser( params->hScreenshot, params->steamID );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_TagPublishedFile( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_TagPublishedFile_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    params->_ret = iface->TagPublishedFile( params->hScreenshot, params->unPublishedFileID );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_IsScreenshotsHooked( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_IsScreenshotsHooked_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    params->_ret = iface->IsScreenshotsHooked(  );
}

void cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_AddVRScreenshotToLibrary( struct cppISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003_AddVRScreenshotToLibrary_params *params )
{
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION003 *)params->linux_side;
    params->_ret = iface->AddVRScreenshotToLibrary( params->eType, params->pchFilename, params->pchVRFilename );
}

