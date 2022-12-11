#include "menu.h"
#include "qaudiooutput.h"
#include "ui_menu.h"
#include <QDebug>



menu::menu(QWidget *parent) :QDialog(parent),ui(new Ui::menu)
{
    ui->setupUi(this);
    logincheck = false;
   readData() ;


}

menu::~menu()
{
    delete ui;

}


void menu::on_pushButton_clicked()
{
    if (logincheck==true)
    {
     qDebug("entered start") ;
     this->close();
     music = new QMediaPlayer();
     music->setSource(QUrl::fromLocalFile("C:/Users/d/Downloads/minon_-_oh_hello.mp3"));
     output = new QAudioOutput();
     output->setVolume(10);
     music->setAudioOutput(output);
     music->play();
    }
    else
    {
      ui->login_show->setText("Please Log in :)");
    }

}

void menu:: readData ()
{
    QFile login ("C:/Users/d/OneDrive/Documents/minionGTA/login.txt");
   login.open(QIODevice::ReadWrite);
    QTextStream stream(&login);
    QString line;

        while (!stream.atEnd())
{
            line = stream.readLine();
            usernames.push_back(line);

           stream.readLineInto(&line);
           passwords.push_back(line);

}
        check();
        login.close();
}

void menu :: check()
{

for(int i=0; i<usernames.size(); i++)
//    for( int i =0; i<passwords.size(); i++)
{

    if((usernames[i].toLower()==name.toLower())&&(passwords[i]==password))
    {
        ui->login_show->setText("Logged in successfully, mabrouk ;)");
        logincheck= true ;
        break ;
        qDebug("logged") ;
    }
     if (passwords[i]!=password)
    {
         ui->login_show->setText("Invalid Password, give it another go");
         logincheck= false ;
    }
     if (usernames[i].toLower()!=name.toLower())
    {
        ui->login_show->setText("Incorrect Username");
        logincheck= false ;
    }
    if ((usernames[i].toLower()!=name.toLower())&&(passwords[i]!=password))
    {
        ui->login_show->setText("You have not yet registered , please register");
         qDebug(" not yet registered ") ;
         logincheck= false ;
    }
}

}


void menu::on_loginb_clicked()
{
    readData();
    name = ui->nle->text();
    password = ui->ple->text();
    check();


}

void menu::addUser(QString username, QString password)

{
    QFile login ("C:/Users/d/OneDrive/Documents/minionGTA/login.txt");
    login.open(QIODevice::Append|QIODevice::Text);
    QTextStream stream(&login);
    stream << username << "\n" << password << "\n";

    login.close();
}

void menu::on_registerb_clicked()
{
    name = ui->nle->text();
    password = ui->ple->text();
    bool usernameTaken = false;

     if(usernames.empty())
     {
        if(password.length() < 8)

             ui->login_show->setText("Password must be at least 8 characters");

else
{
ui->login_show->setText("Congrats on Registering , Enjoy");
usernames.push_back(name);
passwords.push_back(password);
addUser(name, password);
}
}
else
{
 for(int i=0; i<usernames.size(); i++){
  if(usernames[i].toLower()==name.toLower())
     usernameTaken = true;
 }

if(usernameTaken)

             ui->login_show->setText("Name is already registered, choose another name");

         else if(password.length() < 8)

             ui->login_show->setText("Password must be at least 8 characters");

         else{

             ui->login_show->setText("Congrats on Registering , Enjoy");

             usernames.push_back(name);

             passwords.push_back(password);

             addUser(name, password);

         }

     }

}

