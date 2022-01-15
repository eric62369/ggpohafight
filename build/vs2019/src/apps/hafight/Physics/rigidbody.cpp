#include "rigidbody.h"

namespace Physics {
    float truncateFloat(float in) {
        return static_cast<float>(static_cast<int>(in * 10.)) / static_cast<float>(10.);
    }

    Rigidbody::Rigidbody(float* x, float* y, float* dx, float* dy) {
        _x = x;
        _y = y;
        _dx = dx;
        _dy = dy;

        *_x = truncateFloat(*_x);
        *_y = truncateFloat(*_y);
        *_dx = truncateFloat(*_dx);
        *_dy = truncateFloat(*_dy);

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

    void Rigidbody::ApplyForce(float x, float y) {
        x = truncateFloat(x);
        y = truncateFloat(y);
        * _dx += x;
        *_dx += y;
    }
    void Rigidbody::SetVelX(float x) {
        x = truncateFloat(x);
        *_dx = x;
    }
    void Rigidbody::SetVelY(float y) {
        y = truncateFloat(y);
        *_dy = y;
    }
}
