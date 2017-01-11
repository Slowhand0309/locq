/*
 * Copyright 2017 Slowhand0309
 * All rights reserved.
 */
#include "ansi.h"
#include "session.h"

using namespace locq;

int main(int argc, char *argv[]) {

  Session *session = new Session();
  session->write("hogehogeaaa!!!!");
  delete session;
  return 1;
}
