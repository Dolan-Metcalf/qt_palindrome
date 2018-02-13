#include "mainwindow.h"

QRegExp MainWindow::stringFormat("[A-Za-z]{1,1}[A-Za-z\\s]{0,9}");
QRegExp MainWindow::palindromeFormat("^([A-Za-z]?)([A-Za-z]?)([A-Za-z]?)([A-Za-z]?)([A-Za-z]?)([A-Za-z]?)([A-Za-z]?)([A-Za-z]?)([A-Za-z]?)[A-Za-z]?\\5\\4\\3\\2\\1$");
QRegExp MainWindow::filterCharacter("[\\s]");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    widget = new QWidget(this);
    setCentralWidget(widget);

    layout=new QGridLayout;
    instruction = new QLabel("Enter a string:");
    stringEntry=new QLineEdit;
    stringEntry->setMaxLength(20);
    resultString=new QLabel("Result:");
    result=new QLabel(" ");
    clear=new QPushButton("&Clear Fields");
    layout->addWidget(instruction, 0,0);
    layout->addWidget(stringEntry,0,1);
    layout->addWidget(resultString, 1,0);
    layout->addWidget(result,1,1);
    layout->addWidget(clear,2,1);
    widget->setLayout(layout);

    // ensure that only alphabetic characters are entered in the QLineEdit
    stringValid= new QRegExpValidator(stringFormat, this);
    stringEntry->setValidator(stringValid);

    connect(stringEntry, SIGNAL(textChanged(QString)), this, SLOT(checkPalindrome(QString)));
    connect(clear, SIGNAL(clicked()), this, SLOT(clearFields()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::checkPalindrome(QString str)
{
    // set up a standard string for checking
    str.remove(filterCharacter);
    str=str.toUpper();
    if (palindromeFormat.exactMatch(str))
        result->setText("This is a palindrome.");
    else
        result->setText("This is not a palindrome.");
}

void MainWindow::clearFields()
{
    stringEntry->clear();
    result->setText(" ");
    stringEntry->setFocus();
}
