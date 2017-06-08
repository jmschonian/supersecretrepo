#pragma once

class ObjectManager
{
public:
	ObjectManager();
	void init();
	void update();
	void free();
};

static ObjectManager gObjectManager;