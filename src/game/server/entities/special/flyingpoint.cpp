/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include <engine/shared/config.h>
#include <game/server/entities/character.hpp>

#include <game/server/gamecontext.h>
#include "flyingpoint.hpp"

CFlyingPoint::CFlyingPoint(CGameWorld *pGameWorld, vec2 Pos, int OwnerID, vec2 InitialVel)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_PROJECTILE)
{
	m_Pos = Pos;
	m_InitialVel = InitialVel;
	m_OwnerID = OwnerID;
	m_InitialAmount = 0;
	GameWorld()->InsertEntity(this);
}

void CFlyingPoint::Tick()
{
	CPlayer *pOwner = GameServer()->m_apPlayers[m_OwnerID];
	if(!pOwner || !pOwner->GetCharacter())
	{
		return;
	}

	const float Dist = distance(m_Pos, pOwner->GetCharacter()->m_Pos);
	if(Dist < 24.0f)
	{
		GameServer()->CreateSound(m_Pos, SOUND_PICKUP_HEALTH, -1);
		pOwner->m_Level.m_Exp += g_Config.m_ClBlockExp /2;
		GameServer()->m_World.DestroyEntity(this);
		return;
	}

	vec2 Dir = normalize(pOwner->GetCharacter()->m_Pos - m_Pos);
	m_Pos += Dir*clamp(Dist, 0.0f, 16.0f) * (1.0f - m_InitialAmount) + m_InitialVel * m_InitialAmount;
	m_InitialAmount *= 0.98f;
}

void CFlyingPoint::Snap(int SnappingClient)
{
	CNetObj_Projectile *pObj = static_cast<CNetObj_Projectile *>(Server()->SnapNewItem(NETOBJTYPE_PROJECTILE, m_ID, sizeof(CNetObj_Projectile)));
	if(pObj)
	{
		pObj->m_X = (int)m_Pos.x;
		pObj->m_Y = (int)m_Pos.y;
		pObj->m_VelX = 0;
		pObj->m_VelY = 0;
		pObj->m_StartTick = Server()->Tick();
		pObj->m_Type = WEAPON_HAMMER;
	}
}
