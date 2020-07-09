#include "synthClass.h"

synthClass::synthClass() {
    _settings = new_fluid_settings();
    _synth = new_fluid_synth(_settings);
    _adriver = new_fluid_audio_driver(_settings, _synth);
    fluid_synth_sfload(_synth,"../sfdir/synth1.sf2",1);
    button = new QPushButton("PLAY");
    button->setShortcut(Qt::Key_Return);
    line = new QLineEdit;

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(line);
    layout1->addWidget(button);

    connect(button,SIGNAL(clicked()),this, SLOT(start()));
    setLayout(layout1);
}

synthClass::~synthClass() {
    delete_fluid_audio_driver(_adriver);
    delete_fluid_synth(_synth);
    delete_fluid_settings(_settings);
}

const void synthClass::start()
{
    int key = line->text().toInt();
    time_t deltaTime = time(nullptr);
    fluid_synth_noteon(_synth,0,key,100);

    while ((time(nullptr) - deltaTime) != 2);
    fluid_synth_noteoff(_synth,0,key);
}



