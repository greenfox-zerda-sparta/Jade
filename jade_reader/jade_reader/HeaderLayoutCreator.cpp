#include "HeaderLayoutCreator.h"



HeaderLayoutCreator::HeaderLayoutCreator() {
}


HeaderLayoutCreator::~HeaderLayoutCreator() {
}

QGridLayout* HeaderLayoutCreator::createHeaderLayout() {
  headerLayout = new QGridLayout();
  signOutButton = new QPushButton;
  loadMoreButton = new QPushButton;
  signOutButton->setText("Sign out");
  loadMoreButton->setText("Load more");
  headerLayout->addWidget(signOutButton, 0, 0, 1, 1, Qt::AlignLeft);
  headerLayout->addWidget(loadMoreButton, 0, 1, 1, 1, Qt::AlignLeft);
  return headerLayout;
}