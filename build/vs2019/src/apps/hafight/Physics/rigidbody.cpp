#include "rigidbody.h"

namespace boost
{
#ifdef BOOST_NO_EXCEPTIONS
    void throw_exception(std::exception const& e) {
        throw e; // or whatever
    };
#endif
}// namespace boost


namespace Physics {
    Rigidbody::Rigidbody() {
    }
    Rigidbody::~Rigidbody() {}
    void Rigidbody::Update() {
        _x += _dx;
        _y += _dy;
    }

    void Rigidbody::ApplyForce(float x, float y) {
        _dx += x;
        _dx += y;
    }
    void Rigidbody::SetVelX(float x) {
        _dx = x;
    }
    void Rigidbody::SetVelY(float y) {
        _dy = y;
    }

    float Rigidbody::GetVelX() {
        return static_cast<float>(_dx);
    }
    float Rigidbody::GetVelY() {
        return static_cast<float>(_dy);
    }
    float Rigidbody::GetX() {
        return static_cast<float>(_x);
    }
    float Rigidbody::GetY() {
        return static_cast<float>(_y);
    }
}
