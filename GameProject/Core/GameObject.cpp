#include "pch.h"
#include "GameObject.h"

CGameObject::CGameObject() : mScale(1), mIsMarkedForDeath(false), mIsFree(true), mTags(0)
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
	mScale = 1;
	mIsMarkedForDeath = false;
	mIsFree = true;
	mTags = 0;
	mComponents.clear();
}

void CGameObject::MarkForDeath()
{
	this->mIsMarkedForDeath = true;
}

bool CGameObject::IsMarkedForDeath()
{
	return this->mIsMarkedForDeath;
}

void CGameObject::AddTag(const ETags tag)
{
	mTags |= 1 << tag;
}

bool CGameObject::HasTag(const ETags tag) const
{
	return (mTags & 1 << tag);
}
