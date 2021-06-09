#include <napi.h>
#include <string>

int count = 0;
int a = 0;
int b = 1;

Napi::String get_next_fibonacci(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();

    int t = a;
    a = b;
    b = t+b;

    return Napi::String::New(env, std::to_string(t));
}

Napi::Object init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "get"), Napi::Function::New(env, get_next_fibonacci));
    return exports;
};

NODE_API_MODULE(fibonacci, init);