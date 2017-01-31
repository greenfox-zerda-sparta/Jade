#include "WindowManager.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include "UserLoginWindow.h"
#include "UserSignUpWindow.h"

WindowManager::WindowManager() {
  firstPageWidget = new UserLoginWindow;
  secondPageWidget = new UserSignUpWindow;
  thirdPageWidget = new QWidget();

  QWidget* centralWidget = new QWidget();

  QStackedWidget *stackedWidget = new QStackedWidget;
  stackedWidget->addWidget(firstPageWidget);
  stackedWidget->addWidget(secondPageWidget);

  QComboBox *pageComboBox = new QComboBox;
  pageComboBox->addItem(tr("Page 1"));
  pageComboBox->addItem(tr("Page 2"));

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(stackedWidget);
  layout->addWidget(pageComboBox);

  setCentralWidget(centralWidget);
  centralWidget->setLayout(layout);

  connect(pageComboBox, SIGNAL(activated(int)), stackedWidget, SLOT(setCurrentIndex(int)));
}

WindowManager::~WindowManager() {}
