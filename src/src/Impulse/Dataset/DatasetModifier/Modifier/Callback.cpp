#include "../../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                void Callback::applyToColumn(int columnIndex) {
                    DatasetData *samples = this->dataset->getSamples();
                    for (T_Size i = 0; i < samples->size(); i++) {
                        DatasetSample *sample = &samples->at(i);
                        sample->setColumn(columnIndex, this->callback);
                    }
                }

                void Callback::setCallback(std::function<T_String(T_String)> cb) {
                    this->callback = cb;
                }

            }

        }
    }

}
