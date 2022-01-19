#include "rigidbody.h"

namespace Physics {
    Rigidbody::Rigidbody(int* x, int* y, int* dx, int* dy) {
        _x = x;
        _y = y;
        _dx = dx;
        _dy = dy;

        _gravity = 9;
        _pboxWidth = 1;
        _pboxHeight = 1;
        _pboxXOffset = 1;
        _pboxYOffset = 1;
    }
    Rigidbody::~Rigidbody() {}
    void Rigidbody::Update() {
        *_x += *_dx;
        *_y += *_dy;
    }

    void Rigidbody::ApplyForce(int x, int y) {
        * _dx += x;
        *_dx += y;
    }
    void Rigidbody::SetVelX(int x) {
        *_dx = x;
    }
    void Rigidbody::SetVelY(int y) {
        *_dy = y;
    }
    int Rigidbody::GetVelX() {
        return *_dx;
    }
    int Rigidbody::GetVelY() {
        return *_dy;
    }
}
