#include "../../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetModifier {

            namespace Modifier {

                void Category::applyToColumn(int columnIndex) {
                    DatasetData *samples = this->dataset->getSamples();
                    T_StringVector categories;
                    T_Size i;

                    for (i = 0; i < samples->size(); i++) {
                        DatasetSample *sample = &samples->at(i);
                        T_String category = sample->getColumnToString(columnIndex);
                        if (std::find(categories.begin(), categories.end(), category)
                            == categories.end()) {
                            categories.push_back(category);
                        }
                    }

                    for (i = 0; i < samples->size(); i++) {
                        DatasetSample *sample = &samples->at(i);
                        T_String existingCategory = sample->getColumnToString(columnIndex);
                        for (T_Size j = 0; j < categories.size(); j++) {
                            if (categories.at(j) == existingCategory) {
                                sample->insertColumnAfter(columnIndex + j, "1");
                            } else {
                                sample->insertColumnAfter(columnIndex + j, "0");
                            }
                        }
                        sample->removeColumnAt(columnIndex);
                    }
                }

            }

        }
    }

}
