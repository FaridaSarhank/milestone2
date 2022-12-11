#ifndef MENU_H
#define MENU_H
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QVector>
#include <QMediaPlayer>


namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();


private slots:
    void on_pushButton_clicked();

    void on_loginb_clicked();

    void on_registerb_clicked();

private:
    Ui::menu *ui;
    QString name ;
    QString password ;
    QVector <QString> usernames ;
    QVector <QString> passwords ;
    void readData  ();
    void inputData ();
    void check ();
    void addUser (QString u, QString p);
    bool logincheck;
    QFile login ;
    QMediaPlayer *music ;
    QAudioOutput *output;

};

#endif // MENU_H
