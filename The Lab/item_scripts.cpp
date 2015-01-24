/**
 * ScriptDev2 is an extension for mangos providing enhanced features for
 * area triggers, creatures, game objects, instances, items, and spells beyond
 * the default database scripting in mangos.
 *
 * Copyright (C) 2006-2013  ScriptDev2 <http://www.scriptdev2.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

/**
 * ScriptData
 * SDName:      Item_Scripts
 * SD%Complete: 0
 * SDComment:   Placeholder
 * SDCategory:  Items
 * EndScriptData
 */

/**
 * ContentData
 * EndContentData
 */

#include "precompiled.h"

enum
{
    SAY_HI = -1999925
};

bool ItemUse_item_martin_fury(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    DoScriptText(SAY_HI, pPlayer);
    DEBUG_LOG("Using SHIRT !!!!!!!!!!!");
    DEBUG_LOG("Using SHIRT !!!!!!!!!!!");
    DEBUG_LOG("Using SHIRT !!!!!!!!!!!");
    DEBUG_LOG("Using SHIRT !!!!!!!!!!!");
    DEBUG_LOG("Using SHIRT !!!!!!!!!!!");
    DEBUG_LOG("Using SHIRT !!!!!!!!!!!");

    // KILL EVERYTHING!!!
    // ==================
    
    // iterate through all nearby creatures
    GuidList m_luiAcolyteGUIDs;
    std::list<Creature*> lpCreatures;                         // Valid pointers, only used locally
    for (GuidList::const_iterator itr = m_luiAcolyteGUIDs.begin(); itr != m_luiAcolyteGUIDs.end(); ++itr)
    {
        if (Creature* pCreature = pPlayer->GetMap()->GetCreature(*itr))
        {
            // kill the creature

            // test - output creature located
            uint32 uEntry = pCreature->GetEntry();
            DEBUG_LOG("*+_*+_*+_*+_");
            DEBUG_LOG(" ======= Creature found: Entry %u  *********", uEntry);
        }
    }
    
    // terminate them
    

    return true;
}

void AddSC_item_scripts()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "item_martin_fury";
    pNewScript->pItemUse = &ItemUse_item_martin_fury;
    pNewScript->RegisterSelf();
}
