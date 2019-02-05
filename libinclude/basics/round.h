//Round a number.

#ifndef FLOAT_H
#define FLOAT_H

static inline int Round(float f_) {
	float f = f_ + 0.5;
	return (int)f;
}

#endif