#ifndef SYNTHQT_SYNTHCLASS_H
#define SYNTHQT_SYNTHCLASS_H

#include "libsInclude.h"

class synthClass : public QWidget
{
    Q_OBJECT
public:
    synthClass();
    ~synthClass();
protected:
    fluid_settings_t* _settings;
    fluid_synth_t* _synth;
    fluid_audio_driver_t* _adriver;
private:
    QPushButton *button;
    QLineEdit *line;
public slots:
    const void start();

};


#endif //SYNTHQT_SYNTHCLASS_H
