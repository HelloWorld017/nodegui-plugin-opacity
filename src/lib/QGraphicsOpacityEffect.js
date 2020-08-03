const addon = require('../../build/Release/nodegui_plugin_opacity.node');
const { QBrush } = require('@nodegui/nodegui');

class QGraphicsOpacityEffect extends QGraphicsEffect {
	constructor(arg) {
		let native;
		if(arg) {
			if(checkIfNativeElement(arg)) {
				native = arg;
			} else {
				native = new addon.QGraphicsOpacityEffect(arg.native);
			}
		} else {
			native = new addon.QGraphicsOpacityEffect();
		}

		super(native);
		this.native = native;
	}

	setOpacity(opacity) {
		this.setProperty('opacity', opacity);
	}

	opacity() {
		return this.property('opacity').toDouble();
	}

	setOpacityMask(brush) {
		this.setProperty('opacityMask', brush.native);
	}

	opacityMask() {
		return new QBrush(this.property('opacityMask'));
	}
}

module.exports = QGraphicsOpacityEffect;
