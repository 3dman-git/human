#ifndef CC_REGISTRATION_TOOLS_HEADER
#define CC_REGISTRATION_TOOLS_HEADER

//CCLib
#include <RegistrationTools.h>

//qCC_db
#include <ccGLMatrix.h>

class QWidget;
class QStringList;
class ccHObject;

//! Registration tools wrapper
class ccRegistrationTools
{

public:

	//! Applies ICP registration on two entities
	/** \warning Automatically samples points on meshes if necessary (see code for magic numbers ;)
	**/
	static bool ICP(ccHObject* data,
					ccHObject* model,
					ccGLMatrix& transMat,
					double& finalScale,
					double& finalRMS,
					unsigned& finalPointCount,
					double minRMSDecrease,
					unsigned maxIterationCount,
					unsigned randomSamplingLimit,
					bool removeFarthestPoints,
					CCLib::ICPRegistrationTools::CONVERGENCE_TYPE method,
					bool adjustScale,
					double finalOverlapRatio = 1.0,
					bool useDataSFAsWeights = false,
					bool useModelSFAsWeights = false,
					int transformationFilters = CCLib::ICPRegistrationTools::SKIP_NONE,
					int maxThreadCount = 0,
					QWidget* parent = nullptr);

};

#endif //CC_REGISTRATION_TOOLS_HEADER
