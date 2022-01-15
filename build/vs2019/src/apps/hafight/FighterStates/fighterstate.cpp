#include "fighterstate.h"

namespace Player {
    FighterState::FighterState(int* frame) {
        _frame = frame;
    }
    FighterState::~FighterState() {}
    void FighterState::Enter(BaseFighter& fighter) {
        // TODO: remove unused params
        fighter = fighter;
        *_frame = 0;
    }
    void FighterState::Update(BaseFighter& fighter) {
        // TODO: remove unused params
        fighter = fighter;
        *_frame = *_frame + 1;
    }
    void FighterState::LoadState(int frame) {
        *_frame = frame;
    }
}