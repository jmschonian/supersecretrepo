#include "pch.h"
#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}


void ObjectManager::init()
{
}

void ObjectManager::update(float dt)
{
	for (CGameObject* Object : mGameObjects)
	{
		if (Object->IsMarkedForDeath())
		{
			Object->Free();
		}
		else
		{
			//Dispatch LogicUpdate event to GameObject
		}
	}
}

void ObjectManager::free()
{
}