#include "WindowManager.h"
#include "UserLoginWindow.h"
#include "UserSignUpWindow.h"
#include <QVBoxLayout>
#include <QDebug>

WindowManager::WindowManager() {
  firstPageWidget = new UserLoginWindow;
  secondPageWidget = new UserSignUpWindow;

  QWidget* centralWidget = new QWidget();

  stackedWidget = new QStackedWidget;
  stackedWidget->addWidget(firstPageWidget);
  stackedWidget->addWidget(secondPageWidget);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(stackedWidget);

  setCentralWidget(centralWidget);
  centralWidget->setLayout(layout);
  connect(firstPageWidget, SIGNAL(sendRequest()), this, SLOT(changePage()));
  connect(secondPageWidget, SIGNAL(sendRequest()), this, SLOT(changePage()));
}

void WindowManager::changePage() {
  if (stackedWidget->currentIndex() == 0) {
    stackedWidget->setCurrentIndex(1);
  } else if (stackedWidget->currentIndex() == 1) {
    stackedWidget->setCurrentIndex(0);
  }
}

WindowManager::~WindowManager() {}
