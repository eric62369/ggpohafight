set(GGPO_EXAMPLES_HAFIGHT_INC_NOFILTER
	"gamestate.h"
	"ggpo_perfmon.h"
	"nongamestate.h"
	"renderer.h"
	"Resource.h"
	"targetver.h"
	"hafight.h"
	"inputreader.h"
	"raylibrenderer.h"
	"animation.h"
	"animator.h"
	"backwardwalkstate.h"
	"basefighter.h"
	"fighterstate.h"
	"forwardwalkstate.h"
	"gamepadinput.h"
	"hitbox.h"
	"inputinterpreter.h"
	"rigidbody.h"
	"runner.h"
	"standstate.h"
)

set(GGPO_EXAMPLES_HAFIGHT_SRC_NOFILTER
	"gamestate.cpp"
	"ggpo_perfmon.cpp"
	"main.cpp"
	"hafight.cpp"
	"inputreader.cpp"
	"raylibrenderer.cpp"
	"animation.cpp"
	"animator.cpp"
	"basefighter.cpp"
	"backwardwalkstate.cpp"
	"fighterstate.cpp"
	"forwardwalkstate.cpp"
	"gamepadinput.cpp"
	"hitbox.cpp"
	"rigidbody.cpp"
	"runner.cpp"
	"standstate.cpp"
)

set(GGPO_EXAMPLES_HAFIGHT_WIN32RES
	"HAFight.rc"
)

source_group(" " FILES ${GGPO_EXAMPLES_HAFIGHT_INC_NOFILTER} ${GGPO_EXAMPLES_HAFIGHT_SRC_NOFILTER} ${GGPO_EXAMPLES_HAFIGHT_WIN32RES})

set(GGPO_EXAMPLES_HAFIGHT_SRC
	${GGPO_EXAMPLES_HAFIGHT_INC_NOFILTER}
	${GGPO_EXAMPLES_HAFIGHT_SRC_NOFILTER}
	${GGPO_EXAMPLES_HAFIGHT_WIN32RES}
)