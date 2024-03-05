#include "Leg.h"
#include "DayCountCalculator.h"
#include "ZeroCouponCurve.h"

Leg::Leg(const LegDescription& legDesc, std::shared_ptr<ZeroCouponCurve> curve):
    description_(legDesc),
    curve_(curve) {

        // Inicializa el mapa de flujos de caja, que podría llenarse adecuadamente en las subclases.
        // Recorre el vector de fechas de LegDescription y lo inicializamos a 0
        for (const auto& date : description_.paymentDates) {
            cashFlows_[date] = 0.0;
        }
}
