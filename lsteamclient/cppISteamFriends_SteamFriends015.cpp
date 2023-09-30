/* This file is auto-generated, do not edit. */
#include "unix_private.h"
#include "cppISteamFriends_SteamFriends015.h"

struct u_ISteamFriends_SteamFriends015
{
#ifdef __cplusplus
    virtual const char * GetPersonaName(  ) = 0;
    virtual uint64_t SetPersonaName( const char * ) = 0;
    virtual uint32_t GetPersonaState(  ) = 0;
    virtual int32_t GetFriendCount( int32_t ) = 0;
    virtual CSteamID GetFriendByIndex( int32_t, int32_t ) = 0;
    virtual uint32_t GetFriendRelationship( CSteamID ) = 0;
    virtual uint32_t GetFriendPersonaState( CSteamID ) = 0;
    virtual const char * GetFriendPersonaName( CSteamID ) = 0;
    virtual bool GetFriendGamePlayed( CSteamID, FriendGameInfo_t * ) = 0;
    virtual const char * GetFriendPersonaNameHistory( CSteamID, int32_t ) = 0;
    virtual int32_t GetFriendSteamLevel( CSteamID ) = 0;
    virtual const char * GetPlayerNickname( CSteamID ) = 0;
    virtual int32_t GetFriendsGroupCount(  ) = 0;
    virtual int16_t GetFriendsGroupIDByIndex( int32_t ) = 0;
    virtual const char * GetFriendsGroupName( int16_t ) = 0;
    virtual int32_t GetFriendsGroupMembersCount( int16_t ) = 0;
    virtual void GetFriendsGroupMembersList( int16_t, CSteamID *, int32_t ) = 0;
    virtual bool HasFriend( CSteamID, int32_t ) = 0;
    virtual int32_t GetClanCount(  ) = 0;
    virtual CSteamID GetClanByIndex( int32_t ) = 0;
    virtual const char * GetClanName( CSteamID ) = 0;
    virtual const char * GetClanTag( CSteamID ) = 0;
    virtual bool GetClanActivityCounts( CSteamID, int32_t *, int32_t *, int32_t * ) = 0;
    virtual uint64_t DownloadClanActivityCounts( CSteamID *, int32_t ) = 0;
    virtual int32_t GetFriendCountFromSource( CSteamID ) = 0;
    virtual CSteamID GetFriendFromSourceByIndex( CSteamID, int32_t ) = 0;
    virtual bool IsUserInSource( CSteamID, CSteamID ) = 0;
    virtual void SetInGameVoiceSpeaking( CSteamID, bool ) = 0;
    virtual void ActivateGameOverlay( const char * ) = 0;
    virtual void ActivateGameOverlayToUser( const char *, CSteamID ) = 0;
    virtual void ActivateGameOverlayToWebPage( const char * ) = 0;
    virtual void ActivateGameOverlayToStore( uint32_t, uint32_t ) = 0;
    virtual void SetPlayedWith( CSteamID ) = 0;
    virtual void ActivateGameOverlayInviteDialog( CSteamID ) = 0;
    virtual int32_t GetSmallFriendAvatar( CSteamID ) = 0;
    virtual int32_t GetMediumFriendAvatar( CSteamID ) = 0;
    virtual int32_t GetLargeFriendAvatar( CSteamID ) = 0;
    virtual bool RequestUserInformation( CSteamID, bool ) = 0;
    virtual uint64_t RequestClanOfficerList( CSteamID ) = 0;
    virtual CSteamID GetClanOwner( CSteamID ) = 0;
    virtual int32_t GetClanOfficerCount( CSteamID ) = 0;
    virtual CSteamID GetClanOfficerByIndex( CSteamID, int32_t ) = 0;
    virtual uint32_t GetUserRestrictions(  ) = 0;
    virtual bool SetRichPresence( const char *, const char * ) = 0;
    virtual void ClearRichPresence(  ) = 0;
    virtual const char * GetFriendRichPresence( CSteamID, const char * ) = 0;
    virtual int32_t GetFriendRichPresenceKeyCount( CSteamID ) = 0;
    virtual const char * GetFriendRichPresenceKeyByIndex( CSteamID, int32_t ) = 0;
    virtual void RequestFriendRichPresence( CSteamID ) = 0;
    virtual bool InviteUserToGame( CSteamID, const char * ) = 0;
    virtual int32_t GetCoplayFriendCount(  ) = 0;
    virtual CSteamID GetCoplayFriend( int32_t ) = 0;
    virtual int32_t GetFriendCoplayTime( CSteamID ) = 0;
    virtual uint32_t GetFriendCoplayGame( CSteamID ) = 0;
    virtual uint64_t JoinClanChatRoom( CSteamID ) = 0;
    virtual bool LeaveClanChatRoom( CSteamID ) = 0;
    virtual int32_t GetClanChatMemberCount( CSteamID ) = 0;
    virtual CSteamID GetChatMemberByIndex( CSteamID, int32_t ) = 0;
    virtual bool SendClanChatMessage( CSteamID, const char * ) = 0;
    virtual int32_t GetClanChatMessage( CSteamID, int32_t, void *, int32_t, uint32_t *, CSteamID * ) = 0;
    virtual bool IsClanChatAdmin( CSteamID, CSteamID ) = 0;
    virtual bool IsClanChatWindowOpenInSteam( CSteamID ) = 0;
    virtual bool OpenClanChatWindowInSteam( CSteamID ) = 0;
    virtual bool CloseClanChatWindowInSteam( CSteamID ) = 0;
    virtual bool SetListenForFriendsMessages( bool ) = 0;
    virtual bool ReplyToFriendMessage( CSteamID, const char * ) = 0;
    virtual int32_t GetFriendMessage( CSteamID, int32_t, void *, int32_t, uint32_t * ) = 0;
    virtual uint64_t GetFollowerCount( CSteamID ) = 0;
    virtual uint64_t IsFollowing( CSteamID ) = 0;
    virtual uint64_t EnumerateFollowingList( uint32_t ) = 0;
    virtual bool IsClanPublic( CSteamID ) = 0;
    virtual bool IsClanOfficialGameGroup( CSteamID ) = 0;
#endif /* __cplusplus */
};

