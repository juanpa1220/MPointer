#include "MCliente.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

MCliente *MCliente::instance = nullptr;
bool MCliente::activo = 0;

/**
 * Se conecta con el servidor y realiza la solicitud
 * @param json std::string con el JSON
 * @return Objeto JSON Document
 */
rapidjson::Document MCliente::conectar(std::string json) {
    struct sockaddr_in direccionSC = {0};
    direccionSC.sin_family = AF_INET;
    direccionSC.sin_addr.s_addr = inet_addr(IP.c_str());
    direccionSC.sin_port = htons((u_int16_t) this->PORT);

    int cliente = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(cliente, (struct sockaddr *) &direccionSC, sizeof(direccionSC)) != 0) {
        perror("No se pudo conectar");
        return nullptr;
    }

    char mensaje[1000];

    ssize_t bytes = 0;

    // Envio del mensaje al servidor
    send(cliente, json.c_str(), json.length(), 0);

    bytes = recv(cliente, mensaje, 1000, 0);

    mensaje[bytes] = '\0';

    if (bytes <= 0) {
        perror("Se apagó el server");
        return nullptr;
    }

    close(cliente);
    return jsonMaker.parsearJSON(mensaje);
}

/**
 * Constructor privado para MCliente
 * @param ip IP
 * @param port Puerto
 */
MCliente::MCliente(std::string ip, int port) {
    this->IP = ip;
    this->PORT = port;
}

/**
 * Crea una instancia singleton para MCliente
 * @param ip IP
 * @param port Puerto
 * @return MCliente
 */
MCliente *MCliente::getInstance(std::string ip, int port) {
    if (!instance) {
        activo = true;
        instance = new MCliente(ip, port);
    }
    return instance;
}

std::string &MCliente::getIP() {
    return IP;
}

void MCliente::setIP(std::string IP) {
    this->IP = IP;
}

int MCliente::getPORT() {
    return PORT;
}

void MCliente::setPORT(int PORT) {
    this->PORT = PORT;
}

bool MCliente::esActivo() {
    return activo;
}

/**
 * Obtiene la instancia para cuando ya ha sido creada
 * @return MCliente
 */
MCliente *MCliente::getInstance() {
    if (activo) {
        return instance;
    } else {
        return nullptr;
    }
}
