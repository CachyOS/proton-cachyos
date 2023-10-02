/* This file is auto-generated, do not edit. */
#include "unix_private.h"

NTSTATUS ISteamUtils_SteamUtils007_GetSecondsSinceAppActive( void *args )
{
    struct ISteamUtils_SteamUtils007_GetSecondsSinceAppActive_params *params = (struct ISteamUtils_SteamUtils007_GetSecondsSinceAppActive_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetSecondsSinceAppActive(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetSecondsSinceComputerActive( void *args )
{
    struct ISteamUtils_SteamUtils007_GetSecondsSinceComputerActive_params *params = (struct ISteamUtils_SteamUtils007_GetSecondsSinceComputerActive_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetSecondsSinceComputerActive(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetConnectedUniverse( void *args )
{
    struct ISteamUtils_SteamUtils007_GetConnectedUniverse_params *params = (struct ISteamUtils_SteamUtils007_GetConnectedUniverse_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetConnectedUniverse(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetServerRealTime( void *args )
{
    struct ISteamUtils_SteamUtils007_GetServerRealTime_params *params = (struct ISteamUtils_SteamUtils007_GetServerRealTime_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetServerRealTime(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetIPCountry( void *args )
{
    struct ISteamUtils_SteamUtils007_GetIPCountry_params *params = (struct ISteamUtils_SteamUtils007_GetIPCountry_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetIPCountry(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetImageSize( void *args )
{
    struct ISteamUtils_SteamUtils007_GetImageSize_params *params = (struct ISteamUtils_SteamUtils007_GetImageSize_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetImageSize( params->iImage, params->pnWidth, params->pnHeight );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetImageRGBA( void *args )
{
    struct ISteamUtils_SteamUtils007_GetImageRGBA_params *params = (struct ISteamUtils_SteamUtils007_GetImageRGBA_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetImageRGBA( params->iImage, params->pubDest, params->nDestBufferSize );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetCSERIPPort( void *args )
{
    struct ISteamUtils_SteamUtils007_GetCSERIPPort_params *params = (struct ISteamUtils_SteamUtils007_GetCSERIPPort_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetCSERIPPort( params->unIP, params->usPort );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetCurrentBatteryPower( void *args )
{
    struct ISteamUtils_SteamUtils007_GetCurrentBatteryPower_params *params = (struct ISteamUtils_SteamUtils007_GetCurrentBatteryPower_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetCurrentBatteryPower(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetAppID( void *args )
{
    struct ISteamUtils_SteamUtils007_GetAppID_params *params = (struct ISteamUtils_SteamUtils007_GetAppID_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetAppID(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_SetOverlayNotificationPosition( void *args )
{
    struct ISteamUtils_SteamUtils007_SetOverlayNotificationPosition_params *params = (struct ISteamUtils_SteamUtils007_SetOverlayNotificationPosition_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    iface->SetOverlayNotificationPosition( params->eNotificationPosition );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_IsAPICallCompleted( void *args )
{
    struct ISteamUtils_SteamUtils007_IsAPICallCompleted_params *params = (struct ISteamUtils_SteamUtils007_IsAPICallCompleted_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->IsAPICallCompleted( params->hSteamAPICall, params->pbFailed );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetAPICallFailureReason( void *args )
{
    struct ISteamUtils_SteamUtils007_GetAPICallFailureReason_params *params = (struct ISteamUtils_SteamUtils007_GetAPICallFailureReason_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetAPICallFailureReason( params->hSteamAPICall );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_RunFrame( void *args )
{
    struct ISteamUtils_SteamUtils007_RunFrame_params *params = (struct ISteamUtils_SteamUtils007_RunFrame_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    iface->RunFrame(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetIPCCallCount( void *args )
{
    struct ISteamUtils_SteamUtils007_GetIPCCallCount_params *params = (struct ISteamUtils_SteamUtils007_GetIPCCallCount_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetIPCCallCount(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_SetWarningMessageHook( void *args )
{
    struct ISteamUtils_SteamUtils007_SetWarningMessageHook_params *params = (struct ISteamUtils_SteamUtils007_SetWarningMessageHook_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    void (*U_CDECL u_pFunction)(int32_t, const char *) = manual_convert_SetWarningMessageHook_pFunction( params->pFunction );
    iface->SetWarningMessageHook( u_pFunction );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_IsOverlayEnabled( void *args )
{
    struct ISteamUtils_SteamUtils007_IsOverlayEnabled_params *params = (struct ISteamUtils_SteamUtils007_IsOverlayEnabled_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->IsOverlayEnabled(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_BOverlayNeedsPresent( void *args )
{
    struct ISteamUtils_SteamUtils007_BOverlayNeedsPresent_params *params = (struct ISteamUtils_SteamUtils007_BOverlayNeedsPresent_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->BOverlayNeedsPresent(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_CheckFileSignature( void *args )
{
    struct ISteamUtils_SteamUtils007_CheckFileSignature_params *params = (struct ISteamUtils_SteamUtils007_CheckFileSignature_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->CheckFileSignature( params->szFileName );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_ShowGamepadTextInput( void *args )
{
    struct ISteamUtils_SteamUtils007_ShowGamepadTextInput_params *params = (struct ISteamUtils_SteamUtils007_ShowGamepadTextInput_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->ShowGamepadTextInput( params->eInputMode, params->eLineInputMode, params->pchDescription, params->unCharMax, params->pchExistingText );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetEnteredGamepadTextLength( void *args )
{
    struct ISteamUtils_SteamUtils007_GetEnteredGamepadTextLength_params *params = (struct ISteamUtils_SteamUtils007_GetEnteredGamepadTextLength_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetEnteredGamepadTextLength(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetEnteredGamepadTextInput( void *args )
{
    struct ISteamUtils_SteamUtils007_GetEnteredGamepadTextInput_params *params = (struct ISteamUtils_SteamUtils007_GetEnteredGamepadTextInput_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetEnteredGamepadTextInput( params->pchText, params->cchText );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_GetSteamUILanguage( void *args )
{
    struct ISteamUtils_SteamUtils007_GetSteamUILanguage_params *params = (struct ISteamUtils_SteamUtils007_GetSteamUILanguage_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->GetSteamUILanguage(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_IsSteamRunningInVR( void *args )
{
    struct ISteamUtils_SteamUtils007_IsSteamRunningInVR_params *params = (struct ISteamUtils_SteamUtils007_IsSteamRunningInVR_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    params->_ret = iface->IsSteamRunningInVR(  );
    return 0;
}

NTSTATUS ISteamUtils_SteamUtils007_SetOverlayNotificationInset( void *args )
{
    struct ISteamUtils_SteamUtils007_SetOverlayNotificationInset_params *params = (struct ISteamUtils_SteamUtils007_SetOverlayNotificationInset_params *)args;
    struct u_ISteamUtils_SteamUtils007 *iface = (struct u_ISteamUtils_SteamUtils007 *)params->linux_side;
    iface->SetOverlayNotificationInset( params->nHorizontalInset, params->nVerticalInset );
    return 0;
}
