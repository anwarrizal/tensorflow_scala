/* Copyright 2017, Emmanouil Antonios Platanios. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

package org.platanios.tensorflow.api.learn.layers.rnn.cell

import org.platanios.tensorflow.api.learn.Mode
import org.platanios.tensorflow.api.learn.layers.{Layer, LayerInstance}

/**
  * @author Emmanouil Antonios Platanios
  */
abstract class RNNCell[O, OS, S, SS](override protected val name: String)
    extends Layer[Tuple[O, S], Tuple[O, S]](name) {
  def createCell(mode: Mode): CellInstance[O, OS, S, SS]

  override final def forward(input: Tuple[O, S], mode: Mode): LayerInstance[Tuple[O, S], Tuple[O, S]] = {
    val cellInstance = createCell(mode)
    val output = cellInstance.cell.forward(input)
    LayerInstance(input, output, cellInstance.trainableVariables, cellInstance.nonTrainableVariables)
  }
}
