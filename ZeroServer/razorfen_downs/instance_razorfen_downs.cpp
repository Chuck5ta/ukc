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
 * SDName:      Instance_razorfen_downs
 * SD%Complete: 0
 * SDComment:   
 * SDCategory:  Razorfen Downs
 * EndScriptData
 */

#include "precompiled.h"
#include "razorfen_downs.h"


instance_razorfen_downs::instance_razorfen_downs(Map* pMap) : ScriptedInstance(pMap)
{
    Initialize();
}


void instance_razorfen_downs::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

void instance_razorfen_downs::OnCreatureCreate(Creature* pCreature)
{
    //
}

void instance_razorfen_downs::OnObjectCreate(GameObject* pGo)
{
    //
}

void instance_razorfen_downs::SetData(uint32 uiType, uint32 uiData)
{
    //
}

void instance_razorfen_downs::Load(const char* chrIn)
{
    //
}

uint32 instance_razorfen_downs::GetData(uint32 uiType) const
{
    if (uiType < MAX_ENCOUNTER)
    {
        return m_auiEncounter[uiType];
    }

    return 0;
}

void instance_razorfen_downs::OnCreatureEnterCombat(Creature* pCreature)
{
    //
}

void instance_razorfen_downs::OnCreatureEvade(Creature* pCreature)
{
    //
}

void instance_razorfen_downs::OnCreatureDeath(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_TOMB_FIEND:
                // process fiend combat
            break;
        case NPC_TOMB_REAVER:
            // process reaver combat
            break;
    }
}

void instance_razorfen_downs::Update(uint32 uiDiff)
{
    //
}

InstanceData* GetInstanceData_instance_razorfen_downs(Map* pMap)
{
    return new instance_razorfen_downs(pMap);
}

void AddSC_instance_razorfen_downs()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_razorfen_downs";
    pNewScript->GetInstanceData = &GetInstanceData_instance_razorfen_downs;
    pNewScript->RegisterSelf();
}
