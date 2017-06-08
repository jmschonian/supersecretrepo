#pragma once

class Renderer
{
public:
	Renderer();
	void init();
	void update();
	void free();
};

static Renderer gRenderer;