#ifndef _RAYLIB_RENDERER_H_
#define _RAYLIB_RENDERER_H_

#include "renderer.h"

/*
 * renderer.h --
 *
 * A simple C++ renderer that uses GDI to render the game state.
 *
 */

class RaylibRenderer : public Renderer {
public:
	RaylibRenderer(NonGameState& ngs);
	~RaylibRenderer();

	virtual void Draw(GameState& gs, NonGameState& ngs);
	virtual void SetStatusText(const char* text);
	virtual void ToggleFPS();

	char           _status[1024];
	bool		   _drawFPS;
};

#endif
