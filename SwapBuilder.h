#ifndef FRONT_OFFICE_SWAPBUILDER_H
#define FRONT_OFFICE_SWAPBUILDER_H

#include <memory>
#include "InstrumentDescription.h"
#include "IPricer.h"

class SwapBuilder
{
public:
    static std::unique_ptr<IPricer> build (const InstrumentDescription& instrument);
    static InstrumentDescription::Type getId ();
};

#endif
