QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CActionEllipse.cpp \
    CActionManager.cpp \
    CActionRect.cpp \
    CActionSelectSingle.cpp \
    CCore.cpp \
    CDiagramEditorScene.cpp \
    CDiagramEditorView.cpp \
    CEventHandler.cpp \
    CGraphicsTestItem.cpp \
    CPreviewItem.cpp \
    IActionFactory.cpp \
    IActionInterface.cpp \
    IActionManager.cpp \
    IDiagramEditorScene.cpp \
    IPreviewActionInterface.cpp \
    main.cpp \
    CMainWindow.cpp

HEADERS += \
    CActionEllipse.h \
    CActionManager.h \
    CActionRect.h \
    CActionSelectSingle.h \
    CCore.h \
    CDiagramEditorScene.h \
    CDiagramEditorView.h \
    CEventHandler.h \
    CGraphicsTestItem.h \
    CMainWindow.h \
    CPreviewItem.h \
    IActionFactory.h \
    IActionInterface.h \
    IActionManager.h \
    IDiagramEditorScene.h \
    IPreviewActionInterface.h

FORMS += \
    CMainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
