/* This file is auto-generated, do not edit. */
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketIP_params
{
    void *linux_side;
    uint32_t _ret;
    const SteamNetworkingIPAddr *localAddress;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketIP( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketIP_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectByIPAddress_params
{
    void *linux_side;
    uint32_t _ret;
    const SteamNetworkingIPAddr *address;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectByIPAddress( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectByIPAddress_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketP2P_params
{
    void *linux_side;
    uint32_t _ret;
    int32_t nLocalVirtualPort;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketP2P( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketP2P_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectP2P_params
{
    void *linux_side;
    uint32_t _ret;
    const SteamNetworkingIdentity_144 *identityRemote;
    int32_t nRemoteVirtualPort;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectP2P( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectP2P_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_AcceptConnection_params
{
    void *linux_side;
    uint32_t _ret;
    uint32_t hConn;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_AcceptConnection( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_AcceptConnection_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CloseConnection_params
{
    void *linux_side;
    bool _ret;
    uint32_t hPeer;
    int32_t nReason;
    const char *pszDebug;
    bool bEnableLinger;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CloseConnection( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CloseConnection_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CloseListenSocket_params
{
    void *linux_side;
    bool _ret;
    uint32_t hSocket;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CloseListenSocket( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CloseListenSocket_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionUserData_params
{
    void *linux_side;
    bool _ret;
    uint32_t hPeer;
    int64_t nUserData;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionUserData( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionUserData_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionUserData_params
{
    void *linux_side;
    int64_t _ret;
    uint32_t hPeer;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionUserData( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionUserData_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionName_params
{
    void *linux_side;
    uint32_t hPeer;
    const char *pszName;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionName( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionName_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionName_params
{
    void *linux_side;
    bool _ret;
    uint32_t hPeer;
    char *pszName;
    int32_t nMaxLen;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionName( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionName_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SendMessageToConnection_params
{
    void *linux_side;
    uint32_t _ret;
    uint32_t hConn;
    const void *pData;
    uint32_t cbData;
    int32_t nSendFlags;
    int64_t *pOutMessageNumber;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_SendMessageToConnection( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SendMessageToConnection_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SendMessages_params
{
    void *linux_side;
    int32_t nMessages;
    w_SteamNetworkingMessage_t_153a *const *pMessages;
    int64_t *pOutMessageNumberOrResult;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_SendMessages( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SendMessages_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_FlushMessagesOnConnection_params
{
    void *linux_side;
    uint32_t _ret;
    uint32_t hConn;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_FlushMessagesOnConnection( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_FlushMessagesOnConnection_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnConnection_params
{
    void *linux_side;
    int32_t _ret;
    uint32_t hConn;
    w_SteamNetworkingMessage_t_153a **ppOutMessages;
    int32_t nMaxMessages;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnConnection( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnConnection_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionInfo_params
{
    void *linux_side;
    bool _ret;
    uint32_t hConn;
    SteamNetConnectionInfo_t_153a *pInfo;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionInfo( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionInfo_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionRealTimeStatus_params
{
    void *linux_side;
    uint32_t _ret;
    uint32_t hConn;
    SteamNetConnectionRealTimeStatus_t *pStatus;
    int32_t nLanes;
    SteamNetConnectionRealTimeLaneStatus_t *pLanes;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionRealTimeStatus( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetConnectionRealTimeStatus_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetDetailedConnectionStatus_params
{
    void *linux_side;
    int32_t _ret;
    uint32_t hConn;
    char *pszBuf;
    int32_t cbBuf;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetDetailedConnectionStatus( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetDetailedConnectionStatus_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetListenSocketAddress_params
{
    void *linux_side;
    bool _ret;
    uint32_t hSocket;
    SteamNetworkingIPAddr *address;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetListenSocketAddress( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetListenSocketAddress_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateSocketPair_params
{
    void *linux_side;
    bool _ret;
    uint32_t *pOutConnection1;
    uint32_t *pOutConnection2;
    bool bUseNetworkLoopback;
    const SteamNetworkingIdentity_144 *pIdentity1;
    const SteamNetworkingIdentity_144 *pIdentity2;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateSocketPair( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateSocketPair_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConfigureConnectionLanes_params
{
    void *linux_side;
    uint32_t _ret;
    uint32_t hConn;
    int32_t nNumLanes;
    const int32_t *pLanePriorities;
    const uint16_t *pLaneWeights;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ConfigureConnectionLanes( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConfigureConnectionLanes_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetIdentity_params
{
    void *linux_side;
    bool _ret;
    SteamNetworkingIdentity_144 *pIdentity;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetIdentity( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetIdentity_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_InitAuthentication_params
{
    void *linux_side;
    uint32_t _ret;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_InitAuthentication( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_InitAuthentication_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetAuthenticationStatus_params
{
    void *linux_side;
    uint32_t _ret;
    SteamNetAuthenticationStatus_t *pDetails;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetAuthenticationStatus( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetAuthenticationStatus_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreatePollGroup_params
{
    void *linux_side;
    uint32_t _ret;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CreatePollGroup( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreatePollGroup_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_DestroyPollGroup_params
{
    void *linux_side;
    bool _ret;
    uint32_t hPollGroup;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_DestroyPollGroup( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_DestroyPollGroup_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionPollGroup_params
{
    void *linux_side;
    bool _ret;
    uint32_t hConn;
    uint32_t hPollGroup;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionPollGroup( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetConnectionPollGroup_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnPollGroup_params
{
    void *linux_side;
    int32_t _ret;
    uint32_t hPollGroup;
    w_SteamNetworkingMessage_t_153a **ppOutMessages;
    int32_t nMaxMessages;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnPollGroup( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnPollGroup_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceivedRelayAuthTicket_params
{
    void *linux_side;
    bool _ret;
    const void *pvTicket;
    int32_t cbTicket;
    SteamDatagramRelayAuthTicket *pOutParsedTicket;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceivedRelayAuthTicket( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceivedRelayAuthTicket_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_FindRelayAuthTicketForServer_params
{
    void *linux_side;
    int32_t _ret;
    const SteamNetworkingIdentity_144 *identityGameServer;
    int32_t nRemoteVirtualPort;
    SteamDatagramRelayAuthTicket *pOutParsedTicket;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_FindRelayAuthTicketForServer( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_FindRelayAuthTicketForServer_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectToHostedDedicatedServer_params
{
    void *linux_side;
    uint32_t _ret;
    const SteamNetworkingIdentity_144 *identityTarget;
    int32_t nRemoteVirtualPort;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectToHostedDedicatedServer( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectToHostedDedicatedServer_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerPort_params
{
    void *linux_side;
    uint16_t _ret;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerPort( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerPort_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerPOPID_params
{
    void *linux_side;
    uint32_t _ret;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerPOPID( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerPOPID_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerAddress_params
{
    void *linux_side;
    uint32_t _ret;
    SteamDatagramHostedAddress *pRouting;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerAddress( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetHostedDedicatedServerAddress_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateHostedDedicatedServerListenSocket_params
{
    void *linux_side;
    uint32_t _ret;
    int32_t nLocalVirtualPort;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateHostedDedicatedServerListenSocket( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateHostedDedicatedServerListenSocket_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetGameCoordinatorServerLogin_params
{
    void *linux_side;
    uint32_t _ret;
    SteamDatagramGameCoordinatorServerLogin *pLoginInfo;
    int32_t *pcbSignedBlob;
    void *pBlob;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetGameCoordinatorServerLogin( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetGameCoordinatorServerLogin_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectP2PCustomSignaling_params
{
    void *linux_side;
    uint32_t _ret;
    void /*ISteamNetworkingConnectionSignaling*/ *pSignaling;
    const SteamNetworkingIdentity_144 *pPeerIdentity;
    int32_t nRemoteVirtualPort;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectP2PCustomSignaling( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ConnectP2PCustomSignaling_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceivedP2PCustomSignal_params
{
    void *linux_side;
    bool _ret;
    const void *pMsg;
    int32_t cbMsg;
    void /*ISteamNetworkingSignalingRecvContext*/ *pContext;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceivedP2PCustomSignal( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ReceivedP2PCustomSignal_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetCertificateRequest_params
{
    void *linux_side;
    bool _ret;
    int32_t *pcbBlob;
    void *pBlob;
    char (*errMsg)[1024];
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetCertificateRequest( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetCertificateRequest_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetCertificate_params
{
    void *linux_side;
    bool _ret;
    const void *pCertificate;
    int32_t cbCertificate;
    char (*errMsg)[1024];
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_SetCertificate( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_SetCertificate_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ResetIdentity_params
{
    void *linux_side;
    const SteamNetworkingIdentity_144 *pIdentity;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_ResetIdentity( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_ResetIdentity_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_RunCallbacks_params
{
    void *linux_side;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_RunCallbacks( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_RunCallbacks_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_BeginAsyncRequestFakeIP_params
{
    void *linux_side;
    bool _ret;
    int32_t nNumPorts;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_BeginAsyncRequestFakeIP( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_BeginAsyncRequestFakeIP_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetFakeIP_params
{
    void *linux_side;
    int32_t idxFirstPort;
    SteamNetworkingFakeIPResult_t *pInfo;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetFakeIP( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetFakeIP_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketP2PFakeIP_params
{
    void *linux_side;
    uint32_t _ret;
    int32_t idxFakePort;
    int32_t nOptions;
    const SteamNetworkingConfigValue_t *pOptions;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketP2PFakeIP( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateListenSocketP2PFakeIP_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetRemoteFakeIPForConnection_params
{
    void *linux_side;
    uint32_t _ret;
    uint32_t hConn;
    SteamNetworkingIPAddr *pOutAddr;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_GetRemoteFakeIPForConnection( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_GetRemoteFakeIPForConnection_params *params );

struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateFakeUDPPort_params
{
    void *linux_side;
    void /*ISteamNetworkingFakeUDPPort*/ *_ret;
    int32_t idxFakeServerPort;
};
extern void cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateFakeUDPPort( struct cppISteamNetworkingSockets_SteamNetworkingSockets012_CreateFakeUDPPort_params *params );

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