void cppISteamFriends_SteamFriends015_GetPersonaName( struct cppISteamFriends_SteamFriends015_GetPersonaName_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetPersonaName(  );
}

void cppISteamFriends_SteamFriends015_SetPersonaName( struct cppISteamFriends_SteamFriends015_SetPersonaName_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->SetPersonaName( params->pchPersonaName );
}

void cppISteamFriends_SteamFriends015_GetPersonaState( struct cppISteamFriends_SteamFriends015_GetPersonaState_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetPersonaState(  );
}

void cppISteamFriends_SteamFriends015_GetFriendCount( struct cppISteamFriends_SteamFriends015_GetFriendCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendCount( params->iFriendFlags );
}

void cppISteamFriends_SteamFriends015_GetFriendByIndex( struct cppISteamFriends_SteamFriends015_GetFriendByIndex_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    *params->_ret = iface->GetFriendByIndex( params->iFriend, params->iFriendFlags );
}

void cppISteamFriends_SteamFriends015_GetFriendRelationship( struct cppISteamFriends_SteamFriends015_GetFriendRelationship_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendRelationship( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetFriendPersonaState( struct cppISteamFriends_SteamFriends015_GetFriendPersonaState_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendPersonaState( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetFriendPersonaName( struct cppISteamFriends_SteamFriends015_GetFriendPersonaName_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendPersonaName( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetFriendGamePlayed( struct cppISteamFriends_SteamFriends015_GetFriendGamePlayed_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendGamePlayed( params->steamIDFriend, params->pFriendGameInfo );
}

void cppISteamFriends_SteamFriends015_GetFriendPersonaNameHistory( struct cppISteamFriends_SteamFriends015_GetFriendPersonaNameHistory_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendPersonaNameHistory( params->steamIDFriend, params->iPersonaName );
}

void cppISteamFriends_SteamFriends015_GetFriendSteamLevel( struct cppISteamFriends_SteamFriends015_GetFriendSteamLevel_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendSteamLevel( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetPlayerNickname( struct cppISteamFriends_SteamFriends015_GetPlayerNickname_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetPlayerNickname( params->steamIDPlayer );
}

void cppISteamFriends_SteamFriends015_GetFriendsGroupCount( struct cppISteamFriends_SteamFriends015_GetFriendsGroupCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendsGroupCount(  );
}

void cppISteamFriends_SteamFriends015_GetFriendsGroupIDByIndex( struct cppISteamFriends_SteamFriends015_GetFriendsGroupIDByIndex_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendsGroupIDByIndex( params->iFG );
}

void cppISteamFriends_SteamFriends015_GetFriendsGroupName( struct cppISteamFriends_SteamFriends015_GetFriendsGroupName_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendsGroupName( params->friendsGroupID );
}

void cppISteamFriends_SteamFriends015_GetFriendsGroupMembersCount( struct cppISteamFriends_SteamFriends015_GetFriendsGroupMembersCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendsGroupMembersCount( params->friendsGroupID );
}

void cppISteamFriends_SteamFriends015_GetFriendsGroupMembersList( struct cppISteamFriends_SteamFriends015_GetFriendsGroupMembersList_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->GetFriendsGroupMembersList( params->friendsGroupID, params->pOutSteamIDMembers, params->nMembersCount );
}

void cppISteamFriends_SteamFriends015_HasFriend( struct cppISteamFriends_SteamFriends015_HasFriend_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->HasFriend( params->steamIDFriend, params->iFriendFlags );
}

void cppISteamFriends_SteamFriends015_GetClanCount( struct cppISteamFriends_SteamFriends015_GetClanCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetClanCount(  );
}

void cppISteamFriends_SteamFriends015_GetClanByIndex( struct cppISteamFriends_SteamFriends015_GetClanByIndex_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    *params->_ret = iface->GetClanByIndex( params->iClan );
}

void cppISteamFriends_SteamFriends015_GetClanName( struct cppISteamFriends_SteamFriends015_GetClanName_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetClanName( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_GetClanTag( struct cppISteamFriends_SteamFriends015_GetClanTag_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetClanTag( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_GetClanActivityCounts( struct cppISteamFriends_SteamFriends015_GetClanActivityCounts_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetClanActivityCounts( params->steamIDClan, params->pnOnline, params->pnInGame, params->pnChatting );
}

void cppISteamFriends_SteamFriends015_DownloadClanActivityCounts( struct cppISteamFriends_SteamFriends015_DownloadClanActivityCounts_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->DownloadClanActivityCounts( params->psteamIDClans, params->cClansToRequest );
}

void cppISteamFriends_SteamFriends015_GetFriendCountFromSource( struct cppISteamFriends_SteamFriends015_GetFriendCountFromSource_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendCountFromSource( params->steamIDSource );
}

void cppISteamFriends_SteamFriends015_GetFriendFromSourceByIndex( struct cppISteamFriends_SteamFriends015_GetFriendFromSourceByIndex_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    *params->_ret = iface->GetFriendFromSourceByIndex( params->steamIDSource, params->iFriend );
}

void cppISteamFriends_SteamFriends015_IsUserInSource( struct cppISteamFriends_SteamFriends015_IsUserInSource_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->IsUserInSource( params->steamIDUser, params->steamIDSource );
}

void cppISteamFriends_SteamFriends015_SetInGameVoiceSpeaking( struct cppISteamFriends_SteamFriends015_SetInGameVoiceSpeaking_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->SetInGameVoiceSpeaking( params->steamIDUser, params->bSpeaking );
}

void cppISteamFriends_SteamFriends015_ActivateGameOverlay( struct cppISteamFriends_SteamFriends015_ActivateGameOverlay_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->ActivateGameOverlay( params->pchDialog );
}

void cppISteamFriends_SteamFriends015_ActivateGameOverlayToUser( struct cppISteamFriends_SteamFriends015_ActivateGameOverlayToUser_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->ActivateGameOverlayToUser( params->pchDialog, params->steamID );
}

void cppISteamFriends_SteamFriends015_ActivateGameOverlayToWebPage( struct cppISteamFriends_SteamFriends015_ActivateGameOverlayToWebPage_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->ActivateGameOverlayToWebPage( params->pchURL );
}

void cppISteamFriends_SteamFriends015_ActivateGameOverlayToStore( struct cppISteamFriends_SteamFriends015_ActivateGameOverlayToStore_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->ActivateGameOverlayToStore( params->nAppID, params->eFlag );
}

void cppISteamFriends_SteamFriends015_SetPlayedWith( struct cppISteamFriends_SteamFriends015_SetPlayedWith_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->SetPlayedWith( params->steamIDUserPlayedWith );
}

void cppISteamFriends_SteamFriends015_ActivateGameOverlayInviteDialog( struct cppISteamFriends_SteamFriends015_ActivateGameOverlayInviteDialog_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->ActivateGameOverlayInviteDialog( params->steamIDLobby );
}

void cppISteamFriends_SteamFriends015_GetSmallFriendAvatar( struct cppISteamFriends_SteamFriends015_GetSmallFriendAvatar_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetSmallFriendAvatar( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetMediumFriendAvatar( struct cppISteamFriends_SteamFriends015_GetMediumFriendAvatar_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetMediumFriendAvatar( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetLargeFriendAvatar( struct cppISteamFriends_SteamFriends015_GetLargeFriendAvatar_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetLargeFriendAvatar( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_RequestUserInformation( struct cppISteamFriends_SteamFriends015_RequestUserInformation_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->RequestUserInformation( params->steamIDUser, params->bRequireNameOnly );
}

void cppISteamFriends_SteamFriends015_RequestClanOfficerList( struct cppISteamFriends_SteamFriends015_RequestClanOfficerList_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->RequestClanOfficerList( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_GetClanOwner( struct cppISteamFriends_SteamFriends015_GetClanOwner_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    *params->_ret = iface->GetClanOwner( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_GetClanOfficerCount( struct cppISteamFriends_SteamFriends015_GetClanOfficerCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetClanOfficerCount( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_GetClanOfficerByIndex( struct cppISteamFriends_SteamFriends015_GetClanOfficerByIndex_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    *params->_ret = iface->GetClanOfficerByIndex( params->steamIDClan, params->iOfficer );
}

void cppISteamFriends_SteamFriends015_GetUserRestrictions( struct cppISteamFriends_SteamFriends015_GetUserRestrictions_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetUserRestrictions(  );
}

void cppISteamFriends_SteamFriends015_SetRichPresence( struct cppISteamFriends_SteamFriends015_SetRichPresence_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->SetRichPresence( params->pchKey, params->pchValue );
}

void cppISteamFriends_SteamFriends015_ClearRichPresence( struct cppISteamFriends_SteamFriends015_ClearRichPresence_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->ClearRichPresence(  );
}

void cppISteamFriends_SteamFriends015_GetFriendRichPresence( struct cppISteamFriends_SteamFriends015_GetFriendRichPresence_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendRichPresence( params->steamIDFriend, params->pchKey );
}

void cppISteamFriends_SteamFriends015_GetFriendRichPresenceKeyCount( struct cppISteamFriends_SteamFriends015_GetFriendRichPresenceKeyCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendRichPresenceKeyCount( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetFriendRichPresenceKeyByIndex( struct cppISteamFriends_SteamFriends015_GetFriendRichPresenceKeyByIndex_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendRichPresenceKeyByIndex( params->steamIDFriend, params->iKey );
}

void cppISteamFriends_SteamFriends015_RequestFriendRichPresence( struct cppISteamFriends_SteamFriends015_RequestFriendRichPresence_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    iface->RequestFriendRichPresence( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_InviteUserToGame( struct cppISteamFriends_SteamFriends015_InviteUserToGame_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->InviteUserToGame( params->steamIDFriend, params->pchConnectString );
}

void cppISteamFriends_SteamFriends015_GetCoplayFriendCount( struct cppISteamFriends_SteamFriends015_GetCoplayFriendCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetCoplayFriendCount(  );
}

void cppISteamFriends_SteamFriends015_GetCoplayFriend( struct cppISteamFriends_SteamFriends015_GetCoplayFriend_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    *params->_ret = iface->GetCoplayFriend( params->iCoplayFriend );
}

void cppISteamFriends_SteamFriends015_GetFriendCoplayTime( struct cppISteamFriends_SteamFriends015_GetFriendCoplayTime_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendCoplayTime( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_GetFriendCoplayGame( struct cppISteamFriends_SteamFriends015_GetFriendCoplayGame_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendCoplayGame( params->steamIDFriend );
}

void cppISteamFriends_SteamFriends015_JoinClanChatRoom( struct cppISteamFriends_SteamFriends015_JoinClanChatRoom_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->JoinClanChatRoom( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_LeaveClanChatRoom( struct cppISteamFriends_SteamFriends015_LeaveClanChatRoom_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->LeaveClanChatRoom( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_GetClanChatMemberCount( struct cppISteamFriends_SteamFriends015_GetClanChatMemberCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetClanChatMemberCount( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_GetChatMemberByIndex( struct cppISteamFriends_SteamFriends015_GetChatMemberByIndex_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    *params->_ret = iface->GetChatMemberByIndex( params->steamIDClan, params->iUser );
}

void cppISteamFriends_SteamFriends015_SendClanChatMessage( struct cppISteamFriends_SteamFriends015_SendClanChatMessage_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->SendClanChatMessage( params->steamIDClanChat, params->pchText );
}

void cppISteamFriends_SteamFriends015_GetClanChatMessage( struct cppISteamFriends_SteamFriends015_GetClanChatMessage_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetClanChatMessage( params->steamIDClanChat, params->iMessage, params->prgchText, params->cchTextMax, params->peChatEntryType, params->psteamidChatter );
}

void cppISteamFriends_SteamFriends015_IsClanChatAdmin( struct cppISteamFriends_SteamFriends015_IsClanChatAdmin_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->IsClanChatAdmin( params->steamIDClanChat, params->steamIDUser );
}

void cppISteamFriends_SteamFriends015_IsClanChatWindowOpenInSteam( struct cppISteamFriends_SteamFriends015_IsClanChatWindowOpenInSteam_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->IsClanChatWindowOpenInSteam( params->steamIDClanChat );
}

void cppISteamFriends_SteamFriends015_OpenClanChatWindowInSteam( struct cppISteamFriends_SteamFriends015_OpenClanChatWindowInSteam_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->OpenClanChatWindowInSteam( params->steamIDClanChat );
}

void cppISteamFriends_SteamFriends015_CloseClanChatWindowInSteam( struct cppISteamFriends_SteamFriends015_CloseClanChatWindowInSteam_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->CloseClanChatWindowInSteam( params->steamIDClanChat );
}

void cppISteamFriends_SteamFriends015_SetListenForFriendsMessages( struct cppISteamFriends_SteamFriends015_SetListenForFriendsMessages_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->SetListenForFriendsMessages( params->bInterceptEnabled );
}

void cppISteamFriends_SteamFriends015_ReplyToFriendMessage( struct cppISteamFriends_SteamFriends015_ReplyToFriendMessage_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->ReplyToFriendMessage( params->steamIDFriend, params->pchMsgToSend );
}

void cppISteamFriends_SteamFriends015_GetFriendMessage( struct cppISteamFriends_SteamFriends015_GetFriendMessage_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFriendMessage( params->steamIDFriend, params->iMessageID, params->pvData, params->cubData, params->peChatEntryType );
}

void cppISteamFriends_SteamFriends015_GetFollowerCount( struct cppISteamFriends_SteamFriends015_GetFollowerCount_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->GetFollowerCount( params->steamID );
}

void cppISteamFriends_SteamFriends015_IsFollowing( struct cppISteamFriends_SteamFriends015_IsFollowing_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->IsFollowing( params->steamID );
}

void cppISteamFriends_SteamFriends015_EnumerateFollowingList( struct cppISteamFriends_SteamFriends015_EnumerateFollowingList_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->EnumerateFollowingList( params->unStartIndex );
}

void cppISteamFriends_SteamFriends015_IsClanPublic( struct cppISteamFriends_SteamFriends015_IsClanPublic_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->IsClanPublic( params->steamIDClan );
}

void cppISteamFriends_SteamFriends015_IsClanOfficialGameGroup( struct cppISteamFriends_SteamFriends015_IsClanOfficialGameGroup_params *params )
{
    struct u_ISteamFriends_SteamFriends015 *iface = (struct u_ISteamFriends_SteamFriends015 *)params->linux_side;
    params->_ret = iface->IsClanOfficialGameGroup( params->steamIDClan );
}

