#ifndef GRADIENT_H
#define GRADIENT_H

#include <vector>
#include <iostream>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;


class Differential
{
    private:
        float x;
        float dx;
        float w_; 
        float b_;
        float dx_target;
        float df;
        float dfdx;
        float new_dfdx;

    public:
        Differential(float x, float dx, float dx_target , float w_, float b_)
        {
            x = x;
            dx = dx;
            dx_target = dx_target;
            w_ = w_;
            b_ = b_;

            df = getFx(x + dx, w_, b_) - getFx(x, w_, b_);
            dfdx = df / dx;
            new_dfdx = getFx(x, w_, b_) + dfdx * dx_target;

        }


    public:
        float getDfdx(){return dfdx; }
        float getNewDfdx(){return new_dfdx; }
        float getFx(float x, float w_,float b_)
        {
            w_ = w_;
            b_ = b_;
            x = x;
        
            return w_ * x + b_;
        }
};

#endif
