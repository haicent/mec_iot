#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
// #include <fmt/format.h>
#include <json_dto/pub.hpp>
#include "Mqtt.hpp"
#include "Structs.hpp"

auto now() { return std::chrono::steady_clock::now(); }

auto awake_time()
{
	using std::chrono::operator""ms;
	return now() + 10000ms;
}

int main(int argc, char *argv[])
{
	MqttConn("json-test");
	std::string online = "{\"deviceId\":\"josef234\",\"status\":\"1\"}";
	MqttSend("/device_online_status", online.c_str());
	MqttClose();

	clock_t start, finish;
	start = clock();
	while (true)
	{
		try
		{
			std::vector<participantBody_t> ptcList(3);
			for (int i = 0; i < 3; i++)
			{
				participantBody_t participantBody{22 + i, 88, 12, 2, 1, 3, 132432, 2, "xx路口", "yy路", 832, 72, 137.234, 38.341, 20.2, 2, 1, 80.8, 3, 30.5, 4, 23.2, 3, 4, 2.2, 1.7, 2, "red", "??", "大众"};
				ptcList.push_back(participantBody);
			}
			participant_t participant{88, "josef234", ptcList, true};

			const message_t msg{"json_dto", std::time(nullptr), "Hello once again!"};

			std::string str = json_dto::to_json(participant);

			// std::cout << "\nSerialized to JSON:\n" << str << std::endl;

			std::cout << "发送json：" << std::endl;

			MqttConn("json-test");
			MqttSend("/rscu/josef234/participant/up", str.c_str());
			MqttClose();
		}
		catch (const std::exception &ex)
		{
			std::cerr << "Error: " << ex.what() << "." << std::endl;
			return 1;
		}
		std::this_thread::sleep_until(awake_time());
	}
	finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << "runtime:   " << duration << " seconds" << std::endl;
	// printf("%2.1f seconds\n", duration);
	return 0;
}
