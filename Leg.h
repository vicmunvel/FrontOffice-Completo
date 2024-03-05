#ifndef FRONT_OFFICE_LEG_H
#define FRONT_OFFICE_LEG_H

#include <vector>
#include <map>
#include <memory>
#include "ZeroCouponCurve.h"
#include "LegDescription.h"
#include "DayCountCalculator.h"
class Leg {
public:
    Leg(const LegDescription& legDescription, std::shared_ptr<ZeroCouponCurve> curve);

    virtual ~Leg() = default;

    // 'virtual' se utilizaba para indicar que un metodo puede ser sobrescrito por nuna clase derivada.
    // Con esto obligamos a que las clases derivadas implementen el metodo a su manera
    // Método abstracto para calcular el valor presente de la pata
    virtual double presentValue(const boost::gregorian::date& pricingDate) const = 0;

// Declaramos los miembros como 'protected' para que sean accesibles desde las clases que lo heredan
protected:
    LegDescription description_;
    std::shared_ptr<ZeroCouponCurve> curve_;
    std::map<boost::gregorian::date, double> cashFlows_;
    std::unique_ptr<DayCountCalculator> dayCountCalculator_;
};

#endif
