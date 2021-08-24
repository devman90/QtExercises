#include "CCore.h"
#include "CActionDefault.h"
#include "CActionRect.h"
#include "CActionEllipse.h"

class CCorePrivate
{
public:
    CCorePrivate(CCore* q)
        : q_ptr(q)
    {}

    CCore* q_ptr;
    CActionDefaultFactory m_actionSelectSingleFactory;
    CActionRectFactory m_actionRectFactory;
    CActionEllipseFactory m_actionEllipseFactory;
};

CCore::CCore()
    : d_ptr(new CCorePrivate(this))
{

}

CCore::~CCore()
{
    delete d_ptr;
}
