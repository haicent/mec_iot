#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <paho-mqtt/MQTTClient.h>
#define ADDRESS "tcp://172.18.100.27:31953"
#define CLIENTID "ExampleClientPub"
#define TOPIC "abc"
#define PAYLOAD "Hello World!"
#define QOS 1
#define TIMEOUT 10000L
volatile MQTTClient_deliveryToken deliveredtoken;

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
int main(int argc, char *argv[])
{
    static MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;
    MQTTClient_create(&client, ADDRESS, CLIENTID,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    // conn_opts.username = "";
    // conn_opts.password = "";
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    // pubmsg.payload = convertString2ptr(PAYLOAD);
    std::string s = "Hello World!";
    const char *ss = s.c_str();
    pubmsg.payload = const_cast<char *>(PAYLOAD);
    pubmsg.payloadlen = strlen(PAYLOAD);
    // pubmsg.payloadlen = 12;
    // strlen(s);
    pubmsg.qos = QOS;
    pubmsg.retained = 1;
    deliveredtoken = 0;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for publication of %s\n"
           "on topic %s for client with ClientID: %s\n",
           PAYLOAD, TOPIC, CLIENTID);
    while (deliveredtoken != token)
        ;
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}