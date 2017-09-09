#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORY_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORY_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class Category : public Abstract {
                public:
                    Category(Dataset *dataset) :
                            Abstract(dataset) {

                    }

                    void applyToColumn(int columnIndex);
                };

            }

        }
    }

}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_CATEGORY_H
