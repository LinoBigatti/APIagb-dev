//Set an affine matrix to the identity matrix.

#include <object/obj_aff_identity.h>

void obj_aff_identity(obj_affine *obj) {
	obj->pa = 1 << 8;
	obj->pd = 1 << 8;
	obj->pb = 0;
	obj->pc = 0;
}