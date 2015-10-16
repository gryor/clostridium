#ifndef CLOSTRIDIUM_H_VD1EN64P
#define CLOSTRIDIUM_H_VD1EN64P


#include <nan/nan.h>
#include <stdint.h>

#ifndef NAN_TEXT
#define NAN_TEXT(text) Nan::New<v8::String>(#text).ToLocalChecked()
#endif

#define CLOSTRIDIUM_BUFFER_DATA(i) node::Buffer::Data(info[i].As<v8::Object>())
#define CLOSTRIDIUM_BUFFER_SIZE(i) node::Buffer::Length(info[i].As<v8::Object>())
#define CLOSTRIDIUM_BUFFER(content, size) Nan::NewBuffer(content, size).ToLocalChecked()
#define CLOSTRIDIUM_CALLBACK(i) new Nan::Callback(info[i].As<v8::Function>())
#define CLOSTRIDIUM_SIZE(i) Nan::To<v8_size_t>(info[i].As<v8::Number>()).FromJust()

namespace clostridium
{
typedef uint32_t v8_size_t;

//NAN_METHOD(export_function_name);
}


#endif // end of include guard: CLOSTRIDIUM_H_VD1EN64P
