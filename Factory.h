#ifndef FRONT_OFFICE_FACTORY_H
#define FRONT_OFFICE_FACTORY_H

#include <memory>
#include <functional>
#include <map>
#include "InstrumentDescription.h"
#include "IPricer.h"

class Factory {
public:
    typedef std::function<std::unique_ptr<IPricer>(const InstrumentDescription&)> Builder;
    virtual ~Factory();
    void register_constructor(const InstrumentDescription::Type& id, const Builder& builder);
    std::unique_ptr<IPricer> operator()(const InstrumentDescription& description) const;

    // Singleton implementation...
    static Factory& instance();

private:
    Factory();
    InstrumentDescription::Type getBuilderId(const InstrumentDescription& description) const;
    std::map<InstrumentDescription::Type, Builder> buildersMap_;
};

#endif