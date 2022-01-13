#pragma once
#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_

#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;

namespace Physics {

    // defining type for fixed precision floating points
    typedef number<cpp_dec_float<1>> fight_float;

    class Rigidbody {
    public:
        Rigidbody();
        virtual ~Rigidbody();
        virtual void Update();
        virtual void ApplyForce(float x, float y);
        virtual void SetVelX(float x);
        virtual void SetVelY(float y);
        virtual float GetX();
        virtual float GetY();
        virtual float GetVelX();
        virtual float GetVelY();

    protected:
        //virtual void Accel(float x, float y);
        fight_float _x;
        fight_float _y;
        fight_float _dx;
        fight_float _dy;

        fight_float _pboxWidth;
        fight_float _pboxHeight;
        fight_float _pboxXOffset;
        fight_float _pboxYOffset;

        fight_float _gravity;
    };
}

#endif