#include <nan/nan.h>
#include "clostridium.h"


#define EXPORT(name) Nan::Set(target, NAN_TEXT(name), Nan::GetFunction(Nan::New<v8::FunctionTemplate>(clostridium::name)).ToLocalChecked())
#define EXPORT_INT(name, value) target->ForceSet(NAN_TEXT(name), Nan::New<v8::Integer>(value), v8::ReadOnly)

NAN_MODULE_INIT(Init) {
	//EXPORT(method_name);

	//EXPORT_INT(constant_name, constant_value);
}

NODE_MODULE(clostridium, Init)

#undef EXPORT
