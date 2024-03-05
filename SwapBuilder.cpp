#include "SwapBuilder.h"
#include "FactoryRegistrator.h"

namespace register_swap
{
    FactoryRegistrator<SwapBuilder> registration;
}
InstrumentDescription::Type SwapBuilder::getId ()
{
    return InstrumentDescription::Type::swap;
}
std::unique_ptr<IPricer> SwapBuilder::build (const InstrumentDescription& instrument)
{
//...
    std::unique_ptr<IPricer> swap;
    swap = std::make_unique<swap>(receiver, payer, zerocouponCurve);
    return swap;
}