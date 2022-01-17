#pragma once
#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_

namespace Physics {
    class Rigidbody {
    public:
        Rigidbody(float* x, float* y, float* dx, float* dy);
        virtual ~Rigidbody();
        virtual void Update();
        virtual void ApplyForce(float x, float y);
        virtual void SetVelX(float x);
        virtual void SetVelY(float y);

    protected:
        //virtual void Accel(float x, float y);
        float* _x;
        float* _y;
        float* _dx;
        float* _dy;

        float _pboxWidth;
        float _pboxHeight;
        float _pboxXOffset;
        float _pboxYOffset;

        float _gravity;
        /*fight_float _x;
        fight_float _y;
        fight_float _dx;
        fight_float _dy;

        fight_float _pboxWidth;
        fight_float _pboxHeight;
        fight_float _pboxXOffset;
        fight_float _pboxYOffset;*/
    };
}

#endif