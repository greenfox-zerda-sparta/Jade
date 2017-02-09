#include "HeaderLayoutCreator.h"



HeaderLayoutCreator::HeaderLayoutCreator() {
  headerLayout = new QGridLayout();
  signOutButton = new QPushButton;
  loadMoreButton = new QPushButton;
}


HeaderLayoutCreator::~HeaderLayoutCreator() {

  delete signOutButton;
  delete loadMoreButton;
  delete headerLayout;
}

QGridLayout* HeaderLayoutCreator::createHeaderLayout() {
  signOutButton->setText("Sign out");
  loadMoreButton->setText("Load more");
  headerLayout->addWidget(signOutButton, 0, 0, 1, 1, Qt::AlignLeft);
  headerLayout->addWidget(loadMoreButton, 0, 1, 1, 1, Qt::AlignLeft);
  connect(signOutButton, &QAbstractButton::clicked, this, &HeaderLayoutCreator::signOut);
  connect(loadMoreButton, &QAbstractButton::clicked, this, &HeaderLayoutCreator::loadMore);
  return headerLayout;
}

void HeaderLayoutCreator::signOut() {

}

void HeaderLayoutCreator::loadMore() {

}