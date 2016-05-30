#include <thread>
#include <string>
#include <mutex>
#include <iostream>
#include <fstream>

using namespace std;

class DebugLogger
{
	std::mutex MU;
	ofstream f;
public:
	DebugLogger()
	{
		f.open("log.txt");
	}
	void ResourceSharingFunction(string id, int value)
	{
		std::lock_guard<std::mutex> guard(MU); //RAII
		f << "From" << id << ":" << value << endl;
	}

};



void InterfaceFunction(DebugLogger& log)
{
	for (int i = 0; i > -100; i--)
		log.ResourceSharingFunction(string("Thread 1: "), i);

}

int main()
{
	DebugLogger log;
	std::thread FirstThread(InterfaceFunction,std::ref(log));
	for (int i = 0; i < 100; i++)
		log.ResourceSharingFunction(string("Main: "), i);

	FirstThread.join();

	int a;
	cin >> a;
	return 0;
}