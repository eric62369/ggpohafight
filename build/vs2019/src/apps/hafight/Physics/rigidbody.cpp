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
    Rigidbody::Rigidbody(float* x, float* y, float* dx, float* dy) {
        _x = x;
        _y = y;
        _dx = dx;
        _dy = dy;
    }
    Rigidbody::~Rigidbody() {}
    void Rigidbody::Update() {
        *_x += *_dx;
        *_y += *_dy;
    }

    void Rigidbody::ApplyForce(float x, float y) {
        *_dx += x;
        *_dx += y;
    }
    void Rigidbody::SetVelX(float x) {
        *_dx = x;
    }
    void Rigidbody::SetVelY(float y) {
        *_dy = y;
    }
}
