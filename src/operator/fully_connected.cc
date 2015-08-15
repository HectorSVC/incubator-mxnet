/*!
 * Copyright (c) 2015 by Contributors
 * \file fully_connected.cc
 * \brief fully connect operator
*/
#include <mxnet/registry.h>
#include "./fully_connected-inl.h"
namespace mxnet {
namespace op {
template<>
Operator* CreateFullyConnectedOp<cpu>(Param param) {
  return new FullyConnectedOp<cpu>(param);
}

// DO_BIND_DISPATCH comes from static_operator_common.h
Operator* FullyConnectedProp::CreateOperator(Context ctx) const {
  DO_BIND_DISPATCH(CreateFullyConnectedOp, param_);
}

REGISTER_OP_PROPERTY(FullyConnected, FullyConnectedProp);
}  // namespace op
}  // namespace mxnet
