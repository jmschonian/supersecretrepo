#pragma once
#include "GameObject.h"
#include <unordered_map>

class ObjectManager
{
public:
	ObjectManager();
	void init();
	void update(float dt);
	void free();

private:
	std::vector<CGameObject*> mGameObjects;
	std::unordered_map<std::string, std::vector<IComponent*>> mComponentMap;
};

static ObjectManager gObjectManager;