#ifndef GAME_SERVER_ENTITIES_SPECIAL_ARMOR_H
#define GAME_SERVER_ENTITIES_SPECIAL_ARMOR_H

class CArmor : public CEntity
{
public:
	CArmor(CGameWorld* pGameWorld, vec2 Pos, int Owner);

	virtual void Reset();
	virtual void Tick();
	virtual void Snap(int SnappingClient);

private:
	int m_Owner;
	int m_LifeSpan;
};

#endif