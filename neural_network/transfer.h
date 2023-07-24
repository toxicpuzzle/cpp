#ifndef TRANSFER_H
#define TRANSFER_H

#include <cmath>

static const float e_const = 2.718281828459045;

class TransferFunc
{
public:
    TransferFunc() = default;
    virtual float getActivation(float x) const = 0; //? >=1 unoverriden Makes Transfer Func abstract class i.e. virtual ~= abstract
    virtual float getDerivative(float x) const = 0;
};

class RELUTransfer : public TransferFunc
{
    float getActivation(float input) const
    {
        if (input <= 0)
            return 0;
        return input;
    }

    float getDerivative(float input) const
    {
        if (input <= 0)
            return 0;
        return 1;
    }
};

class SigmoidTransfer : public TransferFunc
{
    float getActivation(float input) const
    {   
        return 1/(1+std::pow(e_const, -input));
    }

    float getDerivative(float input) const
    {
        float act = getActivation(input);
        return act*(1-act);
    }
};

#endif