#ifndef IPC_H
#define IPC_H

#include <memory>
#include "Macros.h"

class IpcMessageQueue;
typedef std::shared_ptr<IpcMessageQueue> IpcMessageQueuePtr;

DefEx(IpcEx);

class IpcMessageQueue
{
	public:
	virtual bool ReadMessage(std::string& type, std::string& message, int timeout = -1) = 0;
	virtual bool WriteMessage(std::string type, std::string message, int timeout = -1) = 0;
	
	virtual bool GetReadBuffer(std::string& type, const char** out_buffer, size_t* out_size, int timeout = -1) = 0;
	virtual void ReturnReadBuffer(const char** buffer) = 0;

	virtual char* GetWriteBuffer(int timeout = -1) = 0;
	virtual void ReturnWriteBuffer(std::string type, char** buffer, int len) = 0;
	
	static IpcMessageQueuePtr Create(std::string name, int readQueueBuffers = 4, int readQueueSize = 1024, int writeQueueBuffers = 4, int writeQueueSize = 4);
	static IpcMessageQueuePtr Open(std::string name);
};

#endif
