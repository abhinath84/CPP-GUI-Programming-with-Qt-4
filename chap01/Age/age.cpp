/*
 * This project demonstrate the use of Laying Out Widgets.
 * We will create 3 widgets and play with them to get age.
 * The application consists of three widgets:
 * QWidget, QSpinBox, QSlider
 *
 * We change value of spinbox using slider and vise-versa.
*/

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);



    QSlider *slider = new QSlider(Qt::Horizontal);
    QSpinBox *spinbox = new QSpinBox();

    QObject::connect(spinbox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinbox, SLOT(setValue(int)));

    slider->setRange(0, 150);
    spinbox->setRange(0, 150);
    spinbox->setValue(33);

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(slider);
    hlayout->addWidget(spinbox);

    QWidget *window = new QWidget();
    window->setWindowTitle("Enter your Age!");
    window->resize(300, 50);
    window->setLayout(hlayout);

    window->show();

    return app.exec();
}
