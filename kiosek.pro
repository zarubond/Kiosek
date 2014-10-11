# Add more folders to ship with the application, here
folder_01.source = qml/kiosek
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML2_IMPORT_PATH =%cd%\Qt_Libraries\qml

QT= quick multimedia

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    kiosek.cpp \
    intro.cpp \
    screen.cpp \
    view/view.cpp \
    view/loginview.cpp \
    head.cpp \
    view/mealtodayview.cpp \
    view/mapview.cpp \
    view/homeview.cpp \
    view/infoview.cpp \
    view/mymealview.cpp \
    view/setupview.cpp \
    view/historyview.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    kiosek.h \
    intro.h \
    screen.h \
    view/view.h \
    view/loginview.h \
    head.h \
    view/mealtodayview.h \
    view/mapview.h \
    view/homeview.h \
    view/infoview.h \
    view/mymealview.h \
    view/setupview.h \
    view/historyview.h

OTHER_FILES += \
    qml/kiosek/LeftMenu.qml \
    android/version.xml \
    android/AndroidManifest.xml \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/qtproject/qt5/android/bindings/QtApplication.java \
    android/src/org/qtproject/qt5/android/bindings/QtActivity.java \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-es/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-ro/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values/libs.xml \
    android/res/values/strings.xml
