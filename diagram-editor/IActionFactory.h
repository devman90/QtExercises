#ifndef IACTIONFACTORY_H
#define IACTIONFACTORY_H

#include <QIcon>
#include <QString>
#include "IActionInterface.h"

class IActionFactory
{
public:
    static const QList<IActionFactory*> allActionFactories();

    IActionFactory();
    virtual ~IActionFactory();

    virtual QIcon getIcon() const;
    void setIcon(QIcon icon);
    virtual QString getName() const=0;
    virtual IActionInterface* create(IDiagramEditorScene *scene)=0;

protected:
    QIcon m_icon;
};

#endif // IACTIONFACTORY_H
