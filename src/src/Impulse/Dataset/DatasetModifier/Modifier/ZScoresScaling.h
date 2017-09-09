#ifndef IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_ZSCORESSCALING_H
#define IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_ZSCORESSCALING_H

#include "../../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                class ZScoresScaling : public Abstract {
                public:
                    ZScoresScaling(Dataset *dataset) :
                            Abstract(dataset) {

                    }

                    virtual ~ZScoresScaling() {
                    }

                    void applyToColumn(int columnIndex);

                    T_DoubleVector applyToSample(std::initializer_list<double> list);
                };

            }
        }
    }
}

#endif//IMPULSE_DATASET_DATASETMODIFIER_MODIFIER_ZSCORESSCALING_H
