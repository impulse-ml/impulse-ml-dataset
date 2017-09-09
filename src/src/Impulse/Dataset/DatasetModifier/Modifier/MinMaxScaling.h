#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_MINMAXSCALING_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_MINMAXSCALING_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class MinMaxScaling : public Abstract {
                public:
                    MinMaxScaling(Dataset *dataset) :
                            Abstract(dataset) {

                    }

                    void applyToColumn(int columnIndex);
                };

            }

        }
    }

}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_MINMAXSCALING_H
