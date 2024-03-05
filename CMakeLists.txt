cmake_minimum_required(VERSION 3.27)
project(Front-Office)

set(CMAKE_CXX_STANDARD 17)

# Especifica la ruta de instalación de Boost
set(BOOST_ROOT /home/victor/boost_1_84_0)

# Añade Boost
find_package(Boost COMPONENTS date_time REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Añade tus archivos fuente
add_executable(Front-Office Ejemplo_DayCountCalculator.cpp
        DayCountCalculator.cpp
        DayCountCalculator.h
        SwapBuilder.h
        SwapBuilder.cpp
        InstrumentDescription.h
        Factory.cpp
        Factory.h
        FactoryRegistrator.h
        LegDescription.h
        Leg.cpp
        Leg.h
        FixedLeg.cpp
        FixedLeg.h
        FloatingLeg.cpp
        FloatingLeg.h
        Index.cpp
        Index.h
        ZeroCouponCurve.cpp
        ZeroCouponCurve.h
        IPricer.h
        main.cpp
)

# Enlaza las bibliotecas Boost con tu ejecutable
target_link_libraries(Front-Office ${Boost_LIBRARIES})
