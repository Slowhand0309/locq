/*
 * Copyright 2017 Slowhand0309
 * All rights reserved.
 */
#include "executor.h"
#include "option.h"

using namespace locq;

/**
 * Entry point.
 *
 * @method main
 * @param  argc
 * @param  argv
 * @return      [result code]
 */
int main(int argc, char *argv[]) {

  option_t options;
  Option::parse(options, argc, argv);

  Executor executor(options);
  executor.exec();

  return 1;
}
