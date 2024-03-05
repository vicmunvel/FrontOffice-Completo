#include "FloatingLeg.h"

FloatingLeg::FloatingLeg(const LegDescription& legDesc, std::shared_ptr<ZeroCouponCurve> curve, double spread):
        Leg(legDesc, curve),
        spread_(spread) {}

double FloatingLeg::presentValue(const boost::gregorian::date& pricingDate) const {
    double totalPresentValue = 0.0;
    boost::gregorian::date previousDate = description_.startDate;

    if(description_.daysCountType == "Actual/360"){
        Actual_360 actual360Calculator;

        for (const auto& paymentDate : description_.paymentDates) {
            if (pricingDate <= paymentDate) {
                double periodYearFraction = actual360Calculator(previousDate, paymentDate);
                double forwardRate = 0.02; // Lógica para calcular la tasa forward basada en la curva de índice
                double couponPayment = (forwardRate + spread_) * description_.nominal * periodYearFraction;
                double discountFactor = curve_-> getDiscountFactor(paymentDate);

                totalPresentValue += couponPayment * discountFactor;
                previousDate = paymentDate;
            }
        }

    }else if(description_.daysCountType == "30/360"){
        Thirty_360 thirty360Calculator;

        for (const auto& paymentDate : description_.paymentDates) {
            if (pricingDate <= paymentDate) {
                double periodYearFraction = thirty360Calculator(previousDate, paymentDate);
                double forwardRate = 0.02; // Lógica para calcular la tasa forward basada en la curva de índice
                double couponPayment = (forwardRate + spread_) * description_.nominal * periodYearFraction;
                double discountFactor = curve_->getDiscountFactor(paymentDate);

                totalPresentValue += couponPayment * discountFactor;
                previousDate = paymentDate;
            }
        }

    }else{
        printf("ERROR EN FloatingLeg.cpp REVISAR CONVENCION DE FECHAS");

    }

    return totalPresentValue;
}
