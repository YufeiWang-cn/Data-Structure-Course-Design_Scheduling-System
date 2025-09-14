/********************************************************************************
** Form generated from reading UI file 'SchedulingSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULINGSYSTEM_H
#define UI_SCHEDULINGSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SchedulingSystemClass
{
public:
    QAction *newProject;
    QAction *newFile;
    QAction *openProject;
    QAction *openFile;
    QAction *cleanProject;
    QAction *cleanFile;
    QAction *closeProject;
    QAction *closeAll;
    QAction *saveProject;
    QAction *saveAll;
    QAction *exit;
    QAction *login;
    QAction *personalInfo;
    QAction *credit;
    QAction *color;
    QAction *typeface;
    QAction *enroll;
    QAction *help;
    QAction *about;
    QAction *tutorial;
    QAction *add;
    QAction *exist;
    QAction *timetable;
    QAction *todo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *host;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *File;
    QMenu *currentProject;
    QMenu *currentFile;
    QMenu *Account;
    QMenu *Setup;
    QMenu *Help;
    QMenu *View;

    void setupUi(QMainWindow *SchedulingSystemClass)
    {
        if (SchedulingSystemClass->objectName().isEmpty())
            SchedulingSystemClass->setObjectName(QString::fromUtf8("SchedulingSystemClass"));
        SchedulingSystemClass->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SchedulingSystemClass->sizePolicy().hasHeightForWidth());
        SchedulingSystemClass->setSizePolicy(sizePolicy);
        newProject = new QAction(SchedulingSystemClass);
        newProject->setObjectName(QString::fromUtf8("newProject"));
        newProject->setAutoRepeat(true);
        newFile = new QAction(SchedulingSystemClass);
        newFile->setObjectName(QString::fromUtf8("newFile"));
        openProject = new QAction(SchedulingSystemClass);
        openProject->setObjectName(QString::fromUtf8("openProject"));
        openFile = new QAction(SchedulingSystemClass);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        cleanProject = new QAction(SchedulingSystemClass);
        cleanProject->setObjectName(QString::fromUtf8("cleanProject"));
        cleanFile = new QAction(SchedulingSystemClass);
        cleanFile->setObjectName(QString::fromUtf8("cleanFile"));
        closeProject = new QAction(SchedulingSystemClass);
        closeProject->setObjectName(QString::fromUtf8("closeProject"));
        closeAll = new QAction(SchedulingSystemClass);
        closeAll->setObjectName(QString::fromUtf8("closeAll"));
        saveProject = new QAction(SchedulingSystemClass);
        saveProject->setObjectName(QString::fromUtf8("saveProject"));
        saveAll = new QAction(SchedulingSystemClass);
        saveAll->setObjectName(QString::fromUtf8("saveAll"));
        exit = new QAction(SchedulingSystemClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        login = new QAction(SchedulingSystemClass);
        login->setObjectName(QString::fromUtf8("login"));
        personalInfo = new QAction(SchedulingSystemClass);
        personalInfo->setObjectName(QString::fromUtf8("personalInfo"));
        credit = new QAction(SchedulingSystemClass);
        credit->setObjectName(QString::fromUtf8("credit"));
        color = new QAction(SchedulingSystemClass);
        color->setObjectName(QString::fromUtf8("color"));
        typeface = new QAction(SchedulingSystemClass);
        typeface->setObjectName(QString::fromUtf8("typeface"));
        enroll = new QAction(SchedulingSystemClass);
        enroll->setObjectName(QString::fromUtf8("enroll"));
        help = new QAction(SchedulingSystemClass);
        help->setObjectName(QString::fromUtf8("help"));
        about = new QAction(SchedulingSystemClass);
        about->setObjectName(QString::fromUtf8("about"));
        tutorial = new QAction(SchedulingSystemClass);
        tutorial->setObjectName(QString::fromUtf8("tutorial"));
        tutorial->setCheckable(false);
        add = new QAction(SchedulingSystemClass);
        add->setObjectName(QString::fromUtf8("add"));
        exist = new QAction(SchedulingSystemClass);
        exist->setObjectName(QString::fromUtf8("exist"));
        timetable = new QAction(SchedulingSystemClass);
        timetable->setObjectName(QString::fromUtf8("timetable"));
        todo = new QAction(SchedulingSystemClass);
        todo->setObjectName(QString::fromUtf8("todo"));
        centralWidget = new QWidget(SchedulingSystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        host = new QWidget();
        host->setObjectName(QString::fromUtf8("host"));
        tabWidget->addTab(host, QString());

        verticalLayout->addWidget(tabWidget);

        SchedulingSystemClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SchedulingSystemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SchedulingSystemClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(SchedulingSystemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        File = new QMenu(menuBar);
        File->setObjectName(QString::fromUtf8("File"));
        File->setGeometry(QRect(345, 101, 147, 311));
        File->setCursor(QCursor(Qt::PointingHandCursor));
        currentProject = new QMenu(File);
        currentProject->setObjectName(QString::fromUtf8("currentProject"));
        currentFile = new QMenu(File);
        currentFile->setObjectName(QString::fromUtf8("currentFile"));
        Account = new QMenu(menuBar);
        Account->setObjectName(QString::fromUtf8("Account"));
        Account->setGeometry(QRect(367, 101, 120, 115));
        Account->setCursor(QCursor(Qt::PointingHandCursor));
        Setup = new QMenu(menuBar);
        Setup->setObjectName(QString::fromUtf8("Setup"));
        Setup->setCursor(QCursor(Qt::PointingHandCursor));
        Help = new QMenu(menuBar);
        Help->setObjectName(QString::fromUtf8("Help"));
        Help->setCursor(QCursor(Qt::WhatsThisCursor));
        View = new QMenu(menuBar);
        View->setObjectName(QString::fromUtf8("View"));
        View->setCursor(QCursor(Qt::PointingHandCursor));
        SchedulingSystemClass->setMenuBar(menuBar);

        menuBar->addAction(File->menuAction());
        menuBar->addAction(View->menuAction());
        menuBar->addAction(Setup->menuAction());
        menuBar->addAction(Account->menuAction());
        menuBar->addAction(Help->menuAction());
        File->addSeparator();
        File->addAction(newProject);
        File->addAction(newFile);
        File->addSeparator();
        File->addAction(openProject);
        File->addAction(openFile);
        File->addSeparator();
        File->addAction(currentProject->menuAction());
        File->addAction(currentFile->menuAction());
        File->addSeparator();
        File->addAction(closeProject);
        File->addAction(closeAll);
        File->addSeparator();
        File->addAction(saveProject);
        File->addAction(saveAll);
        File->addSeparator();
        File->addAction(exit);
        currentProject->addSeparator();
        currentProject->addAction(cleanProject);
        currentFile->addSeparator();
        currentFile->addAction(cleanFile);
        Account->addAction(enroll);
        Account->addAction(login);
        Account->addAction(personalInfo);
        Setup->addAction(credit);
        Setup->addAction(color);
        Setup->addAction(typeface);
        Help->addAction(help);
        Help->addAction(tutorial);
        Help->addAction(about);
        Help->addAction(todo);
        View->addAction(add);
        View->addAction(exist);
        View->addAction(timetable);

        retranslateUi(SchedulingSystemClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SchedulingSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *SchedulingSystemClass)
    {
        SchedulingSystemClass->setWindowTitle(QCoreApplication::translate("SchedulingSystemClass", "SchedulingSystem", nullptr));
        newProject->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        newFile->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
        openProject->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\211\223\345\274\200\351\241\271\347\233\256", nullptr));
        openFile->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        cleanProject->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\270\205\351\231\244", nullptr));
        cleanFile->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\270\205\351\231\244", nullptr));
        closeProject->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\205\263\351\227\255\345\275\223\345\211\215\351\241\271\347\233\256", nullptr));
        closeAll->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\205\263\351\227\255\346\211\200\346\234\211\351\241\271\347\233\256", nullptr));
        saveProject->setText(QCoreApplication::translate("SchedulingSystemClass", "\344\277\235\345\255\230\345\275\223\345\211\215\351\241\271\347\233\256", nullptr));
        saveAll->setText(QCoreApplication::translate("SchedulingSystemClass", "\344\277\235\345\255\230\346\211\200\346\234\211\351\241\271\347\233\256", nullptr));
        exit->setText(QCoreApplication::translate("SchedulingSystemClass", "\351\200\200\345\207\272", nullptr));
        login->setText(QCoreApplication::translate("SchedulingSystemClass", "\347\231\273\345\275\225", nullptr));
        personalInfo->setText(QCoreApplication::translate("SchedulingSystemClass", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        credit->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\255\246\345\210\206", nullptr));
        color->setText(QCoreApplication::translate("SchedulingSystemClass", "\351\242\234\350\211\262", nullptr));
        typeface->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\255\227\344\275\223", nullptr));
        enroll->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\263\250\345\206\214", nullptr));
        help->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\270\256\345\212\251\346\226\207\346\241\243", nullptr));
        about->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(whatsthis)
        about->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        tutorial->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\225\231\347\250\213", nullptr));
        add->setText(QCoreApplication::translate("SchedulingSystemClass", "\346\267\273\345\212\240", nullptr));
        exist->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\267\262\346\234\211\350\257\276\347\250\213", nullptr));
        timetable->setText(QCoreApplication::translate("SchedulingSystemClass", "\350\257\276\347\250\213\350\241\250", nullptr));
        todo->setText(QCoreApplication::translate("SchedulingSystemClass", "\345\276\205\344\274\230\345\214\226", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(host), QCoreApplication::translate("SchedulingSystemClass", "\344\270\273\351\241\265", nullptr));
        File->setTitle(QCoreApplication::translate("SchedulingSystemClass", "\346\226\207\344\273\266", nullptr));
        currentProject->setTitle(QCoreApplication::translate("SchedulingSystemClass", "\346\234\200\350\277\221\344\275\277\347\224\250\347\232\204\351\241\271\347\233\256", nullptr));
        currentFile->setTitle(QCoreApplication::translate("SchedulingSystemClass", "\346\234\200\350\277\221\350\256\277\351\227\256\347\232\204\346\226\207\344\273\266", nullptr));
        Account->setTitle(QCoreApplication::translate("SchedulingSystemClass", "\350\264\246\345\217\267", nullptr));
        Setup->setTitle(QCoreApplication::translate("SchedulingSystemClass", "\350\256\276\347\275\256", nullptr));
        Help->setTitle(QCoreApplication::translate("SchedulingSystemClass", "\345\270\256\345\212\251", nullptr));
        View->setTitle(QCoreApplication::translate("SchedulingSystemClass", "\350\257\276\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SchedulingSystemClass: public Ui_SchedulingSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULINGSYSTEM_H
