/* This file is auto-generated, do not edit. */
#include "unix_private.h"
#include "cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION.h"

struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION
{
#ifdef __cplusplus
    virtual bool Init( const char * ) = 0;
    virtual bool Shutdown(  ) = 0;
    virtual void RunFrame(  ) = 0;
    virtual bool GetControllerState( uint32_t, SteamControllerState001_t * ) = 0;
    virtual void TriggerHapticPulse( uint32_t, uint32_t, uint16_t ) = 0;
    virtual void SetOverrideMode( const char * ) = 0;
#endif /* __cplusplus */
};

void cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_Init( struct cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_Init_params *params )
{
    struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *iface = (struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *)params->linux_side;
    params->_ret = iface->Init( params->pchAbsolutePathToControllerConfigVDF );
}

void cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_Shutdown( struct cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_Shutdown_params *params )
{
    struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *iface = (struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *)params->linux_side;
    params->_ret = iface->Shutdown(  );
}

void cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_RunFrame( struct cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_RunFrame_params *params )
{
    struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *iface = (struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *)params->linux_side;
    iface->RunFrame(  );
}

void cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_GetControllerState( struct cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_GetControllerState_params *params )
{
    struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *iface = (struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *)params->linux_side;
    params->_ret = iface->GetControllerState( params->unControllerIndex, params->pState );
}

void cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_TriggerHapticPulse( struct cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_TriggerHapticPulse_params *params )
{
    struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *iface = (struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *)params->linux_side;
    iface->TriggerHapticPulse( params->unControllerIndex, params->eTargetPad, params->usDurationMicroSec );
}

void cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_SetOverrideMode( struct cppISteamController_STEAMCONTROLLER_INTERFACE_VERSION_SetOverrideMode_params *params )
{
    struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *iface = (struct u_ISteamController_STEAMCONTROLLER_INTERFACE_VERSION *)params->linux_side;
    iface->SetOverrideMode( params->pchMode );
}

