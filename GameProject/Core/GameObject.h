#pragma once
#include "SimpleMath.h"
#include "IComponent.h"
#include <unordered_map>

enum ETags
{
	SampleTag = 0,

	TagsNUM
};

class CGameObject
{
public:

	CGameObject();
	~CGameObject();

	void Init();
	void Free();

	void MarkForDeath();
	bool IsMarkedForDeath();

	void AddTag(const ETags tag);
	bool HasTag(const ETags tag) const;

	template <typename T>
	T* AddComponent()
	{
		T* NewComp = gObjectManager.CreateObject<T>(typeid(T).name());
		NewComp->mParent = this;
		mComponents[typeid(T).name()] = NewComp;
		NewComp->Init();
		return NewComp;
	}

	template <typename T>
	T* GetComponent()
	{
		return mComponents.count(typeid(T).name()) ? (T*)mComponents[typeid(T).name()] : nullptr;
	}

private:

public:

	Matrix mTransform;
	Vector3 mPos;
	Vector3 mRot;
	float mScale;

private:
	std::unordered_map<std::string, IComponent*> mComponents;
	int mTags;
	bool mIsMarkedForDeath;
	bool mIsFree;
};