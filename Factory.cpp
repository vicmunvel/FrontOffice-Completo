#include <memory>
#include <functional>
#include <map>
#include <stdexcept>
#include "Factory.h"
#include "InstrumentDescription.h"


std::unique_ptr<IPricer> Factory::operator()(const InstrumentDescription& description) const {
    auto builder = buildersMap_.find(getBuilderId(description));
    if (builder == buildersMap_.end()) {
        throw std::runtime_error("invalid payoff descriptor");
    };
    return (builder->second)(description);
}

InstrumentDescription::Type Factory::getBuilderId(const InstrumentDescription& description) {
    return description.type;
}

void Factory::register_constructor(const InstrumentDescription::Type& id,
                                   const Builder& builder)
{
    buildersMap_.insert(std::make_pair(id, builder));
}