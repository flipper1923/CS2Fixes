/* ************************************Admins chat**************************************************************
*/
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
	ClientPrint(player, HUD_PRINTTALK, " \7[To Admins] Message: \4%s \1, sent to \7Admins", args.ArgS());
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

	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS " \3%s \1You successfully reset your score.", player->GetPlayerName());
}

CON_COMMAND_CHAT(ws, "fake ws")
{
    if (!player)
        return;

    ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS "\3%s\1, Play 2h to have access to !ws.", player->GetPlayerName());
}

CON_COMMAND_CHAT(stats, "get your stats")
{
	if (!player)
		return;

	CSMatchStats_t *stats = &player->m_pActionTrackingServices->m_matchStats();

	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS"Kills: %d", stats->m_iKills.Get());
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS"Deaths: %d", stats->m_iDeaths.Get());
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS"Assists: %d", stats->m_iAssists.Get());
	ClientPrint(player, HUD_PRINTTALK, CHAT_PREFIXS"Damage: %d", stats->m_iDamage.Get());
}

CON_COMMAND_CHAT(say, "say something using console")
{
	ClientPrintAll(HUD_PRINTTALK, "%s", args.ArgS());
}
