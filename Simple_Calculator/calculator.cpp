#include "Calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent), leftOperand(0), operatorPressed(false) {
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    createLayout();
}

void Calculator::createLayout() {
    QGridLayout *layout = new QGridLayout(this);

    // Add the display at the top
    layout->addWidget(display, 0, 0, 1, 4);

    // Create number buttons (0-9)
    QStringList digitButtons = {"7", "8", "9", "4", "5", "6", "1", "2", "3", "0"};
    int pos = 0;
    for (const QString &digit : digitButtons) {
        QPushButton *button = createButton(digit, SLOT(digitClicked()));
        layout->addWidget(button, 1 + pos / 3, pos % 3);
        pos++;
    }

    // Operator buttons
    QStringList operators = {"/", "*", "-", "+"};
    for (int i = 0; i < operators.size(); ++i) {
        QPushButton *button = createButton(operators[i], SLOT(operatorClicked()));
        layout->addWidget(button, i + 1, 3);
    }

    // Create equal, clear buttons
    QPushButton *equalButton = createButton("=", SLOT(equalClicked()));
    QPushButton *clearButton = createButton("C", SLOT(clearClicked()));

    layout->addWidget(equalButton, 4, 1);
    layout->addWidget(clearButton, 4, 2);

    setLayout(layout);
}

QPushButton* Calculator::createButton(const QString &text, const char *member) {
    QPushButton *button = new QPushButton(text, this);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculator::digitClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString digitValue = button->text();

    if (operatorPressed) {
        display->clear();
        operatorPressed = false;
    }

    display->setText(display->text() + digitValue);
}

void Calculator::operatorClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    currentOperator = button->text();
    leftOperand = display->text().toDouble();
    operatorPressed = true;
}

void Calculator::equalClicked() {
    double rightOperand = display->text().toDouble();
    double result = 0;

    if (currentOperator == "+")
        result = leftOperand + rightOperand;
    else if (currentOperator == "-")
        result = leftOperand - rightOperand;
    else if (currentOperator == "*")
        result = leftOperand * rightOperand;
    else if (currentOperator == "/") {
        if (rightOperand != 0)
            result = leftOperand / rightOperand;
        else
            display->setText("Error");
    }

    display->setText(QString::number(result));
}

void Calculator::clearClicked() {
    display->clear();
    leftOperand = 0;
    currentOperator = "";
    operatorPressed = false;
}
