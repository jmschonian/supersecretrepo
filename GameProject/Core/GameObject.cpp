#include "pch.h"
#include "GameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
}

void CGameObject::Init()
{
}

void CGameObject::Free()
{
}

void CGameObject::MarkForDeath()
{
}

bool CGameObject::IsMarkedForDeath()
{
	return false;
}

void CGameObject::AddTag(const ETags tag)
{
}

bool CGameObject::HasTag(const ETags tag) const
{
	return false;
}
