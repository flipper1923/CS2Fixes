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