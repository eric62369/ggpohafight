#include "gameinterfaces.h"
#include "fighterstates.h"
#include "inputinterpreter.h"

namespace Player {
    class FighterState {
    public:
        FighterState() {
            _frame = 0;
        }
        virtual FighterState* HandleInput(IFighter& fighter, InputAction input) = 0;
        virtual void Enter(IFighter& fighter) {
            _frame = 0;
        };
        virtual void Update(IFighter& fighter) {
            _frame++;
        }
        virtual void LoadState(int frame) {
            _frame = frame;
        }

    protected:
        int _frame; // Which frame in this state are we in? count from 0 to x
    };

    class BaseFighter {
    public:
        BaseFighter(Fighter* _gameStateData) {
            _state = new StandState();
            _gameStateData->position.x = 100;
            _gameStateData->position.y = 100;
        }
        virtual void HandleInput(InputAction input) {
            FighterState* new_state = _state->HandleInput(*this, input);
            if (new_state != nullptr) {
                delete _state;
                _state = new_state;
                _state->Enter(*this);
            }

        }
        virtual void Update() {
            _state->Update(*this);
        }
        virtual void LoadState(int stateEnum, int frame) {
        }
        virtual void SaveState() {
        }
        virtual void MoveFighter(int dx, int dy) {
            _gameStateData->position.x += dx;
            _gameStateData->position.y += dy;
        }

    protected:
        FighterState* _state;
        Fighter* _gameStateData;
    };
}

#endif