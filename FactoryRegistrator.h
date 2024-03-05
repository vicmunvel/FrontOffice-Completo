#ifndef FRONT_OFFICE_FACTORYREGISTRATOR_H
#define FRONT_OFFICE_FACTORYREGISTRATOR_H
#include "Factory.h"

template<typename BuilderClass>
class FactoryRegistrator
{
public:
    FactoryRegistrator()
    {
        Factory::instance().register_constructor(BuilderClass::getId(),
                                                 &BuilderClass::build);
    }
};

#endif