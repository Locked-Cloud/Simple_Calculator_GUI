#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(
        QWidget *parent = nullptr
               );

private slots:
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();

private:
    QLineEdit *display;
    QString currentOperator;
    double leftOperand;
    bool operatorPressed;

    void createLayout();
    QPushButton* createButton(const QString &text, const char *member);
};

#endif // CALCULATOR_H
