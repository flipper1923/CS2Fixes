//************************************Admins chat**************************************************************

CON_COMMAND_CHAT(u, "admins chat")
{
    if (!player)
        return;

    int iCommandPlayer = player->GetPlayerSlot();

    ZEPlayer *pPlayer = g_playerManager->GetPlayer(iCommandPlayer);
    if (args.ArgC() < 2)
    {
        
        ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIX "Usage: /u <message> to admins");
        return;
    }
	
for (int i = 0; i < MAXPLAYERS; i++)
	{
    ZEPlayer* pAdmin = g_playerManager->GetPlayer(i);
    CBasePlayerController* cPlayer = (CBasePlayerController*)g_pEntitySystem->GetBaseEntity((CEntityIndex)(i + 1));

    if (!cPlayer || !pAdmin || pAdmin->IsFakeClient() || !pAdmin->IsAdminFlagSet(ADMFLAG_SLAY))
        continue;
        ClientPrint(cPlayer, HUD_PRINTTALK," \3*************\14Admins Chat\3*************");
        ClientPrint(cPlayer, HUD_PRINTTALK, " \7[Admins]\4 %s \1from \7%s ", args.ArgS(), player->GetPlayerName());
        ClientPrint(cPlayer, HUD_PRINTTALK, " \3**************************************");
	}
	//ClientPrint(cPlayer, HUD_PRINTTALK, " \7[To Admins] \4%s \1, message sent to \7Admins", args.ArgS());
	ClientPrint(player, HUD_PRINTTALK, " \7[To Admins] \4%s \1, message sent to \7Admins", args.ArgS());
}
//***************************************************Reset Score***********************************************
CON_COMMAND_CHAT(rs, "reset your score")
{
	if (!player)
		return;
	
	player->m_pActionTrackingServices->m_matchStats().m_iKills = 0;
	player->m_pActionTrackingServices->m_matchStats().m_iDeaths = 0;
	player->m_pActionTrackingServices->m_matchStats().m_iAssists = 0;
	player->m_pActionTrackingServices->m_matchStats().m_iDamage = 0;
	player->m_iScore = 0;
	player->m_iMVPs = 0;

	ClientPrint(player, HUD_PRINTTALK, " \7[Reset Score]\1 You successfully reset your score.");
}
CON_COMMAND_CHAT(RS, "reset your score")
{
	if (!player)
		return;
	
	player->m_pActionTrackingServices->m_matchStats().m_iKills = 0;
	player->m_pActionTrackingServices->m_matchStats().m_iDeaths = 0;
	player->m_pActionTrackingServices->m_matchStats().m_iAssists = 0;
	player->m_pActionTrackingServices->m_matchStats().m_iDamage = 0;
	player->m_iScore = 0;
	player->m_iMVPs = 0;

	ClientPrint(player, HUD_PRINTTALK, " \7[Reset Score]\1 You successfully reset your score.");
}
//************************************end reset**************************************************************
CON_COMMAND_CHAT(ws, "fake ws")
{
    if (!player)
        return;

    ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS "\3%s\1, Play 2h to have access to !ws.", player->GetPlayerName());
}
CON_COMMAND_CHAT(help, "help")
{
		if (!player)
		return;
ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS "Use commands: !medic, !rs,!RS, !sound, !stats, !vip, !stats, /u(admins chat)");
}
CON_COMMAND_CHAT(vip, "vip info")
{
	if (!player)
		return;

	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXV"\1Starting health: \5 100-115.");
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXV"\1Starting armor: \5 110-200.");
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXV"\1Money add every round: \5 1000-5000.");
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXV"\1Starting with: \5 defeuser, he, smoke, molotov, flashbang, healthshot .");
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXV"\1Smoke color: \5 green, \14blue, \7red, \2r\4a\3n\5d\6o\7m.");
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXV"\1For buying VIP, contact \7FOUNDER.");
}