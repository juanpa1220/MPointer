//
// Created by ortegajosant on 30/09/18.
//

#include <stringbuffer.h>
#include <prettywriter.h>
#include "JSONMakerClient.h"

/**
 * Crea un JSON que solicita la memoria al servidor
 * @param tipo
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarMemoria(std::string tipo) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "reservar", allocator);
    doc.AddMember("tipo", rapidjson::Value().SetString(tipo.c_str(), allocator), allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();

}

/**
 * Crea un JSON que solicita al servidor que retorne un valor para un dato
 * @param id
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarValor(std::string id) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "retornar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();
}

/**
 * Solicita la asignación de una valor para un int
 * @param id ID
 * @param dato dato
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarAsignacion(std::string id, int dato) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "asignar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);
    doc.AddMember("Dato", dato, allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();
}

/**
 * Solicita la asignación de una valor para un string
 * @param id ID
 * @param dato dato
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarAsignacion(std::string id, std::string dato) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "asignar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);
    doc.AddMember("Dato", rapidjson::Value().SetString(dato.c_str(), allocator), allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

//    std::cout<<

    return stringBuffer.GetString();
}

/**
 * Solicita la asignación de una valor para un char
 * @param id ID
 * @param dato dato
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarAsignacion(std::string id, char dato) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "asignar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);
    doc.AddMember("Dato", dato, allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();
}

/**
 * Solicita la asignación de una valor para un double
 * @param id ID
 * @param dato dato
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarAsignacion(std::string id, double dato) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "asignar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);
    doc.AddMember("Dato", dato, allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();
}

/**
 * Solicita la asignación de una valor para un long
 * @param id ID
 * @param dato dato
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarAsignacion(std::string id, long dato) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "asignar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);
    doc.AddMember("Dato", rapidjson::Value().SetString(std::to_string(dato).c_str(), allocator), allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();
}

/**
 * Solicita la asignación de una valor para un bool
 * @param id ID
 * @param dato dato
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarAsignacion(std::string id, bool dato) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "asignar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);
    doc.AddMember("Dato", dato, allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();
}

/**
 * Solicita la asignación de una valor para un float
 * @param id ID
 * @param dato dato
 * @return std::string JSON
 */
std::string JSONMakerClient::solicitarAsignacion(std::string id, float dato) {

    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

    doc.AddMember("solicitud", "asignar", allocator);
    doc.AddMember("id", rapidjson::Value().SetString(id.c_str(), allocator), allocator);
    doc.AddMember("Dato", dato, allocator);

    rapidjson::StringBuffer stringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(stringBuffer);

    doc.Accept(writer);

    return stringBuffer.GetString();
}

/**
 * Parsea un string a JSON
 * @param json
 * @return Objeto JSON Document
 */
rapidjson::Document JSONMakerClient::parsearJSON(char *json) {
    rapidjson::Document document;
    document.Parse(json);
    return document;
}
