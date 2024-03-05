#include "Index.h"

Index::Index() {
    // Inicializar la curva de índices aquí, si es necesario.
}

Index::~Index() {
    // Liberar recursos, si es necesario.
}

double Index::getRate(const boost::gregorian::date& date) const {
    // Implementar la lógica para obtener la tasa de interés.
    // Esto puede incluir buscar en una tabla de tasas históricas o calcular una tasa forward.
    // De forma simplificada, puedes devolver un valor fijo o simulado para empezar.
    return 0.02; // Tasa de interés de ejemplo.
}
