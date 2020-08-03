#include <napi.h>
#include "QGraphicsOpacityEffect/qgraphicsopacityeffect_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
	QGraphicsOpacityEffectWrap::init(env, exports);
	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
