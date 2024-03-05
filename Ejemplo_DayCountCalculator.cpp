#include "DayCountCalculator.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <string>

int main() {
    // Instancias de las clases Actual_360 y Thirty_360
    Actual_360 actual360Calculator;
    Thirty_360 thirty360Calculator;

    // STRING ACTUAL/360: Usando cadenas para calcular el número de días
    std::string startDateStr = "2016-04-01";
    std::string endDateStr = "2016-10-03";
    auto daysActual360Str = actual360Calculator.compute_daycount(startDateStr, endDateStr);
    auto fractionOfYearActual360Str = actual360Calculator(startDateStr, endDateStr);

    std::cout << "Días (Actual/360 - Strings) entre " << startDateStr << " y " << endDateStr << ": " << daysActual360Str << std::endl;
    std::cout << "Fracción de año (Actual/360 - Strings) entre " << startDateStr << " y " << endDateStr << ": " << fractionOfYearActual360Str << std::endl;


    // BOOST ACTUAL/360: Usando objetos boost::gregorian::date para calcular el número de días
    boost::gregorian::date startDate(boost::gregorian::from_string("2016-04-01"));
    boost::gregorian::date endDate(boost::gregorian::from_string("2016-10-03"));
    auto daysActual360Date = actual360Calculator.compute_daycount(startDate, endDate);
    auto fractionOfYearActual360Date = actual360Calculator(startDate, endDate);

    std::cout << "Días (Actual/360 - Gregorian) entre " << startDate << " y " << endDate << ": " << daysActual360Date << std::endl;
    std::cout << "Fracción de año (Actual/360- Gregorian) entre " << startDate << " y " << endDate << ": " << fractionOfYearActual360Date << std::endl;


    // STRING 30/360: Usando cadenas para calcular el número de días
    auto daysThirtyl360Str = thirty360Calculator.compute_daycount(startDateStr, endDateStr);
    auto fractionOfYearThirty360Str = thirty360Calculator(startDateStr, endDateStr);

    std::cout << "Días (30/360 - Strings) entre " << startDateStr << " y " << endDateStr << ": " << daysThirtyl360Str << std::endl;
    std::cout << "Fracción de año (30/360- Gregorian) entre " << startDateStr << " y " << endDateStr << ": " << fractionOfYearThirty360Str << std::endl;


    // BOOST 30/360: Usando objetos boost::gregorian::date para calcular el número de días
    auto daysThirty360Date = thirty360Calculator.compute_daycount(startDate, endDate);
    auto fractionOfYearThirty360Date = thirty360Calculator(startDate, endDate);

    std::cout << "Días (30/360 - Gregorian) entre " << startDate << " y " << endDate << ": " << daysThirty360Date << std::endl;
    std::cout << "Fracción de año (30/360- Gregorian) entre " << startDateStr << " y " << endDateStr << ": " << fractionOfYearThirty360Date << std::endl;


    // Calculando el número de días especificando años, meses y días con 30/360 p.e.
    short years = 1, months = 2, daysFrom = 15, daysTo = 18;
    auto daysThirty360 = thirty360Calculator.compute_daycount(years, months, daysFrom, daysTo);

    std::cout << "Días (30/360) con años: " << years << ", meses: " << months << ", desde día: " << daysFrom << ", hasta día: " << daysTo << ": " << daysThirty360 << std::endl;
    std::cout << "Conversion a fraccion: " << daysThirty360/360.0 << std::endl;

    return 0;
}


