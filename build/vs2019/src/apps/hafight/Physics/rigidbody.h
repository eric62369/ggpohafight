#pragma once
#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_

namespace Physics {
    class Rigidbody {
    public:
        Rigidbody();
        virtual ~Rigidbody();
        virtual void ApplyForce();
        virtual void Move();
    };
}

#endif