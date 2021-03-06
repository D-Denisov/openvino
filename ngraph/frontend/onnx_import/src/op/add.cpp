// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "op/add.hpp"
#include "default_opset.hpp"
#include "ngraph/builder/autobroadcast.hpp"
#include "ngraph/shape.hpp"

namespace ngraph
{
    namespace onnx_import
    {
        namespace op
        {
            namespace set_1
            {
                OutputVector add(const Node& node)
                {
                    const Output<ngraph::Node> lhs_node = node.get_ng_inputs().at(0);
                    Output<ngraph::Node> rhs_node = node.get_ng_inputs().at(1);
                    const bool broadcast = node.get_attribute_value<std::int64_t>("broadcast", 0);
                    if (broadcast)
                    {
                        if (node.has_attribute("axis"))
                        {
                            // Unidirectional broadcast right node to left shape.
                            const auto axis = node.get_attribute_value<std::int64_t>("axis");
                            const auto axes_mapping = builder::opset1::get_axes_mapping_output(
                                lhs_node.get_partial_shape(), rhs_node.get_partial_shape(), axis);
                            rhs_node = std::make_shared<default_opset::Broadcast>(
                                rhs_node,
                                std::make_shared<default_opset::ShapeOf>(lhs_node),
                                axes_mapping);
                        }
                        else
                        {
                            rhs_node = std::make_shared<default_opset::Broadcast>(
                                rhs_node, std::make_shared<default_opset::ShapeOf>(lhs_node));
                        }
                        return {std::make_shared<default_opset::Add>(
                            lhs_node, rhs_node, ngraph::op::AutoBroadcastSpec::NONE)};
                    }
                    return {std::make_shared<default_opset::Add>(lhs_node, rhs_node)};
                }

            } // namespace set_1

            namespace set_7
            {
                OutputVector add(const Node& node)
                {
                    return {std::make_shared<default_opset::Add>(node.get_ng_inputs().at(0),
                                                                 node.get_ng_inputs().at(1))};
                }

            } // namespace set_7

        } // namespace op

    } // namespace onnx_import

} // namespace ngraph
