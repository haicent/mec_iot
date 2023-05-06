#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
// #include <paho-mqtt/MQTTClient.h>
#include "Mqtt.hpp"
// 账号配置
#define ADDRESS "tcp://172.18.100.27:31953"
#define QOS 1
#define TIMEOUT 10000L
volatile MQTTClient_deliveryToken deliveredtoken;

static MQTTClient client;
static const char *s_clientId;

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}
int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    void *payloadptr;
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");
    payloadptr = message->payload;
    std::cout << message->payload << std::endl;
    // for (i = 0; i < message->payloadlen; i++)
    // {
    //     putchar(*payloadptr++);
    // }
    putchar('\n');
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}
void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
    // const char *ci = s_clientId;
    MqttConn(s_clientId);
}
char *convertString2ptr(std::string s)
{
    std::string str = s;
    char *data;
    int len = str.length();
    data = (char *)malloc((len + 1) * sizeof(char));
    str.copy(data, len, 0);
    return data;
}
void MqttConn(const char *clientId)
{
    // TODO 这里要做单例处理，而不是每次都要连接
    // if (NULL == client)
    // {
    // }

    s_clientId = clientId;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;
    MQTTClient_create(&client, ADDRESS, clientId,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    // conn_opts.username = "";
    // conn_opts.password = "";
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        client = NULL;
        // exit(EXIT_FAILURE);
    }
    else
    {
        printf("Success to connect, return code %d\n", rc);
    }
    // return client;
}

void MqttSend(const char *topic, const char *message)
{
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    // pubmsg.payload = convertString2ptr(PAYLOAD);
    // std::string s = "Hello World222!";
    // const char *ss = s.c_str();
    pubmsg.payload = const_cast<char *>(message);
    pubmsg.payloadlen = strlen(message);
    // pubmsg.payloadlen = 12;
    // strlen(s);
    pubmsg.qos = QOS;
    pubmsg.retained = 1;
    deliveredtoken = 0;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    printf("Waiting for publication of %s\n"
           "on topic %s \n",
           message, topic);
    // while (deliveredtoken != token)
    // ;
}
void MqttClose()
{
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
}

int main888(int argc, char const *argv[])
{
    MqttConn("oneClientId001");
    MqttSend("abc", "1234");

    MqttClose();
    return 0;
}
