#include <iostream>
#include <conio.h>

using namespace std;
class NetworkProtocolCommand
{
public:
	virtual void PerformAction() = 0;
};
class ServerReceiver
{
public:
	void Action()
	{
		cout << "Network Protocol Command received" <<endl;
		
	}
};
class ClientInvoker
{
	NetworkProtocolCommand *m_NetworkProtocolCommand;

public:
	ClientInvoker(NetworkProtocolCommand *cmd = 0) : m_NetworkProtocolCommand(cmd)
	{
	}

	void SetCommad(NetworkProtocolCommand *cmd)
	{
		m_NetworkProtocolCommand = cmd;
	}

	void Invoke()
	{
		if (0 != m_NetworkProtocolCommand)
		{
			m_NetworkProtocolCommand->PerformAction();
		}
	}
};

class MyNetworkProtocolCommand : public NetworkProtocolCommand
{
	ServerReceiver *m_ServerReceiver;

public:
	MyNetworkProtocolCommand(ServerReceiver *rcv = 0) : m_ServerReceiver(rcv)
	{
	}

	void SetServerReceiver(ServerReceiver *rcv)
	{
		m_ServerReceiver = rcv;
	}

	virtual void PerformAction()
	{
		if (0 != m_ServerReceiver)
		{
			m_ServerReceiver->Action();
		}
	}
};

int main()
{
	ServerReceiver r;
	MyNetworkProtocolCommand cmd(&r);
	ClientInvoker caller(&cmd);
	caller.Invoke();

	_getch();
	return 0;
}