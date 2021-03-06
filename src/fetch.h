#ifndef FETCH_H
#define FETCH_H

#include <Arduino.h>
#include <ESP8266HTTPClient.h>

#include "certStore.h"

class HTTPRequest
{

public:
    void clean();
    int GET(String url);
    int POST(String url, String body);
    bool busy();
    bool available();
    uint8_t read();
    String readString();
    void begin();

private : 
    BearSSL::CertStore certStore;

    HTTPClient *http;
    WiFiClient *client;
    BearSSL::WiFiClientSecure *httpsClient;

    void beginRequest(String &url);
};

extern HTTPRequest fetch;

#endif
