#-------------------------------------------------
#
# Project created by QtCreator 2017-06-18T13:58:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Carcass_visualizer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    camera/camera.cpp \
    draw/qt_draw.cpp \
    edge/edge.cpp \
    facade/facade.cpp \
    holder/holder.cpp \
    load/file_load.cpp \
    load/load_strategy.cpp \
    managers/draw_manager.cpp \
    managers/load_manager.cpp \
    managers/main_manager.cpp \
    managers/transform_manager.cpp \
    matrix/transformmatrix.cpp \
    model/model.cpp \
    objects/composite_object.cpp \
    objects/invis_obj.cpp \
    objects/vis_object.cpp \
    point/point.cpp \
    scene/scene.cpp \
    scene/scene_object.cpp \
    scene/object_mediator.cpp \
    math_vector/math_vector.cpp

HEADERS  += mainwindow.h \
    camera/base_camera.h \
    camera/camera.h \
    commands/base_command.h \
    commands/commands.h \
    draw/draw_strategy.h \
    draw/qt_draw.h \
    edge/edge.h \
    facade/facade.h \
    holder/holder.h \
    load/file_load.h \
    load/load_strategy.h \
    managers/base_manager.h \
    managers/draw_manager.h \
    managers/load_manager.h \
    managers/main_manager.h \
    managers/transform_manager.h \
    matrix/base_matrix.h \
    matrix/base_matrix.hpp \
    matrix/matrix.h \
    matrix/matrix.hpp \
    matrix/transformmatrix.h \
    model/base_model.h \
    model/model.h \
    objects/base_object.h \
    objects/composite_object.h \
    objects/invis_obj.h \
    objects/vis_object.h \
    point/point.h \
    scene/scene.h \
    scene/scene_object.h \
    vector/base_vector.h \
    vector/base_vector.hpp \
    vector/iterator.h \
    vector/iterator.hpp \
    vector/vector.h \
    vector/vector.hpp \
    base_error.h \
    errors.h \
    scene/object_mediator.h \
    math_vector/math_vector.h

FORMS += \
    mainwindow.ui
