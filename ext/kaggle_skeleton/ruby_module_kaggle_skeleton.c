// ext/kaggle_skeleton/rub_module_kaggle_skeleton.c

#include "ruby_module_kaggle_skeleton.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

VALUE KaggleSkeleton = Qnil;

void init_module_kaggle_skeleton() {
  KaggleSkeleton = rb_define_module( "KaggleSkeleton" );
}
