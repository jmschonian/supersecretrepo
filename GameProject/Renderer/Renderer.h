#pragma once

static Renderer gRenderer;

class Renderer
{
public:
	Renderer();
	void init();
	void update();
	void free();
};

