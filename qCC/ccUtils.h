#ifndef CCUTILS_H
#define CCUTILS_H

class QString;

namespace ccUtils
{
	//! Display a warning or error for locked verts
	void    DisplayLockedVerticesWarning(const QString &meshName, bool displayAsError);
}

#endif //CCUTILS_H
