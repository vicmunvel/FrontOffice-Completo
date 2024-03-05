#ifndef FRONT_OFFICE_IPRICER_H
#define FRONT_OFFICE_IPRICER_H

#include <boost/date_time/gregorian/gregorian.hpp>

// La interfaz IPricer define el método price que cada instrumento financiero debe implementar.
class IPricer {
public:
    virtual ~IPricer() = default;

    // Método virtual puro que calcula el precio del instrumento en la fecha de valoración dada.
    virtual double price(const boost::gregorian::date& valuationDate) const = 0;
};

#endif
