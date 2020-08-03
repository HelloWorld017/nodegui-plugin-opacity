#include "qgraphicsopacityeffect_wrap.h"

#include <nodegui/Extras/Utils/nutils.h>
#include <QtCore/QObject/qobject_wrap.h>

Napi::FunctionReference QGraphicsOpacityEffectWrap::constructor;

Napi::Object QGraphicsOpacityEffectWrap::init(Napi::Env env, Napi::Object exports) {
	Napi::HandleScope scope(env);
	char CLASSNAME[] = "QGraphicsOpacityEffect";
	Napi::Function func = DefineClass(
		env,
		CLASSNAME,
		{
			QGRAPHICSEFFECT_WRAPPED_METHODS_EXPORT_DEFINE(QGraphicsOpacityEffectWrap)
		}
	);
	
	constructor = Napi::Persistent(func);
	exports.Set(CLASSNAME, func);
	return exports;
}

NGraphicsOpacityEffect* QGraphicsOpacityEffectWrap::getInternalInstance() {
  return this->instance;
}

QGraphicsOpacityEffectWrap::~QGraphicsOpacityEffectWrap() {
  extrautils::safeDelete(this->instance);
}

QGraphicsOpacityEffectWrap::QGraphicsOpacityEffectWrap(const Napi::CallbackInfo& info)
	: Napi::ObjectWrap<QGraphicsOpacityEffectWrap>(info) {
	
	Napi::Env env = info.Env();
	Napi::HandleScope scope(env);

	if (info.Length() == 1) {
		Napi::Object parentObject = info[0].As<Napi::Object>();
		QObjectWrap* parentObjectWrap = Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
		this->instance = new NGraphicsOpacityEffect(parentObjectWrap->getInternalInstance());
	} else if (info.Length() == 0) {
		this->instance = new NGraphicsOpacityEffect();
	} else {
		Napi::TypeError::New(env, "Wrong number of arguments")
			.ThrowAsJavaScriptException();
	}
	
	this->rawData = extrautils::configureQObject(this->getInternalInstance());
}