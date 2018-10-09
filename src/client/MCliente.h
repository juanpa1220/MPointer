#ifndef MPOINTER_MCLIENTE_H
#define MPOINTER_MCLIENTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <../../libraries/include/rapidjson/document.h>
#include "JSONMakerClient.h"

/**
 * Realiza todas las conexiones con el servidor
 */
class MCliente {
public:
    static MCliente * getInstance(std::string, int);
    static MCliente * getInstance();
    static bool esActivo();

    rapidjson::Document conectar(std::string);

    std::string &getIP();

    void setIP(std::string IP);

    int getPORT();

    void setPORT(int PORT);

private:
    JSONMakerClient jsonMaker;
    std::string IP;
    int PORT;
    static MCliente *instance;
    static bool activo;

    MCliente(std::string, int);
};

#endif //MPOINTER_MCLIENTE_H
