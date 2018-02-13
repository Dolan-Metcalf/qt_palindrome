#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QRegExp>
#include <QGridLayout>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QLabel>
#include <QPushButton>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void checkPalindrome(QString str);
  void clearFields();

private:
  QWidget *widget;
  QRegExpValidator* stringValid;
  QGridLayout* layout;
  QLineEdit* stringEntry;
  QLabel* instruction;
  QLabel* result;
  QLabel* resultString;
  QPushButton* clear;
  QString inputString;

  static QRegExp stringFormat;
  static QRegExp palindromeFormat;
  static QRegExp filterCharacter;
};

#endif // MAINWINDOW_H
