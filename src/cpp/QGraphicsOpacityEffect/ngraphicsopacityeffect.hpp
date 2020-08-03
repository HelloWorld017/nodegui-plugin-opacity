#pragma once

#include <QGraphicsOpacityEffect>

#include <nodegui/QtWidgets/QGraphicsEffect/qgraphicseffect_macro.h>
#include <nodegui/core/Events/eventwidget.h>
#include <nodegui/core/Events/eventwidget_macro.h>

class NGraphicsOpacityEffect : public QGraphicsOpacityEffect, public EventWidget {
	Q_OBJECT
	EVENTWIDGET_IMPLEMENTATIONS(QGraphicsOpacityEffect)

	public:
		using QGraphicsOpacityEffect::QGraphicsOpacityEffect;

	void connectSignalsToEventEmitter() {
		QGRAPHICSEFFECT_SIGNALS
	}
};