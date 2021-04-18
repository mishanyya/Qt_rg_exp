#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QRegExp" //для работы с регулярными выражениями


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //editingFinished() - срабатывает при нажатии кнопки Enter или Return
    connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(inputTextInField())); //для ввода символов и проверки его содержимого через регулярные выражения


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::inputTextInField() //для ввода символов и проверки его содержимого через регулярные выражения
{
//чтобы не было лишних знаков сделать

QString str= ui->lineEdit->text(); // получаем значение QLineEdit

//Рабочие варианты:                     //ищет:
//QRegExp rx("\\s");                    //знак пробела
//QRegExp rx("\\d*\\.\\d+");            //десятичное число с точкой
//QRegExp rx("\\@\\.[0-9]");            //набор знаков @. и одной из цифр, например @.6
//QRegExp rx("[\\@\\.0-9]");            //любой знак @ или . или цифру от 0 до 9, например @
//QRegExp rx("[a-zA-Z]");               //любой символ от a до Z любого регистра, например h или H
//QRegExp rx("[^a-z]");                 //любой символ кроме от a до z, например 4
//QRegExp rx("[^\\@\\_\\-\\.a-zA-Z0-9]"); //любой символ кроме @ _ – . или букв и цифр - от a до z, A-Z, 0-9, например <
//QRegExp rx("[^a-z+]");                    //любой символ кроме от a до z, например 5
//QRegExp rx("[^(a-z0-9)+]");                 //любой символ кроме от a до z или от 0 до 9 и знака +, например =
//QRegExp rx("[^(a-zA-Z0-9)+\\@]");            //любой символ кроме от a до z или от A до Z или от 0 до 9 и кроме @ и знака +, например /
//QRegExp rx("^([a-zA-Z0-9\\-\\_\\.]+\\@[a-z]+\\.[a-z]+)");  //e-mail
QRegExp rx("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}"); //IP адрес



rx.indexIn(str);   // возвращает номер первого символа от группы значений найденного совпадения, начиная с 0
//если нет совпадений показывает -1
QString s = QString::number(rx.indexIn(str));
ui->label->setText(s);


/*
 * //rx.pos(0);  // возвращает номер первого символа найденного совпадения
QRegExp rx("\\s");//значение, которое ищет регулярное выражение в строке - знак пробела

//QStringList list;//массив с символами
QList<QString> list;//массив с символами
int pos = 0;
//разбить строку на элементы и поместить в массив
while ((pos = rx.indexIn(str, pos)) != -1) {
    list << rx.cap(1);
    pos += rx.matchedLength();
}
// list: ["12", "14", "99", "231", "7"]
*/

 /*
 QList<int>  allValues;//массив всех значений типа int
  for (int q=1;q<91;q++ ) {
      allValues << q;
  }
    QStringList values;
    QString entireValue;
*/

QString a,b;
a="НЕ подходит!";
b="Подходит!";
//ui->label->setText(a);
//ui->label->setText(b);
}

