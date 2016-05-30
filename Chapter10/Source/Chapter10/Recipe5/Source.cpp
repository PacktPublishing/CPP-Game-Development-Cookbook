#include <thread>
#include <string>
#include <mutex>
#include <iostream>

using namespace std;

std::mutex MU;

void Locomotion(string msg, int id)
{
	std::lock_guard<std::mutex> guard(MU); //RAII
	//MU.lock();
	cout << msg << id << endl;
	//MU.unlock();
}
void InterfaceFunction()
{
	for (int i = 0; i > -100; i--)
		Locomotion(string("From Thread 1: "), i);

}

int main()
{
	std::thread FirstThread(InterfaceFunction);
	for (int i = 0; i < 100; i++)
		Locomotion(string("From Main: "), i);

	FirstThread.join();

	int a;
	cin >> a;
	return 0;
}