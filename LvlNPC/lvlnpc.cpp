/////////////////////////////////////
//  LvlNPC v1.0
//  by VooDoo
//  http://www.wowemu.com.br
///////////////////////////////////////

#include "precompiled.h"
#include "../../../../shared/Config/Config.h"
#include "../../config.h"

bool GossipHello_LvlNPC(Player *player, Creature *_Creature)
{
	Config SD2Config; //Se pode acessar o SD2Config
	if(!SD2Config.SetSource(_SCRIPTDEV2_CONFIG,true))
		error_log("SD2: Unable to open configuration file");


        player->ADD_GOSSIP_ITEM( 5, "+1 lvl", GOSSIP_SENDER_MAIN, 1000);
        player->ADD_GOSSIP_ITEM( 5, "+5 lvl", GOSSIP_SENDER_MAIN, 1005);
        player->ADD_GOSSIP_ITEM( 5, "+10 lvl", GOSSIP_SENDER_MAIN, 1010);
        player->ADD_GOSSIP_ITEM( 5, "+40 lvl", GOSSIP_SENDER_MAIN, 1015);
        player->ADD_GOSSIP_ITEM( 5, "Resete para lvl 1", GOSSIP_SENDER_MAIN, 1020);



    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());

return true;
}

void SendDefaultMenu_LvlNPC(Player *player, Creature *_Creature, uint32 action )
{
	Config SD2Config;
	if(!SD2Config.SetSource(_SCRIPTDEV2_CONFIG,true))
		error_log("SD2: Unable to open configuration file");
	// -- Carrega os valores do SD2Config
	int levelMinimo = SD2Config.GetIntDefault("LvlNPC.Lxlmax",0);


// Chacagem de combate
if(!player->getAttackers().empty())
{
    player->CLOSE_GOSSIP_MENU();
    _Creature->MonsterWhisper("You are in combat!", LANG_UNIVERSAL, NULL);
	return;
}


switch(action)
{

    int lvl;

    case 1000:

        lvl = 1;

        if(player->getLevel()+lvl>levelMinimo);
        {
            player->MonsterWhisper("Seu lvl é muito alto para isso",LANG_UNIVERSAL, NULL);
            return true;
        }

        player->SetLevel(player->getLevel()+lvl);
        return true;


    case 1005:

        lvl = 5;

        if(player->getLevel()+lvl>levelMinimo);
        {
            player->MonsterWhisper("Seu lvl é muito alto para isso",LANG_UNIVERSAL, NULL);
            return true;
        }

        player->SetLevel(player->getLevel()+lvl);
        return true;


    case 1010:

        lvl = 10;

        if(player->getLevel()+lvl>levelMinimo);
        {
            player->MonsterWhisper("Seu lvl é muito alto para isso",LANG_UNIVERSAL, NULL);
            return true;
        }

        player->SetLevel(player->getLevel()+lvl);
        return true;


    case 1015:

        lvl = 40;

        if(player->getLevel()+lvl>levelMinimo);
        {
            player->MonsterWhisper("Seu lvl é muito alto para isso",LANG_UNIVERSAL, NULL);
            return true;
        }

        player->SetLevel(player->getLevel()+lvl);
        return true;


    case 1020:

        player->SetLevel(1);
        return true;

} // end of switch
return;
} //end of function



bool GossipSelect_LvlNPC(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
	// Main menu
	if (sender == GOSSIP_SENDER_MAIN)
	SendDefaultMenu_LvlNPC( player, _Creature, action );

return true;
}

void AddSC_lvlnpc()
{
    Script *newscript;
	newscript = new Script;
	newscript->Name="lvlnpc";
	newscript->pGossipHello = &GossipHello_LvlNPC;
	newscript->pGossipSelect = &GossipSelect_LvlNPC;
	newscript->RegisterSelf();
}
