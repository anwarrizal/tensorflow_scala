/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "python_api.h"

#include "c_api_internal.h"

namespace tensorflow {

void UpdateEdge(TF_Graph* graph, TF_Output new_src, TF_Input dst, TF_Status* status) {
  mutex_lock l(graph->mu);
  status->status = graph->graph.UpdateEdge(&new_src.oper->node, new_src.index, &dst.oper->node, dst.index);
}

void AddControlInput(TF_Graph* graph, TF_Operation* op, TF_Operation* input) {
  mutex_lock l(graph->mu);
  graph->graph.AddControlEdge(&input->node, &op->node);
}

void ClearControlInputs(TF_Graph* graph, TF_Operation* op) {
  mutex_lock l(graph->mu);
  for (const auto* edge : op->node.in_edges()) {
    if (edge->IsControlEdge()) {
      graph->graph.RemoveControlEdge(edge);
    }
  }
}

void SetRequestedDevice(TF_Graph* graph, TF_Operation* op, const char* device) {
  mutex_lock l(graph->mu);
  op->node.set_requested_device(device);
}

}  // namespace tensorflow
