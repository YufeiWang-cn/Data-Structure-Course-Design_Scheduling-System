/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_11;
    QLabel *credit;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *remove;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_2;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_6;
    QSlider *horizontalSlider;
    QLabel *semester;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_10;
    QComboBox *comboBox;
    QPushButton *add;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Credit)
    {
        if (Credit->objectName().isEmpty())
            Credit->setObjectName(QString::fromUtf8("Credit"));
        Credit->resize(600, 450);
        gridLayout = new QGridLayout(Credit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 9, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 3, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_11, 5, 3, 1, 1);

        credit = new QLabel(Credit);
        credit->setObjectName(QString::fromUtf8("credit"));

        gridLayout->addWidget(credit, 4, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 8, 3, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 6, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 9, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 8, 6, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 6, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        remove = new QPushButton(Credit);
        remove->setObjectName(QString::fromUtf8("remove"));

        gridLayout->addWidget(remove, 2, 8, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 7, 5, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(Credit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_2, 7, 6, 1, 2);

        doubleSpinBox = new QDoubleSpinBox(Credit);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 4, 3, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 9, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 10, 1, 1);

        horizontalSlider = new QSlider(Credit);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 4, 6, 1, 3);

        semester = new QLabel(Credit);
        semester->setObjectName(QString::fromUtf8("semester"));

        gridLayout->addWidget(semester, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 7, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_10, 5, 6, 1, 1);

        comboBox = new QComboBox(Credit);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 3, 1, 1);

        add = new QPushButton(Credit);
        add->setObjectName(QString::fromUtf8("add"));

        gridLayout->addWidget(add, 2, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 7, 4, 1, 1);

        pushButton = new QPushButton(Credit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 7, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 3, 1, 1);


        retranslateUi(Credit);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(Credit);
    } // setupUi

    void retranslateUi(QWidget *Credit)
    {
        Credit->setWindowTitle(QCoreApplication::translate("Credit", "Form", nullptr));
        credit->setText(QCoreApplication::translate("Credit", "\345\255\246\345\210\206(0~100)", nullptr));
        remove->setText(QCoreApplication::translate("Credit", "\347\247\273\351\231\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Credit", "\351\207\215\347\275\256", nullptr));
        semester->setText(QCoreApplication::translate("Credit", "\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Credit", "\347\254\2541\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Credit", "\347\254\2542\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Credit", "\347\254\2543\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Credit", "\347\254\2544\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Credit", "\347\254\2545\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Credit", "\347\254\2546\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Credit", "\347\254\2547\345\255\246\346\234\237", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Credit", "\347\254\2548\345\255\246\346\234\237", nullptr));

        add->setText(QCoreApplication::translate("Credit", "\346\267\273\345\212\240", nullptr));
        pushButton->setText(QCoreApplication::translate("Credit", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credit: public Ui_Credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
