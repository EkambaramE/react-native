/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <fabric/core/ShadowNode.h>
#include <fabric/core/Props.h>

namespace facebook {
namespace react {

class ComponentDescriptor;

using SharedComponentDescriptor = std::shared_ptr<ComponentDescriptor>;

/*
 * Abstract class defining an interface of `ComponentDescriptor`.
 * `ComponentDescriptor` represents particular `ShadowNode` type and
 * defines (customizes) basic operations with particular kind of
 * `ShadowNode`s (such as creating, cloning, props and children managing).
 */
class ComponentDescriptor {
public:

  virtual ~ComponentDescriptor() = default;

  /*
   * Returns `componentHandle` associated with particular kind of components.
   * All `ShadowNode`s of this type must return same `componentHandle`.
   */
  virtual ComponentHandle getComponentHandle() const = 0;

  /*
   * Returns component's name.
   * React uses a `name` to refer to particular kind of components in
   * `create` requests.
   */
  virtual ComponentName getComponentName() const = 0;

  /*
   * Creates a new `ShadowNode` of a particular type.
   */
  virtual SharedShadowNode createShadowNode(
    const Tag &tag,
    const Tag &rootTag,
    const InstanceHandle &instanceHandle,
    const RawProps &rawProps
  ) const = 0;

  /*
   * Clones a `ShadowNode` with optionally new `props` and/or `children`.
   */
  virtual SharedShadowNode cloneShadowNode(
    const SharedShadowNode &shadowNode,
    const SharedRawProps &rawProps = nullptr,
    const SharedShadowNodeSharedList &children = nullptr
  ) const = 0;

  /*
   * Appends (by mutating) a given `childShadowNode` to `parentShadowNode`.
   */
  virtual void appendChild(
    const SharedShadowNode &parentShadowNode,
    const SharedShadowNode &childShadowNode
  ) const = 0;
};

} // namespace react
} // namespace facebook
