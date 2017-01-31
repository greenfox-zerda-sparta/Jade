#include "WindowManager.h"
#include "UserLoginWindow.h"
#include "UserSignUpWindow.h"
#include <QVBoxLayout>

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
}

void WindowManager::changePage() {
  stackedWidget->setCurrentIndex(1);
}

WindowManager::~WindowManager() {}