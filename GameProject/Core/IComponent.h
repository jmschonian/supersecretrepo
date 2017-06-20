#pragma once
using namespace DirectX::SimpleMath;

class IComponent
{
public:
	virtual void Init() = 0;
	virtual void Free() = 0;

private:

public:
	IComponent* mParent;

private:
};