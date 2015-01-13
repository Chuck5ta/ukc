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

#ifndef DEF_RFD_H
#define DEF_RFD_H

enum
{
    MAX_ENCOUNTER = 1,

    GO_GONG = 148917,
    NPC_TOMB_FIEND = 7349,
    TOTAL_FIENDS = 8,
    NPC_TOMB_REAVER = 7351,
    TOTAL_REAVERS = 4,
    NPC_TUTENKASH = 7355
};

struct TUTENKASH_CreatureLocation
{
    float fX, fY, fZ, fO;
};

static const TUTENKASH_CreatureLocation aCreatureLocation[] =
{
    {2540.479f, 906.539f, 46.663f, 5.47f},               // mob 1 
    {2541.511f, 912.857f, 46.216f, 5.39f},               // mob 2
    {2536.703f, 917.214f, 46.094f, 5.57f},               // mob 3
    {2530.443f, 913.598f, 46.083f, 5.69f},               // mob 4
    {2529.833f, 920.977f, 45.836f, 5.47f},               // mob 5
    {2524.738f, 915.195f, 46.248f, 5.97f},               // mob 6
    {2517.829f, 917.746f, 46.073f, 5.83f},               // mob 7
    {2512.750f, 924.458f, 46.504f, 5.92f}                // mob 8
};


// records which round of creatures we are in (TombFiend, Tomb Raider, Boss)
static int iWaveNumber;

class instance_razorfen_downs : public ScriptedInstance
{
public:
    instance_razorfen_downs(Map* pMap);
    ~instance_razorfen_downs() {}

    void Initialize() override;

    void OnCreatureCreate(Creature* pCreature) override;
    void OnObjectCreate(GameObject* pGo) override;

    void SetData(uint32 uiType, uint32 uiData) override;
    uint32 GetData(uint32 uiType) const override;

    const char* Save() const override { return m_strInstData.c_str(); }
    void Load(const char* chrIn) override;

    void OnCreatureEnterCombat(Creature* pCreature) override;
    void OnCreatureEvade(Creature* pCreature);
    void OnCreatureDeath(Creature* pCreature) override;

    void Update(uint32 uiDiff) override;

protected:

    /*
    bool StartSlaugtherSquare();
    void DoSortZiggurats();
    void ThazudinAcolyteJustDied(Creature* pCreature);

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string m_strInstData;

    uint32 m_uiBaronRunTimer;
    uint32 m_uiBarthilasRunTimer;
    uint32 m_uiMindlessSummonTimer;
    uint32 m_uiSlaugtherSquareTimer;

    uint32 m_uiYellCounter;
    uint32 m_uiMindlessCount;
    uint8 m_uiPostboxesUsed;
    uint8 m_uiSilverHandKilled;

    ZigguratStore m_zigguratStorage[MAX_ZIGGURATS];

    std::set<uint32> m_suiCrimsonLowGuids;
    GuidList m_luiCrystalGUIDs;
    GuidSet m_sAbomnationGUID;
    GuidList m_luiAcolyteGUIDs;
    GuidList m_luiUndeadGUIDs;
    GuidList m_luiGuardGUIDs;

    // this ensures that the code that deals with the initial spawning of The Unforgiven and its adds (Vengful Phantoms) is only run once
    bool bTheUnforgivenSpawnHasTriggered;

    */   

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string m_strInstData;

    int iTombFiendsAlive = 8;

};

#endif
