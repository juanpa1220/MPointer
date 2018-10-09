#ifndef MPOINTER_JSONMAKERCLIENT_H
#define MPOINTER_JSONMAKERCLIENT_H

#include <../../libraries/include/rapidjson/document.h>

/**
 * Realiza toda la administración del JSON para el cliente
 */
class JSONMakerClient {
public:
    std::string solicitarMemoria(std::string);

    std::string solicitarValor(std::string);


    std::string solicitarAsignacion(std::string id, int dato);

    std::string solicitarAsignacion(std::string id, char dato);
    std::string solicitarAsignacion(std::string id, std::string dato);

    std::string solicitarAsignacion(std::string id, double dato);

    std::string solicitarAsignacion(std::string id, bool dato);

    std::string solicitarAsignacion(std::string id, long dato);

    std::string solicitarAsignacion(std::string id, float dato);

    rapidjson::Document parsearJSON(char *);

};


#endif //MPOINTER_JSONMAKERCLIENT_H
