#ifndef FRONT_OFFICE_FLOATINGLEG_H
#define FRONT_OFFICE_FLOATINGLEG_H

#include "Leg.h"

class FloatingLeg : public Leg {
public:
    FloatingLeg(const LegDescription& legDesc, std::shared_ptr<ZeroCouponCurve> curve, double spread);
    virtual double presentValue(const boost::gregorian::date& pricingDate) const override;

private:
    double spread_;
};

#endif
