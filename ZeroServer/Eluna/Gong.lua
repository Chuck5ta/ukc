--[[
    EmuDevs <http://emudevs.com/forum.php>
    Eluna Lua Engine <https://github.com/ElunaLuaEngine/Eluna>
    Eluna Scripts <https://github.com/ElunaLuaEngine/Scripts>
    Eluna Wiki <http://wiki.emudevs.com/doku.php?id=eluna>

    -= Script Information =-
    * Zone: Tanaris
    * Script Type: Quest (Cuergo's Gold)
    * Creature: Sailor boys (7899, 7901, 7902)
    * Game object: Pirate's treasure chest (142194)
	* Version: tested on Zero
--]]

-- This creates the table used to localize all variables and functions
local TutenkashGong = {
    GO_GONG = 148917;
    NPC_TOMB_FIEND = 7349,
    TOTAL_FIENDS = 8,
    NPC_TOMB_REAVER = 7351,
    NPC_TUTENKASH = 7355,
    CreatureSpawnPoints =
    {
        { 2540.479, 906.539. 46.663, 5.47 },
        { 2541.511, 912.857, 46.216, 5.39 },
        { 2536.703, 917.214, 46.094, 5.57 },
        { 2530.443, 913.598, 46.083, 5.69 },
        { 2529.833, 920.977, 45.836, 5.47 },
        { 2524.738, 915.195, 46.248, 5.97 },
        { 2517.829, 917.746, 46.073, 5.83 },
        { 2512.750, 924.458, 46.504, 5.92 }
    }
    
}
local 

function TutenkashGong.SummonCreatures(player, NPC_ID, iTotalToSpawn)    
    for i = 1, iTotalToSpawn, 1 do
        -- spawn creature (Tomb Fiend / Tome Reaver)
        player:SummonCreature(NPC_ID, CreatureSpawnPoints[i][1], CreatureSpawnPoints[i][2], CreatureSpawnPoints[i][3], CreatureSpawnPoints[i][4], 2, 500000)
    end
end

function TutenkashGong.Gong_OnUse(event, player, go)
    -- spawn creatures
    TutenkashGong.SummonCreatures(player, TutenkashGong.NPC_TOMB_FIEND, TutenkashGong.TOTAL_FIENDS) 
    -- deactivate gong

end

-- Register the events
RegisterGameObjectGossipEvent(Gong.GO_GONG, 1, Gong.Gong_OnUse)
