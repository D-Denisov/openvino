# Copyright (C) 2018-2021 Intel Corporation
# SPDX-License-Identifier: Apache-2.0

from mo.graph.graph import Graph
from mo.ops.op import Op


class DequantizeLinear(Op):
    op = 'DequantizeLinear'
    enabled = False

    def __init__(self, graph: Graph, attrs: dict):
        mandatory_props = {
            'type': None,
            'op': self.op,
            'version': None,
            'infer': None,
            'out_ports_count': 1,
            'in_ports_count': 3,
        }
        super().__init__(graph, mandatory_props, attrs)

    def supported_attrs(self):
        return ['axis']
