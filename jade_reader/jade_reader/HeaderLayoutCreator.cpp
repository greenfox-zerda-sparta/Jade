#include "HeaderLayoutCreator.h"
#include "FeedService.h"
#include "Config.h"

HeaderLayoutCreator::HeaderLayoutCreator() :
  headerLayout(new QGridLayout()),
  signOutButton(new QPushButton),
  refreshButton(new QPushButton) {
  }

QSharedPointer<QGridLayout> HeaderLayoutCreator::createHeaderLayout() {
  signOutButton->setText("Sign out");
  refreshButton->setText("Refresh");
  headerLayout->addWidget(signOutButton.data(), 0, 0, 1, 1, Qt::AlignLeft);
  headerLayout->addWidget(refreshButton.data(), 0, 1, 1, 1, Qt::AlignRight);
  connect(signOutButton.data(), &QAbstractButton::clicked, this, &HeaderLayoutCreator::signOutSignal);
  connect(refreshButton.data(), &QAbstractButton::clicked, this, &HeaderLayoutCreator::refreshSignal);
  return headerLayout;
}