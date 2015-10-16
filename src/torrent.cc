#include <nan/nan.h>
#include <node.h>
#include <libtorrent/entry.hpp>
#include "clostridium.h"


namespace clostridium {
class Seed : public Nan::AsyncWorker
{
public:
	Seed(Nan::Callback * callback, char * message, size_t message_size): Nan::AsyncWorker(callback), _message(message), _message_size(message_size) {}

	void Execute() {
		if(0 /* ERROR */)
			SetErrorMessage("Error happened");
	}

	void HandleOKCallback()
	{
		Nan::HandleScope scope;
		v8::Local<v8::Value> argv[] = {
			Nan::Null(),
			CLOSTRIDIUM_BUFFER(_message, _message_size)
		};
		callback->Call(2, argv);
	}

protected:
	char * _message;
	size_t _message_size;
};

NAN_METHOD(seed)
{
	Nan::AsyncQueueWorker(new Seed(CLOSTRIDIUM_CALLBACK(1), CLOSTRIDIUM_BUFFER_DATA(0), CLOSTRIDIUM_BUFFER_SIZE(0)));
}
}
