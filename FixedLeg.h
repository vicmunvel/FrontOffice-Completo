#ifndef FRONT_OFFICE_FIXEDLEG_H
#define FRONT_OFFICE_FIXEDLEG_H

#include "Leg.h"

class FixedLeg : public Leg {
public:
    FixedLeg(const LegDescription& legDesc, std::shared_ptr<ZeroCouponCurve> curve, double fixedRate);
    virtual double presentValue(const boost::gregorian::date& pricingDate) const override;

private:
    double fixedRate_;
};

#endif
