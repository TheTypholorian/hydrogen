#include "nanovg.h"

namespace H {
	static NVGcolor color(float r, float g, float b) {
		NVGcolor c;
		c.r = r / 255;
		c.g = g / 255;
		c.b = b / 255;
		c.a = 1;
		return c;
	}

	static NVGcolor gold1 = color(255, 247, 216);
	static NVGcolor gold2 = color(255, 232, 158);
	static NVGcolor gold3 = color(239, 217, 105);
	static NVGcolor gold4 = color(224, 195, 51);
	static NVGcolor gold5 = color(206, 175, 0);

	static NVGcolor black1 = color(76, 76, 76);
	static NVGcolor black2 = color(63, 63, 63);
	static NVGcolor black3 = color(51, 51, 51);
	static NVGcolor black4 = color(36, 36, 36);
	static NVGcolor black5 = color(25, 25, 25);
}