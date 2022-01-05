#include <stdio.h>
#include <math.h>
#include "ggponet.h"
#include "inputreader.h"
#include "gamestate.h"

#include "../../../build/vs2019/src/apps/hafight/Fighter/basefighter.h"
#include "../../../build/vs2019/src/apps/hafight/Fighter/inputinterpreter.h"

using namespace Player;

extern GGPOSession *ggpo;

// Fighter representation that modifies the fighter game state struct
BaseFighter* Fighters[MAX_FIGHTERS];
InputInterpreter* Interpreters[MAX_FIGHTERS];

/*
 * InitGameState --
 *
 * Initialize our game state.
 */

void
GameState::Init(int num_players)
{
   _framenumber = 0;
   _num_fighters = num_players;
   int i;

   for (i = 0; i < _num_fighters; i++) {
       Fighters[i] = new BaseFighter(&_fighters[i]);
       Interpreters[i] = new InputInterpreter();
   }
}

void GameState::GetFighterAI(int i)
{
    i = i;
}
void
GameState::Update(int inputs[], int disconnect_flags)
{
   _framenumber++;
   for (int i = 0; i < _num_fighters; i++) {
      if (disconnect_flags & (1 << i)) {
          GetFighterAI(i);
      } else {
          Fighters[i]->HandleInput(Interpreters[i]->ParseInput(inputs[i]));
      }
      Fighters[i]->Update();
   }
}
