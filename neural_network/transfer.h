#ifndef TRANSFER_H
#define TRANSFER_H

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

#endif