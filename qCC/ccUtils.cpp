#include "ccConsole.h"

#include "ccUtils.h"


namespace ccUtils
{
	void    DisplayLockedVerticesWarning(const QString &meshName, bool displayAsError)
	{
		QString message = QString("Vertices of mesh '%1' are locked (they may be shared by multiple entities for instance).\nYou should call this method directly on the vertices cloud.\n(warning: all entities depending on this cloud will be impacted!)").arg(meshName);
		
		if (displayAsError)
			ccConsole::Error(message);
		else
			ccConsole::Warning(message);
	}
}
