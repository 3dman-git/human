#ifndef CC_CROP_TOOL_HEADER
#define CC_CROP_TOOL_HEADER

//qCC_db
#include <ccBBox.h>

class ccHObject;
class ccGLMatrix;

//! Cropping tool
/** Handles clouds and meshes for now
**/
class ccCropTool
{
public:
	//! Crops the input entity
	/** \param entity entity to be cropped (should be a cloud or a mesh)
		\param box cropping box
		\param inside whether to keep the points/triangles inside or outside the input box
		\param meshRotation optional rotation (for meshes only)
		\return cropped entity (if any)
	**/
	static ccHObject* Crop(ccHObject* entity, const ccBBox& box, bool inside = true, const ccGLMatrix* meshRotation = 0);

};

#endif //CC_CROP_TOOL_HEADER
