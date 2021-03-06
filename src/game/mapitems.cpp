#include <game/mapitems.hpp>

bool IsValidGameTile(int Index)
{
	return (
		Index == TILE_AIR ||
		(Index >= TILE_SOLID && Index <= TILE_THROUGH) ||
		Index == TILE_FREEZE ||
		(Index >= TILE_UNFREEZE && Index <= TILE_DUNFREEZE) ||
		(Index >= TILE_REFILL_JUMPS && Index <= TILE_STOPA) ||
		(Index >= TILE_CP && Index <= TILE_THROUGH_DIR) ||
		(Index >= TILE_OLDLASER && Index <= TILE_UNLOCK_TEAM) ||
		(Index >= TILE_ENTITIES_OFF_1 && Index <= TILE_ENTITIES_OFF_2) ||
		IsValidEntity(Index));
}

bool IsValidFrontTile(int Index)
{
	return (
		    Index == TILE_AIR
		||  Index == TILE_DEATH
		|| (Index >= TILE_NOLASER && Index <= TILE_THROUGH)
		||  Index == TILE_FREEZE
		|| (Index >= TILE_UNFREEZE && Index <= TILE_DUNFREEZE)
		|| (Index >= TILE_WALLJUMP && Index <= TILE_SOLO_END)
		|| (Index >= TILE_REFILL_JUMPS && Index <= TILE_STOPA)
		|| (Index >= TILE_CP && Index <= TILE_THROUGH_DIR)
		|| (Index >= TILE_OLDLASER && Index <= TILE_UNLOCK_TEAM)
		|| (Index >= TILE_NPC_END && Index <= TILE_NPH_END)
		|| (Index >= TILE_NPC_START && Index <= TILE_NPH_START)
		||  IsValidEntity(Index)
	);
}

bool IsValidEntity(int Index)
{
	Index -= ENTITY_OFFSET;
	return (
		   (Index >= ENTITY_SPAWN && Index <= ENTITY_LASER_O_FAST)
		|| (Index >= ENTITY_PLASMAE && Index <= ENTITY_CRAZY_SHOTGUN)
		|| (Index >= ENTITY_DRAGGER_WEAK && Index <= ENTITY_DRAGGER_STRONG_NW)
		||  Index == ENTITY_DOOR
	);
}
bool IsRotatableTile(int Index)
{
	return (
		Index == TILE_STOP ||
		Index == TILE_STOPS ||
		Index == TILE_CP ||
		Index == TILE_CP_F ||
		Index == TILE_THROUGH_DIR ||
		Index == TILE_ENTITIES_OFF_1 ||
		Index == TILE_ENTITIES_OFF_2 ||
		Index - ENTITY_OFFSET == ENTITY_CRAZY_SHOTGUN_EX ||
		Index - ENTITY_OFFSET == ENTITY_CRAZY_SHOTGUN);
}
bool IsValidSwitchTile(int Index)
{
	return (
		Index == TILE_JUMP ||
		Index == TILE_FREEZE ||
		Index == TILE_DFREEZE ||
		Index == TILE_DUNFREEZE ||
		(Index >= TILE_SWITCHTIMEDOPEN && Index <= TILE_SWITCHCLOSE) ||
		(IsValidEntity(Index) && Index >= ENTITY_OFFSET + ENTITY_ARMOR_1));
}
