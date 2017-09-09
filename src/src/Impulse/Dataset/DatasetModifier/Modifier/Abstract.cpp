#include "../../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                Abstract::Abstract(Dataset *_dataset) :
                        dataset(_dataset) {

                }

                void Abstract::apply() {
                    DatasetData *samples = this->dataset->getSamples();
                    if (samples->size() > 0) {
                        for (T_Size i = 0; i < samples->at(0).getSize(); i++) {
                            this->applyToColumn(i);
                        }
                    }
                }
            }
        }
    }
}
