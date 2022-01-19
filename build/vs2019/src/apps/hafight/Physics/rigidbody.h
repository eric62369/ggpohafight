#pragma once
#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_

namespace Physics {
    class Rigidbody {
    public:
        Rigidbody(int* x, int* y, int* dx, int* dy);
        virtual ~Rigidbody();
        virtual void Update();
        virtual void ApplyForce(int x, int y);
        virtual void SetVelX(int x);
        virtual void SetVelY(int y);
        virtual int GetVelX();
        virtual int GetVelY();

    protected:
        int* _x;
        int* _y;
        int* _dx;
        int* _dy;

        int _pboxWidth;
        int _pboxHeight;
        int _pboxXOffset;
        int _pboxYOffset;

        int _gravity;
    };
}

#endif