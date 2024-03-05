#include "FixedLeg.h"

FixedLeg::FixedLeg(const LegDescription& legDesc, std::shared_ptr<ZeroCouponCurve> curve, double fixedRate):
    Leg(legDesc, curve),
    fixedRate_(fixedRate) {}

    double FixedLeg::presentValue(const boost::gregorian::date& pricingDate) const {
        double totalPresentValue = 0.0;
        boost::gregorian::date previousDate = description_.startDate;

        if(description_.daysCountType == "Actual/360"){
            Actual_360 actual360Calculator;

            for (const auto& paymentDate : description_.paymentDates) {
                if (pricingDate <= paymentDate) {

                    double periodYearFraction = actual360Calculator(previousDate, paymentDate);
                    double couponPayment = fixedRate_ * description_.nominal * periodYearFraction;
                    double discountFactor = curve_->getDiscountFactor(paymentDate);

                    totalPresentValue += couponPayment * discountFactor;
                    previousDate = paymentDate;
                }
            }

        }else if(description_.daysCountType == "30/360"){
            Thirty_360 thirty360Calculator;

            for (const auto& paymentDate : description_.paymentDates) {
                if (pricingDate <= paymentDate) {
                    double periodYearFraction = thirty360Calculator(previousDate, paymentDate);
                    double couponPayment = fixedRate_ * description_.nominal * periodYearFraction;
                    double discountFactor = curve_->getDiscountFactor(paymentDate);

                    totalPresentValue += couponPayment * discountFactor;
                    previousDate = paymentDate;
                }
            }

        }else{
            printf("ERROR EN LegFixed.cpp REVISAR CONVENCION DE FECHAS");

        }

        return totalPresentValue;
}
