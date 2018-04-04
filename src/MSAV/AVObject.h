#ifndef MSAV_AVOBJECT_H
#define MSAV_AVOBJECT_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "signals2/signal.hpp"
#include "signals2/signal_type.hpp"

#include "MSAVGlobal.h"
#include "DPTR.h"

namespace MSAV {

using namespace boost::signals2;

class AVObjectPrivate;
class AVObject
{
    DPTR_DECLARE_PRIVATE(AVObject);
public:
    AVObject();
    virtual ~AVObject();

protected:
    String className() const;
    void setClassName(const String &name);

private:
};
}
#endif //MSAV_AVOBJECT_H
