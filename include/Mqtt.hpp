#pragma once
#include <paho-mqtt/MQTTClient.h>

void delivered(void *context, MQTTClient_deliveryToken dt);

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message);

void connlost(void *context, char *cause);

void MqttConn(const char *clientId);

void MqttSend(const char *topic, const char *message);

void MqttClose();