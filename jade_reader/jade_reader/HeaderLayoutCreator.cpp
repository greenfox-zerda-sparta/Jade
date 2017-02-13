#include "HeaderLayoutCreator.h"
#include "FeedService.h"

HeaderLayoutCreator::HeaderLayoutCreator() {
  headerLayout = new QGridLayout();
  signOutButton = new QPushButton;
  refreshButton = new QPushButton;
}

HeaderLayoutCreator::~HeaderLayoutCreator() {

  delete signOutButton;
  delete refreshButton;
  delete headerLayout;
}

QGridLayout* HeaderLayoutCreator::createHeaderLayout() {
  signOutButton->setText("Sign out");
  refreshButton->setText("Refresh");
  headerLayout->addWidget(signOutButton, 0, 0, 1, 1, Qt::AlignLeft);
  headerLayout->addWidget(refreshButton, 0, 1, 1, 1, Qt::AlignRight);
  connect(signOutButton, &QAbstractButton::clicked, this, &HeaderLayoutCreator::signOutSlot);
  connect(refreshButton, &QAbstractButton::clicked, this, &HeaderLayoutCreator::refreshSlot);
  return headerLayout;
}

void HeaderLayoutCreator::signOutSlot() {
  signOutSignal();
}

void HeaderLayoutCreator::refreshSlot() {
  refreshSignal();
}