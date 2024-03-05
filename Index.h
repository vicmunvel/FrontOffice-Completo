#ifndef FRONT_OFFICE_INDEX_H
#define FRONT_OFFICE_INDEX_H

#include <boost/date_time/gregorian/gregorian.hpp>

class Index {
public:
    Index();  // Constructor para inicializar la curva de índices, si es necesario.
    ~Index(); // Destructor.

    // Método para obtener la tasa de interés para una fecha dada.
    double getRate(const boost::gregorian::date& date) const;
};

#endif
